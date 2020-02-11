/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:07:57 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/10 12:16:53 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_alt(t_struct *csp, int padding, int c)
{
	char *new;

	if (padding > 0)
	{
		if (!(new = ft_strnew(padding)))
			exit(-1);
		ft_memset(new, c, padding);
		write(1, new, padding);
		csp->len += padding;
		free(new);
	}
	return (csp);
}
