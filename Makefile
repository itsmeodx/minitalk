CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	server
NAME2	=	client
SRC	=	server.c
SRC2	=	client.c
OBJ	=	$(SRC:.c=.o)
OBJ2	=	$(SRC2:.c=.o)

all:	$(NAME) $(NAME2)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(NAME2):	$(OBJ2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)

clean:
	rm -f $(OBJ) $(OBJ2)

fclean:	clean
	rm -f $(NAME) $(NAME2)

re:	fclean all

.PHONY:	all clean
