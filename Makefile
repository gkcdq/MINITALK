SRCS		= server.c client.c
OBJS		= $(SRCS:.c=.o)
SERVER		= server
CLIENT		= client
CC		= gcc -g
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS 	= -Llibft
INCLUDES	= -Ilibft

all: $(SERVER) $(CLIENT)

$(SERVER): server.o
	@make -C libft
	$(CC) $(CFLAGS) server.o $(LDFLAGS) -o $(SERVER)

$(CLIENT): client.o
	@make -C libft
	$(CC) $(CFLAGS) client.o $(LDFLAGS) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
