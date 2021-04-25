/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:10:44 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/25 14:24:47 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_push *push, int mod)
{
	t_pile	*tmp;

	tmp = NULL;
	if ((mod == 0 && push->size_b < 1)
	|| (mod == 1 && push->size_a < 1))
		return ;
	if (mod == 0)
	{
		tmp = push->first_b;
		ft_delete_pile(push, tmp, mod);
		ft_add_pile(push, push->first_a, tmp, mod);
	}
	else
	{
		tmp = push->first_a;
		ft_delete_pile(push, tmp, mod);
		ft_add_pile(push, push->first_b, tmp, mod);
	}
}

void	ft_rotate_reverse(t_push *push, int mod)
{
	t_pile	*tmp;

	tmp = NULL;
	if (mod == 0)
	{
		push->last_a->prev->next = NULL;
		tmp = push->last_a->prev;
		push->first_a->prev = push->last_a;
		push->last_a->prev = NULL;
		push->last_a->next = push->first_a;
		push->first_a = push->last_a;
		push->last_a = tmp;
	}
	else
	{
		push->last_b->prev->next = NULL;
		tmp = push->last_b->prev;
		push->first_b->prev = push->last_b;
		push->last_b->prev = NULL;
		push->last_b->next = push->first_b;
		push->first_b = push->last_b;
		push->last_b = tmp;
	}
}

void	ft_rotate(t_push *push, int mod)
{
	t_pile	*tmp;

	tmp = NULL;
	if (mod == 0)
	{
		push->first_a->next->prev = NULL;
		tmp = push->first_a->next;
		push->last_a->next = push->first_a;
		push->first_a->next = NULL;
		push->first_a->prev = push->last_a;
		push->last_a = push->first_a;
		push->first_a = tmp;
	}
	else
	{
		push->first_b->next->prev = NULL;
		tmp = push->first_b->next;
		push->last_b->next = push->first_b;
		push->first_b->next = NULL;
		push->first_b->prev = push->last_b;
		push->last_b = push->first_b;
		push->first_b = tmp;
	}
}

void	ft_swap(int i, t_pile *pile)
{
	int	tmp;

	if (i <= 1)
		return ;
	tmp = pile->value;
	pile->value = pile->next->value;
	pile->next->value = tmp;
}
