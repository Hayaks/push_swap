/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:59:57 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/11 23:00:24 by jsaguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
//# include <string.h>
//# include <stdio.h>
# include "../../libft/libft.h"
typedef struct	s_push
{
	int				ac;
	char			**av;
	struct s_list	*first_a;
	struct s_list	*last_a;
	struct s_list	*first_b;
	struct s_list	*last_b;
}				t_push;
typedef struct	s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;
#endif