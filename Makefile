CHECK_NAME		= checker

PUSH_NAME		= push_swap

CHECK_HEADER	= -I checker_folder/includes/ -I libft/

PUSH_HEADER		= -I push_swap_folder/includes/ -I libft/

LIBFT 			= -L libft -lft

CHECK_SRCS		= main.c ft_verif_info.c ft_malloc_free.c ft_pile.c \
					ft_instruction.c

PUSH_SRCS		= main.c ft_verif_info.c ft_malloc_free.c ft_pile.c \
					ft_instruction.c ft_utils.c ft_little_tri.c \
					ft_big_tri.c ft_search_nbr.c

CHECK_FOLDER	= $(addprefix checker_folder/srcs/, $(CHECK_SRCS))

PUSH_FOLDER		= $(addprefix push_swap_folder/srcs/, $(PUSH_SRCS))

CHECK_OBJS		= $(CHECK_FOLDER:c=o)

PUSH_OBJS		= $(PUSH_FOLDER:c=o)

CC				= clang
LIB				= ar -rcs
CFLAGS 			= -Wall -Wextra -Werror
FSAN			= -g3 -fsanitize=address
RM				= rm -f

all:			$(CHECK_NAME) $(PUSH_NAME)

%o: %.c
				$(CC) $(CFLAGS) $(LIBFT) $(CHECK_HEADER) $(PUSH_HEADER) -c $< -o $@

$(CHECK_NAME):	$(CHECK_OBJS)
				make bonus -C libft
				$(CC) $(CFLAGS) -o $(CHECK_NAME) $(CHECK_OBJS) $(LIBFT)

$(PUSH_NAME):	$(PUSH_OBJS)
				make bonus -C libft
				$(CC) $(CFLAGS) -o $(PUSH_NAME) $(PUSH_OBJS) $(LIBFT)

fsan:			$(PUSH_OBJS)
				make bonus -C libft
				$(CC) $(CFLAGS) $(FSAN) -o $(PUSH_NAME) $(PUSH_OBJS) $(LIBFT)

leaks:			$(PUSH_NAME)
				valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes ./$(PUSH_NAME)

clean:
				make clean -C libft
				$(RM) $(CHECK_OBJS) $(PUSH_OBJS)

fclean:			clean
				make fclean -C libft
				$(RM) $(CHECK_NAME) $(PUSH_NAME)

re:				fclean all

.PHONY: all clean fclean re test fsan leaks