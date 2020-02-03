/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:58:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/03 21:36:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_p(t_struct *csp)
{
	char		*tmp;
	int			base;
	int			s_len;
	int			padding;
	uintmax_t	nbr;

// need to have if/else statement here in case value is NULL. TMP will then be '(nil)'

	base = 16;
	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp = convert_nbr(nbr, base);
	tmp = ft_strjoin("0x", tmp);
	s_len = ft_strlen(tmp);
	padding = get_padding(csp, s_len);
	csp->len += ft_strlen(tmp);
	align_print(csp, padding, tmp);
	return (csp);
}
