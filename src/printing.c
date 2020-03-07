/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:36:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/07 12:14:23 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_s_la_p(t_struct *csp, char *tmp, int s_len)
{
	if (csp->prec < s_len && csp->specifier == 's')
		while (csp->prec--)
			ft_putchar(*(tmp++));
	else
		ft_putstr(tmp);
		// while (s_len--)
		// 	ft_putchar(*(tmp++));
	if (csp->c_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	free(tmp);
	return (csp);
}

t_struct	*print_s_ra_p(t_struct *csp, char *tmp, int s_len)
{
	if (csp->c_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	if (csp->prec < s_len && csp->specifier == 's')
		while (csp->prec--)
			ft_putchar(*(tmp++));
	else
		ft_putstr(tmp);
		// while (s_len--)
		// 	ft_putchar(*(tmp++));
	free(tmp);
	return (csp);
}

t_struct	*print_s_la_no_p(t_struct *csp, char *tmp, int s_len)
{
	ft_putstr(tmp);
	if (csp->c_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	free(tmp);
	return (csp);
}

t_struct	*print_s_ra_no_p(t_struct *csp, char *tmp, int s_len)
{
	if (csp->c_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	ft_putstr(tmp);
	free(tmp);
	return (csp);
}
