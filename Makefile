NAME	= so_long
SRCS	= ./SRC/errors.c \
./SRC/check_map.c \
./SRC/check_map_2.c \
./SRC/convert.c \
./SRC/event.c \
./SRC/FT_PRINTF/ft_printf.c \
./SRC/FT_PRINTF/ft_printf_utils.c \
./SRC/GNL/get_next_line.c \
./SRC/GNL/get_next_line_utils.c \
./SRC/initialisation.c \
./SRC/LIB/ft_atoi.c \
./SRC/LIB/ft_bzero.c \
./SRC/LIB/ft_calloc.c \
./SRC/LIB/ft_isalnum.c \
./SRC/LIB/ft_isalpha.c \
./SRC/LIB/ft_isascii.c \
./SRC/LIB/ft_isdigit.c \
./SRC/LIB/ft_isprint.c \
./SRC/LIB/ft_itoa.c \
./SRC/LIB/ft_lstadd_back_bonus.c \
./SRC/LIB/ft_lstadd_front_bonus.c \
./SRC/LIB/ft_lstclear_bonus.c \
./SRC/LIB/ft_lstdelone_bonus.c \
./SRC/LIB/ft_lstiter_bonus.c \
./SRC/LIB/ft_lstlast_bonus.c \
./SRC/LIB/ft_lstmap_bonus.c \
./SRC/LIB/ft_lstnew_bonus.c \
./SRC/LIB/ft_lstsize_bonus.c \
./SRC/LIB/ft_memchr.c \
./SRC/LIB/ft_memcmp.c \
./SRC/LIB/ft_memcpy.c \
./SRC/LIB/ft_memmove.c \
./SRC/LIB/ft_memset.c \
./SRC/LIB/ft_putchar_fd.c \
./SRC/LIB/ft_putendl_fd.c \
./SRC/LIB/ft_putnbr_fd.c \
./SRC/LIB/ft_putstr_fd.c \
./SRC/LIB/ft_split.c \
./SRC/LIB/ft_strchr.c \
./SRC/LIB/ft_strdup.c \
./SRC/LIB/ft_striteri.c \
./SRC/LIB/ft_strjoin.c \
./SRC/LIB/ft_strlcat.c \
./SRC/LIB/ft_strlcpy.c \
./SRC/LIB/ft_strlen.c \
./SRC/LIB/ft_strmapi.c \
./SRC/LIB/ft_strncmp.c \
./SRC/LIB/ft_strnstr.c \
./SRC/LIB/ft_strrchr.c \
./SRC/LIB/ft_strtrim.c \
./SRC/LIB/ft_substr.c \
./SRC/LIB/ft_tolower.c \
./SRC/LIB/ft_toupper.c \
./SRC/main.c \
./SRC/moves.c \
./SRC/path_finding.c
OBJS	= ${SRCS:.c=.o}
INCS	= -IINCS
CC		= gcc -fsanitize=address
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} -framework OpenGL -framework AppKit -lmlx

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
