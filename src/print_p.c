/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:58:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/11 10:54:31 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_p(t_struct *csp)
{
	char		*tmp;
	int			s_len;
	uintmax_t	nbr;

	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp = cvt_nbr(csp, nbr, 16);
	tmp = ft_strjoin("0x", tmp);
	if (tmp == NULL || nbr == 0)
		tmp = ft_strjoin(tmp, "0");
	s_len = ft_strlen(tmp);
	get_padding(csp, s_len);
	csp->len += ft_strlen(tmp);
	align_print(csp, tmp, s_len);
	return (csp);
}
