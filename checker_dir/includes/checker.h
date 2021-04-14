/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:59:57 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/14 15:08:03 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
//# include <string.h>
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
	int				size_p;
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
#endif