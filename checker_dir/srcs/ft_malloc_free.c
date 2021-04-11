/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:15:46 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/11 23:34:50 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_push  *ft_malloc_push(int ac, char **av)
{
    t_push  *push;

    push = (t_push*)malloc(sizeof(t_push));
    push.ac = ac;
    push.av = av;
}