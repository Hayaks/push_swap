/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:23:03 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/11 19:24:56 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_high(t_push *push)
{
	t_pile *pile;
	int		min;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (push->first_b != NULL)
	{
		pile = push->first_b;
		min = pile->value;
		while (pile)
		{
			if ((pile->value < push->first_a->value && min < pile->value)
			|| (pile->value < push->first_a->value && min > push->first_a->value)
			|| (min > push->first_a->value && min < pile->value))
			{
				min = pile->value;
				j = i;
			}
			pile = pile->next;
			i++;
		}
	}
	if (push->first_b == NULL || (push->size_b == 1 && push->first_a->value > push->first_b->value))
		ft_push(push, 1);
	else if ((push->size_b == 1 && push->first_a->value < push->first_b->value)
	|| j == 0)
	{
		ft_push(push, 1);
		ft_rotate(push, 1);
	}
	else if (j < (push->size_b / 2 + 1))
	{
		while (push->first_b->value != min)
			ft_rotate(push, 1);
		ft_push(push, 1);
	}
	else
	{
		while (push->first_b->value != min)
			ft_rotate_reverse(push, 1);
		ft_push(push, 1);
	}
}

int		ft_start_or_end(t_push *push, int i)
{
	int	start;
	int	end;
	int	j;
	t_pile	*tmp;

	start = -1;
	end = -1;
	j = 0;
	tmp = push->first_a;
	while (tmp && start == -1)
	{
		if (ft_equal(push, (i - i % push->group) / push->group, tmp->value) == 1)
			start = j;
		j++;
		tmp = tmp->next;
	}
	j = 0;
	tmp = push->last_a;
	while (tmp && end == -1)
	{
		if (ft_equal(push, (i - i % push->group) / push->group, tmp->value) == 1)
			end = j;
		j++;
		tmp = tmp->prev;
	}
	return (start - end);
}

void	ft_search_nbr(t_push *push, int i)
{
	if (ft_start_or_end(push, i) <= 0)
		while (ft_equal(push, (i - i % push->group) / push->group, push->first_a->value) == 0)
			ft_rotate(push, 0);
	else
		while (ft_equal(push, (i - i % push->group) / push->group, push->first_a->value) == 0)
			ft_rotate_reverse(push, 0);
	if (ft_equal(push, (i - i % push->group) / push->group, push->first_a->value) == 1)
		ft_push_high(push);
}