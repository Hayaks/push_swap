/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:56:04 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/22 17:38:22 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_get_instruction_bis(t_push *push, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		ft_rotate(push, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rotate(push, 1);
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_rotate(push, 0);
		ft_rotate(push, 1);
	}
	else if (ft_strcmp(line, "rra") == 0)
		ft_rotate_reverse(push, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rotate_reverse(push, 1);
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_rotate_reverse(push, 0);
		ft_rotate_reverse(push, 1);
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
	printf("Size A: %i \n", push->size_a);
	pile = push->first_b;
	while (pile)
	{
		value = pile->value;
		printf("Value B: %i \n", value);
		pile = pile->next;
	}
	printf("Size B: %i \n", push->size_b);
}

int		ft_tri(t_push *push)
{
	int		value;
	t_pile	*pile;

	pile = NULL;
	if (push->size_b != 0)
		return (0);
	pile = push->first_a;
	while (pile)
	{
		value = pile->value;
		if (pile->next != NULL && value > pile->next->value)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_push	*push;

	ft_verif_info(ac, av);
	push = ft_malloc_push(ac, av);
	ft_begin_pile(push, av);
	ft_get_instruction(push);
	ft_show(push); //Verification des listes chainées
	if (ft_tri(push) == 1)
		printf("OK\n");
	else
		printf("KO\n");
	ft_free_push(push);
}
