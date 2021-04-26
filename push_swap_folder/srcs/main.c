/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:56:04 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/26 16:39:24 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_show(t_push *push)
{
	int		value;
	t_pile	*pile;

	pile = push->first_a;
	while (pile)
	{
		value = pile->value;
		printf("Value A: %i \n", value);
		pile = pile->next;
	}
	printf("Size A: %i \n", push->size_a);
	pile = push->first_b;
	while (pile)
	{
		value = pile->value;
		printf("Value B: %i \n", value);
		pile = pile->next;
	}
	printf("Size B: %i \n", push->size_b);
}

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
	//Beginning
	if (ft_tri(push) == 0 && ac > 2 && ac <= 6)
		ft_little_tri(push);
	//else if (ft_tri(push) == 0 && ac > 6)
		//ft_big_tri(push);
	ft_show(push); //Verification des listes chainées
	ft_free_push(push);
}
