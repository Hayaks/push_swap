/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:19:45 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/26 11:32:56 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_pile(t_push *push, t_pile *first, t_pile *pile, int mod)
{
	pile->next = first;
	if (first != NULL)
		first->prev = pile;
	if (mod == 0 && first == NULL)
	{
		push->first_a = pile;
		push->last_a = pile;
	}
	else if (mod == 1 && first == NULL)
	{
		push->first_b = pile;
		push->last_b = pile;
	}
	else if (mod == 0 && first != NULL)
		push->first_a = pile;
	else if (mod == 1 && first != NULL)
		push->first_b = pile;
	if (mod == 0)
		push->size_a++;
	else
		push->size_b++;
}

void	ft_delete_pile(t_push *push, t_pile *pile, int mod)
{
	if (mod == 0)
	{
		push->first_b = pile->next;
		push->size_b--;
	}
	else
	{
		push->first_a = pile->next;
		push->size_a--;
	}
	if (pile->next != NULL)
		pile->next->prev = NULL;
}

void	ft_begin_pile(t_push *push, char **av)
{
	int		i;
	t_pile	*pile1;
	t_pile	*pile2;

	i = 1;
	pile1 = NULL;
	pile2 = NULL;
	while (av[i])
	{
		pile1 = malloc(sizeof(t_pile));
		pile1->value = ft_atoi(av[i]);
		pile1->prev = pile2;
		if (pile2)
			pile2->next = pile1;
		pile2 = pile1;
		i++;
	}
	pile1->next = NULL;
	push->last_a = pile1;
	while (pile1 && pile1->prev)
		pile1 = pile1->prev;
	push->first_a = pile1;
	push->size_a = i - 1;
	push->min_a = ft_small_index(push->first_a);
	push->max_a = ft_big_index(push->first_a);
}
