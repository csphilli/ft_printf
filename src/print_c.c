/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:38:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/06 19:33:22 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_c(t_struct *csp)
{
	csp->len += csp->width;
	if (csp->c_flags[0] == '-' && csp->width > 0 && \
		(csp->c_flags[4] == 0 || csp->c_flags[4] != '\0'))
	{
		ft_putchar(va_arg(csp->args, int));
		while ((csp->width--) - 1 >= 1)
			ft_putchar(32);
	}
	else
	{
		while ((csp->width--) - 1 > 0)
			ft_putchar(32);
		ft_putchar(va_arg(csp->args, int));
	}
	return (csp);
}
