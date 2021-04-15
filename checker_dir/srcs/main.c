/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:56:04 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/15 15:30:38 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_get_instruction_bis(t_push *push, char *line)
{
	if (ft_strcmp(line, "rb") == 0)
		rb;
	else if (ft_strcmp(line, "rr") == 0)
	{
		ra;
		rb;
	}
	else if (ft_strcmp(line, "rra") == 0)
		rra;
	else if (ft_strcmp(line, "rrb") == 0)
		rrb;
	else if (ft_strcmp(line, "rrr") == 0)
	{
		rra;
		rrb;
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_push(push);
		free(line);
		line = NULL;
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
			sa;
		else if (ft_strcmp(line, "sb") == 0)
			sb;
		else if (ft_strcmp(line, "ss") == 0)
		{
			sa;
			sb;
		}
		else if (ft_strcmp(line, "pa") == 0)
			pa;
		else if (ft_strcmp(line, "pb") == 0)
			pb;
		else if (ft_strcmp(line, "ra") == 0)
			ra;
		else
			ft_get_instruction_bis(push, line);
		free(line);
		line = NULL;
	}
}

int		main(int ac, char **av)
{
	t_push	*push;

	ft_verif_info(ac, av);
	push = ft_malloc_push(ac, av);
	ft_begin_pile(push, av);
	ft_get_instruction(push);
	ft_free_push(push);
}
