/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 10:47:34 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/11 15:43:45 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_equal(t_push *push, int x, int nbr)
{
	int	i;

	i = 0;
	while (i < push->x)
	{
		if (push->all_nbr[i + (push->x * x)] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int		ft_small_index_tab(t_pile *pile, int limit, int position)
{
	int	i;
	int value_min;

	i = 0;
	if (position != 0)
		while (pile->next != NULL && pile->value <= limit)
			pile = pile->next;
	value_min = pile->value;
	while (pile)
	{
		if (pile->value < value_min
		&& (position == 0 || pile->value > limit))
			value_min = pile->value;
		pile = pile->next;
		i++;
	}
	return (value_min);
}

void	ft_add_tab(t_push *push)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	push->all_nbr = malloc(sizeof(int) * push->size_a + 1);
	while (i < push->size_a)
	{
		tmp = ft_small_index_tab(push->first_a, tmp, i);
		push->all_nbr[i] = tmp;
		i++;
	}
	push->all_nbr[i] = '\0';
}

int		ft_big_index(t_pile *pile)
{
	int	i;
	int	j;
	int value_max;

	i = 0;
	j = 0;
	value_max = pile->value;
	while (pile)
	{
		if (pile->value > value_max)
		{
			value_max = pile->value;
			j = i;
		}
		pile = pile->next;
		i++;
	}
	return (j);
}

int		ft_small_index(t_pile *pile)
{
	int	i;
	int	j;
	int value_min;

	i = 0;
	j = 0;
	value_min = pile->value;
	while (pile)
	{
		if (pile->value < value_min)
		{
			value_min = pile->value;
			j = i;
		}
		pile = pile->next;
		i++;
	}
	return (j);
}
