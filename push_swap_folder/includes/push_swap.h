/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:14:06 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/11 19:04:59 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../libft/libft.h"

typedef struct	s_push
{
	int				ac;
	char			**av;
	struct s_pile	*first_a;
	struct s_pile	*last_a;
	struct s_pile	*first_b;
	struct s_pile	*last_b;
	int				size_a;
	int				size_b;
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	int				*all_nbr;
	int				nb_list;
	int				group;
	int				size_all;
}				t_push;

typedef struct	s_pile
{
	int				value;
	struct s_pile	*prev;
	struct s_pile	*next;
}				t_pile;

void			ft_verif_info(int ac, char **av);
long int		ft_atoi_verif(const char *nbr);
t_push  		*ft_malloc_push(int ac, char **av);
void			ft_free_push(t_push *push);
void			ft_begin_pile(t_push *push, char **av);
void			ft_delete_pile(t_push *push, t_pile *pile, int mod);
void			ft_add_pile(t_push *push, t_pile *first, t_pile *pile, int mod);
int				ft_tri(t_push *push);
void			ft_swap(int i, t_pile *pile, int mod);
void			ft_rotate(t_push *push, int mod);
void			ft_rotate_reverse(t_push *push, int mod);
void			ft_push(t_push *push, int mod);
int				ft_small_index(t_pile *pile);
int				ft_big_index(t_pile *pile);
void			ft_add_tab(t_push *push);
void			ft_little_tri(t_push *push);
int				ft_small_index_tab(t_pile *pile, int limit, int position);
int				ft_equal(t_push *push, int x, int nbr);
void			ft_three(t_push *push);
void			ft_big_tri(t_push *push);
void			ft_search_nbr(t_push *push, int i);
int				ft_start_or_end(t_push *push, int i);
void			ft_push_high(t_push *push);
void			ft_show(t_push *push); //Ne pas oublier
#endif