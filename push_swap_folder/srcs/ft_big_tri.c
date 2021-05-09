/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:47:55 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/09 20:57:36 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_big_tri(t_push *push)
{
	int	nb_list;
	int	i;

	nb_list = (push->size_a - push->size_a % 10) / 10;
	i = 0;
	while (((i - i % 10) / 10) != nb_list)
	{
		ft_search_nbr(push, i);
		i++;
	}
	while (push->first_a)
		ft_push_high(push);
	while (push->first_b)
		ft_push(push, 0);
}
