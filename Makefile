NAME	= so_long
SRCS	= $(shell find ./SRC -iname "*.c")
OBJS	= ${SRCS:.c=.o}
INCS	= -IINCS
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} ${INCS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} 
# -framework OpenGL -framework AppKit -lmlx

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
