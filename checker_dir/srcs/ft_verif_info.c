/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 23:50:25 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/14 10:28:00 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

long int	ft_atoi_verif(const char *str)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[0] == '-')
		sign = -1;
	if (sign == -1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (nb > 2147483647 || nb < -2147483648
	|| str[i] != '\0' || str[0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (nb * sign);
}

void		ft_verif_info(int ac, char **av)
{
	int	i;
	int	j;
	int	nbr;

	i = 1;
	if (ac < 2)
		exit(1);
	while (i < ac)
	{
		ft_atoi_verif(av[i]);
		j = 1;
		nbr = ft_atoi(av[i]);
		while (j < ac)
		{
			if (j != i && ft_atoi(av[j]) == nbr)
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
