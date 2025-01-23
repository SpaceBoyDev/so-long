# The name of the project
NAME = so_long

VAL = valgrind
VALFLAGS = --leak-check=full --show-leak-kinds=all

# Makefile flags
MAKEFLAGS += --no-print-directory
MAP = ./maps/map.ber
LIBFT = ./libft/
LIBFT_LIB = $(LIBFT)libft.a
LIBMLX	:= ./MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

VALID_MAPS = maps/map1.ber maps/map2.ber

INVALID_MAPS = maps/invalid/change_permissions.ber maps/invalid/empty.ber maps/invalid/no_collectibles.ber \
	maps/invalid/no_exit.ber maps/invalid/no_extension maps/invalid/no_path_bonus.ber \
	maps/invalid/no_path0.ber maps/invalid/no_path1.ber maps/invalid/no_starting_position.ber \
	maps/invalid/not_rectangular0.ber maps/invalid/not_rectangular1.ber maps/invalid/not_surrounded.ber \
	maps/invalid/other_characters.ber maps/invalid/other_extension.txt maps/invalid/two_exits.ber \
	maps/invalid/two_starting_positions.ber

# A list of all .c files in the current directory
SRCS = main.c game_manager.c file_check.c map_checker.c map_utils.c error_manager.c flood_fill.c free_variables.c
# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)
HDERS = so_long.h

CC = cc
CFLAGS = -Wall -Wextra -D SCALE=3#-Werror
ARFLAGS = -rc
RM = rm -f

COLOREND = \033[0m
GREEN = \033[1;32m
RED = \e[1;31m
YELLOW = \e[1;33m
BLUE = \033[0;34m
CIAN = \e[7;36m

# The default target - builds the project
all: $(NAME)

# A rule to build the project from the .o files
$(NAME): $(LIBFT_LIB) libmlx $(OBJS)
	@echo "$(CIAN)Compiling so_long...$(BLUE)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_LIB):
	@echo "$(CIAN)Compiling libft...$(BLUE)"
	make -C $(LIBFT) -f Makefile

# Compile de MLX42 library
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# A rule to remove all .o files
clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean
	make -C $(LIBMLX)/build clean
	@echo "$(CIAN)Objects cleaned$(COLOREND)"

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean
	@echo "$(CIAN)Full clean$(COLOREND)"

# A rule to rebuild everything from scratch
re: fclean all

# A rule to run the program
run: all
	./$(NAME) $(MAP)

testmaps:
	@echo "$(CIAN)Testing all invalid maps$(COLOREND)"
	@for file in $(INVALID_MAPS); do \
		./$(NAME) $$file | grep "ERROR" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(RED)$$file: ERROR!$(COLOREND)"; \
		else \
			echo "$(YELLOW)$$file: SHOULD GIVE AN ERROR?$(COLOREND)"; \
		fi \
	done
	@echo "$(CIAN)Testing all valid maps$(COLOREND)"
	@for file in $(VALID_MAPS); do \
		./$(NAME) $$file | grep "ERROR" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(RED)$$file: ERROR!$(COLOREND)"; \
		else \
			echo "$(GREEN)$$file: OK!$(COLOREND)"; \
		fi \
	done
	@echo "$(CIAN)All maps tested$(COLOREND)"

leaks:
	@echo "$(CIAN)Testing all invalid maps$(COLOREND)"
	@for file in $(INVALID_MAPS); do \
			$(VAL) $(VALFLAGS) ./$(NAME) $$file | grep "LEAK SUMMARY" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(RED)$$file: leaks!$(COLOREND)"; \
		else \
			echo "$(GREEN)$$file: no leaks$(COLOREND)"; \
		fi \
	done

norme:
	@echo "$(CIAN)SOURCES$(COLOREND)"
	@for file in $(SRCS); do \
		norminette $$file | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$file: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$file; \
			echo "$(COLOREND)"; \
		fi \
	done
	@echo "$(CIAN)\nHEADERS$(COLOREND)"
	@for header in $(HDERS); do \
		norminette $$header | grep "OK!" > /dev/null; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)$$header: OK!$(COLOREND)"; \
		else \
			echo "$(RED)"; \
			norminette $$header; \
			echo "$(COLOREND)"; \
		fi \
	done


# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean run error
