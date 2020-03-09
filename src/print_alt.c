/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:07:57 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/09 21:44:21 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Handles the printing of anything not related to the actual string/number
**	This function also helps facilitate the return length value.
*/

t_struct	*print_alt(t_struct *csp, int amount, int c)
{
	char *new;

	if (amount > 0)
	{
		if (!(new = ft_strnew(amount))) // Try subbing in just malloc here to see if speed improves.
			exit(-1);
		ft_memset(new, c, amount);
		write(1, new, amount);
		csp->len += amount;
		free(new);
	}
	return (csp);
}
