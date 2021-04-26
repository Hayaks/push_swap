/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:59:57 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/25 17:41:00 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
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
void			ft_get_instruction(t_push *push);
void			ft_get_instruction_bis(t_push *push, char *line);
int				ft_tri(t_push *push);
void			ft_swap(int i, t_pile *pile);
void			ft_rotate(t_push *push, int mod);
void			ft_rotate_reverse(t_push *push, int mod);
void			ft_push(t_push *push, int mod);
void			ft_show(t_push *push); //Ne pas oublier
#endif