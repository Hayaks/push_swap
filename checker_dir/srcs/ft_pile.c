/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:19:45 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/14 11:19:41 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	push->size_p = i - 1;
}