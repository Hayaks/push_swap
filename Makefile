CHECK_NAME		= checker

CHECK_HEADER	= -I checker_dir/includes/ -I libft/

LIBFT 			= -L libft/libft.a

CHECK_SRCS		= checker.c

CHECK_DIR		= $(addprefix checker_dir/srcs/, $(CHECK_SRCS))

CHECK_OBJS		= $(CHECK_DIR:c=o)

CC				= clang
LIB				= ar -rcs
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			$(CHECK_NAME)

.c.o:
				$(CC) $(CFLAGS) $(LIBFT) $(CHECK_HEADER) -c $< -o $@

$(CHECK_NAME):	$(CHECK_OBJS)
				make bonus -C libft
				$(CC) $(CFLAGS) -o $(CHECK_NAME) $(CHECK_OBJS) $(LIBFT)

clean:
				make clean -C libft
				$(RM) $(CHECK_OBJS)

fclean:			clean
				make fclean -C libft
				$(RM) $(CHECK_NAME)

re:				fclean all

.PHONY: all clean fclean re test norm