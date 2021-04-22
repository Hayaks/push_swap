/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:56:04 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/22 13:43:42 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_get_instruction_bis(t_push *push, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		ft_rotate(push->size_a, push->first_a, push->last_a);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rotate(push->size_b, push->first_b, push->last_b);
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_rotate(push->size_a, push->first_a, push->last_a);
		ft_rotate(push->size_b, push->first_b, push->last_b);
	}
	else if (ft_strcmp(line, "rra") == 0)
		ft_rotate_reverse(push->size_a, push->first_a, push->last_a);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rotate_reverse(push->size_b, push->first_b, push->last_b);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_rotate_reverse(push->size_a, push->first_a, push->last_a);
		ft_rotate_reverse(push->size_b, push->first_b, push->last_b);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_push(push);
		free(line);
		exit(1);
	}
}

void	ft_get_instruction(t_push *push)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "sa") == 0)
			ft_swap(push->size_a, push->first_a);
		else if (ft_strcmp(line, "sb") == 0)
			ft_swap(push->size_b, push->first_b);
		else if (ft_strcmp(line, "ss") == 0)
		{
			ft_swap(push->size_a, push->first_a);
			ft_swap(push->size_b, push->first_b);
		}
		else if (ft_strcmp(line, "pa") == 0)
			ft_push(push, 0);
		else if (ft_strcmp(line, "pb") == 0)
			ft_push(push, 1);
		else
			ft_get_instruction_bis(push, line);
		free(line);
		line = NULL;
	}
	free(line);
}

void	ft_show(t_push *push)
{
	int		value;
	t_pile	*pile;

	pile = push->first_a;
	while (pile)
	{
		value = pile->value;
		printf("Value A: %i \n", value);
		pile = pile->next;
	}
	pile = push->first_b;
	while (pile)
	{
		value = pile->value;
		printf("Value B: %i \n", value);
		pile = pile->next;
	}
}

int		main(int ac, char **av)
{
	t_push	*push;

	ft_verif_info(ac, av);
	push = ft_malloc_push(ac, av);
	ft_begin_pile(push, av);
	ft_get_instruction(push);
	ft_show(push); //Verification des listes chainées
	ft_free_push(push);
}
