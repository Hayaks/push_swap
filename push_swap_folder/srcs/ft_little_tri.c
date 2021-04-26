/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_tri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 17:39:42 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/26 16:55:21 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_three(t_push *push)
{
	push->min_a = ft_small_index(push->first_a);
	push->max_a = ft_big_index(push->first_a);
	if (push->min_a == 1 && push->max_a == 2)
		ft_swap(push->size_a, push->first_a, 0);
	else if (push->min_a == 2 && push->max_a == 0)
	{
		ft_swap(push->size_a, push->first_a, 0);
		ft_rotate_reverse(push, 0);
	}
	else if (push->min_a == 1 && push->max_a == 0)
		ft_rotate(push, 0);
	else if (push->min_a == 0 && push->max_a == 1)
	{
		ft_swap(push->size_a, push->first_a, 0);
		ft_rotate(push, 0);
	}
	else if (push->min_a == 2 && push->max_a == 1)
		ft_rotate_reverse(push, 0);
}

void	ft_little_tri(t_push *push)
{
	while (ft_tri(push) == 0 || push->size_b > 0)
	{
		if (push->size_a == 2)
			ft_swap(push->size_a, push->first_a, 0);
		else if (push->size_a == 3)
		{
			ft_three(push);
			while (push->size_b > 0)
				ft_push(push, 0);
		}
		else
		{
			while (push->min_a != 0)
			{
				if ((double)push->size_a / (double)push->min_a > 2.0)
					ft_rotate(push, 0);
				else
					ft_rotate_reverse(push, 0);
				push->min_a = ft_small_index(push->first_a);
			}
			ft_push(push, 1);
			push->min_a = ft_small_index(push->first_a);
		}
	}
}