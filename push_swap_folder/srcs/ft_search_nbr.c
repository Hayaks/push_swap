/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:23:03 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/09 20:07:20 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_high(t_push *push)
{
	int	tmp;

	tmp = 0;
	if (push->first_b == NULL || push->first_a->value > push->first_b->value)
		ft_push(push, 1);
	else if (push->first_a->value < push->last_b->value)
	{
		ft_push(push, 1);
		ft_rotate(push, 1);
	}
	else
	{
		tmp = push->first_b->value;
		while (push->first_a->value < push->first_b->value)
			ft_rotate(push, 1);
		ft_push(push, 1);
		while (push->first_b->value != tmp)
			ft_rotate_reverse(push, 1);
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
	while (tmp && start == -1 && j < (push->size_a / 2) + 1)
	{
		if (ft_equal(push, (i - i % 10) / 10, tmp->value) == 1)
			start = j;
		j++;
		tmp = tmp->next;
	}
	j = 1;
	tmp = push->last_a;
	while (tmp && end == -1 && j < (push->size_a / 2) + 1)
	{
		if (ft_equal(push, (i - i % 10) / 10, tmp->value) == 1)
			end = j;
		j++;
		tmp = tmp->prev;
	}
	return (start - end);
}

void	ft_search_nbr(t_push *push, int i)
{
	if (ft_start_or_end(push, i) <= 0)
		while (ft_equal(push, (i - i % 10) / 10, push->first_a->value) == 0)
			ft_rotate(push, 0);
	else
		while (ft_equal(push, (i - i % 10) / 10, push->first_a->value) == 0)
			ft_rotate_reverse(push, 0);
	if (ft_equal(push, (i - i % 10) / 10, push->first_a->value) == 1)
		ft_push_high(push);
}