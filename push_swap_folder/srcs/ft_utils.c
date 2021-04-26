/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 10:47:34 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/26 16:37:19 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_big_index(t_pile *pile)
{
	int	i;
	int	j;
	int value_max;

	i = 0;
	j = 0;
	value_max = pile->value;
	while(pile)
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

int	ft_small_index(t_pile *pile)
{
	int	i;
	int	j;
	int value_min;

	i = 0;
	j = 0;
	value_min = pile->value;
	while(pile)
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