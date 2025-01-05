# The name of your library
NAME = libft.a

# The compiler to use
CC = cc

# The archiver to use
AR = ar

# The flags to use with the archiver
ARFLAGS = -rc

# The flags to use with the compiler
CFLAGS = -Wall -Wextra -Werror

# The command to remove files
RM = rm -f

# A list of all .c files wanted
SRCS = \
	libft/ft_isalpha.c \
	libft/ft_isdigit.c \
	libft/ft_isalnum.c \
	libft/ft_isascii.c \
	libft/ft_isprint.c \
	libft/ft_strlen.c \
	libft/ft_memset.c \
	libft/ft_bzero.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_strlcpy.c \
	libft/ft_strlcat.c \
	libft/ft_toupper.c \
	libft/ft_tolower.c \
	libft/ft_strchr.c \
	libft/ft_strrchr.c \
	libft/ft_strncmp.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_strnstr.c \
	libft/ft_atoi.c \
	libft/ft_calloc.c \
	libft/ft_strdup.c \
	libft/ft_substr.c \
	libft/ft_strjoin.c \
	libft/ft_strtrim.c \
	libft/ft_split.c \
	libft/ft_itoa.c \
	libft/ft_strmapi.c \
	libft/ft_striteri.c \
	libft/ft_putchar_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_lstnew.c \
	libft/ft_lstadd_front.c \
	libft/ft_lstsize.c \
	libft/ft_lstlast.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstdelone.c \
	libft/ft_lstclear.c \
	libft/ft_lstiter.c \
	libft/ft_lstmap.c \
	printf/ft_printf.c \
	printf/ft_printnumbers.c \
	printf/ft_printcharacters.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c

# A list of all .o files that correspond to the .c files
OBJS = $(SRCS:.c=.o)

# The default target. Builds the library
all: $(NAME)

# A rule to build the library from the .o files
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# A 
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -c

# A rule to remove all the .o files
clean:
	$(RM) $(OBJS) $(BNS)

# A rule to remove all the .o files and the library
fclean: clean
	$(RM) $(NAME)

# A rule to rebuild everthing from scratch
re: fclean all

# A especial rule to tell Makefile that these targets aren't files
.PHONY: all clean fclean re
