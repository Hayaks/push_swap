/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaguez <jsaguez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:59:57 by jsaguez           #+#    #+#             */
/*   Updated: 2021/04/08 11:29:43 by jsaguez          ###   ########.fr       */
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
	struct s_pile	*first_a;
	struct s_pile	*last_a;
	struct s_pile	*first_b;
	struct s_pile	*last_b;
}				t_push;
typedef struct	s_pile
{
	int				value;
	struct s_pile	*prev;
	struct s_pile	*next;
}				t_pile;
#endif