MAKEFLAGS += --no-print-directory
# The name of your project
NAME = so_long
MAP = ./maps/map.ber
LIBFT = ./libft/
LIBFT_LIB = $(LIBFT)libft.a
LIBMLX	:= ./MLX42
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# The C compiler to use
CC = cc

# The flags to use with the archiver
ARFLAGS = -rc

# The flags to use with the C compiler
CFLAGS = -Wall -Wextra -Werror

# The command to remove files
RM = rm -f

# A list of all .c files in the current directory
SRCS = main.c \
	game_manager.c \
	file_check.c \
	map_manager.c \
	error_manager.c

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# The default target - builds the project
all: $(NAME)

# A rule to build the project from the .o files
$(NAME): $(LIBFT_LIB) libmlx $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(LIBFT_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT_LIB):
	make -C $(LIBFT) -f Makefile

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# A rule to remove all .o files
clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean
	make -C $(LIBMLX)/build clean

# A rule to remove all .o files and the project
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

# A rule to rebuild everything from scratch
re: fclean all

# A rule to run the program
run: all
	./$(NAME) $(MAP)

testmaps: all
	./$(NAME) ./maps/invalid/change_permissions.ber
	./$(NAME) ./maps/invalid/empty.ber
	./$(NAME) ./maps/invalid/no_collectibles.ber
	./$(NAME) ./maps/invalid/no_exit.ber
	./$(NAME) ./maps/invalid/no_extension
	./$(NAME) ./maps/invalid/no_path0.ber
	./$(NAME) ./maps/invalid/no_path1.ber
	./$(NAME) ./maps/invalid/no_starting_position.ber
	./$(NAME) ./maps/invalid/not_rectangular0.ber
	./$(NAME) ./maps/invalid/not_rectangular1.ber
	./$(NAME) ./maps/invalid/not_surrounded.ber
	./$(NAME) ./maps/invalid/other_characters.ber
	./$(NAME) ./maps/invalid/other_extension.txt
	./$(NAME) ./maps/invalid/two_exits.ber
	./$(NAME) ./maps/invalid/two_starting_positions.ber
	./$(NAME) ./maps/map1.ber

# A special rule to tell make that these targets aren't files
.PHONY: all fclean re clean run error
