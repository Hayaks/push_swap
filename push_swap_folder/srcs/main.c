/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:56:04 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/13 15:42:34 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_tri(t_push *push)
{
	int		value;
	t_pile	*pile;

	pile = NULL;
	pile = push->first_a;
	while (pile)
	{
		value = pile->value;
		if (pile->next != NULL && value > pile->next->value)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_push	*push;

	ft_verif_info(ac, av);
	push = ft_malloc_push(ac, av);
	ft_begin_pile(push, av);
	if (ft_tri(push) == 0 && push->size_a > 1 && push->size_a < 30)
		ft_little_tri(push);
	else if (ft_tri(push) == 0 && push->size_a >= 30)
	{
		ft_add_tab(push);
		ft_big_tri(push);
		free(push->all_nbr);
	}
	ft_free_push(push);
}
