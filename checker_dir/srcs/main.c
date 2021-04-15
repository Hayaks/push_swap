/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:56:04 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/15 14:59:01 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_get_instruction(t_push *push)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
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