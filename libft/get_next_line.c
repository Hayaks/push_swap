/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:06:53 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/15 14:25:26 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cat(char *s, char c)
{
	int		i;
	char	*cat;

	i = 0;
	while (s[i] != 0)
		i++;
	cat = malloc(sizeof(*cat) * (i + 2));
	if (!cat)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		cat[i] = s[i];
		i++;
	}
	cat[i] = c;
	cat[i + 1] = 0;
	free(s);
	return (cat);
}

int		get_next_line(int fd, char **line)
{
	char	*cat;
	char	buf;
	int		ret;

	cat = malloc(sizeof(char) * 1);
	if (fd < 0 || !line || !cat)
		return (-1);
	cat[0] = 0;
	ret = read(fd, &buf, 1);
	while (ret != 0)
	{
		if (ret == -1)
			return (-1);
		if (buf == '\n')
			break ;
		cat = ft_cat(cat, buf);
		ret = read(fd, &buf, 1);
	}
	*line = cat;
	if (*line == NULL)
		ret = -1;
	return (ret);
}
