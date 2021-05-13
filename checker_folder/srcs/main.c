/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:56:04 by jsaguez           #+#    #+#             */
/*   Updated: 2021/05/13 15:43:37 by jsaguez          ###   ########.fr       */
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

int		ft_tri(t_push *push)
{
	int		value;
	t_pile	*pile;

	pile = NULL;
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
	if (ft_tri(push) == 1 && push->size_b <= 0)
		printf("OK\n");
	else
		printf("KO\n");
	ft_free_push(push);
}
