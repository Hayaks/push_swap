/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:15:46 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/14 11:24:51 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_free_push(t_push *push)
{
	
}

t_push	*ft_malloc_push(int ac, char **av)
{
	t_push	*push;
	
	push = (t_push*)malloc(sizeof(t_push));
	push->ac = ac;
	push->av = av;
	push->first_a = NULL;
	push->last_a = NULL;
	push->first_b = NULL;
	push->last_b = NULL;
	return (push);
}