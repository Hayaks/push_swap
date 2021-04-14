/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:15:46 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/14 16:26:55 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_free_push(t_push *push)
{
	t_pile *tmp;
	
	while (push->first_a)
	{
		printf("Value: %i \n", push->first_a->value);
		tmp = push->first_a->next;
		free(push->first_a);
		push->first_a = tmp;
	}
	while (push->first_b)
	{
		tmp = push->first_b->next;
		free(push->first_b);
		push->first_b = tmp;
	}
	if (push)
	{
		free(push);
		push = NULL;
	}
}

t_push	*ft_malloc_push(int ac, char **av)
{
	t_push	*push;
	
	push = NULL;
	push = (t_push*)malloc(sizeof(t_push));
	push->ac = ac;
	push->av = av;
	push->first_a = NULL;
	push->last_a = NULL;
	push->first_b = NULL;
	push->last_b = NULL;
	return (push);
}