/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:10:44 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/21 22:08:53 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_push(t_push *push, int case)
{
	t_pile	*tmp;
	
	tmp = NULL;
	if ((case == 0 && push->size_b < 1)
	|| (case == 1 && push->size_a < 1))
		return ;
	if (case == 0)
	{
		tmp = push->first_b;
		ft_delete_pile(push, tmp, case);
		ft_add_pile(push, first_a, tmp, case);
	}
	else
	{
		tmp = push->first_a;
		ft_delete_pile(push, tmp, case);
		ft_add_pile(push, first_b, tmp, case);
	}
}

void	ft_rotate_reverse(int i, t_pile *pile_begin, t_pile *pile_end)
{
	t_pile	*tmp;

	if (i <= 1)
		return ;
	pile_end->prev->next = NULL;
	tmp = pile_end->prev;
	pile_begin->prev = pile_end;
	pile_end->prev = NULL;
	pile_end->next = pile_begin;
	pile_begin = pile_end;
	pile_end = tmp;
}

void	ft_rotate(int i, t_pile *pile_begin, t_pile *pile_end)
{
	t_pile	*tmp;

	if (i <= 1)
		return ;
	pile_begin->next->prev = NULL;
	tmp = pile_begin->next;
	pile_end->next = pile_begin;
	pile_begin->next = NULL;
	pile_begin->prev = pile_end;
	pile_end = pile_begin;
	pile_begin = tmp;
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