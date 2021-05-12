/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:47:55 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/11 19:24:00 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_big_tri(t_push *push)
{
	int	i;

	if (push->size_a <= 100)
		push->nb_list = 6;
	else
		push->nb_list = 12;
	i = 0;
	push->size_all = push->size_a;
	push->x = (push->size_all - push->size_all % 10) / push->nb_list;
	while (i != (push->size_all - push->size_all % 10))
	{
		ft_search_nbr(push, i);
		i++;
	}
	while (push->first_a)
		ft_push_high(push);
	push->max_b = ft_big_index(push->first_b);
	while (push->max_b != 0)
	{
		ft_rotate_reverse(push, 1);
		push->max_b = ft_big_index(push->first_b);
	}
	while (push->first_b)
		ft_push(push, 0);
}
