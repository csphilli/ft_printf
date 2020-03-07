/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:58:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/07 00:29:48 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_p(t_struct *csp)
{
	char		*tmp_s;
	char		*tmp_n;
	int			s_len;
	uintmax_t	nbr;

	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp_n = ft_itoa_base(nbr, 16);
	tmp_s = ft_strjoin("0x", tmp_n);
	if (tmp_s == NULL || nbr == 0)
		tmp_s = ft_strjoin(tmp_s, "0");
	s_len = ft_strlen(tmp_s);
	get_padding(csp, s_len);
	csp->len += ft_strlen(tmp_s);
	align_print(csp, tmp_s, s_len);
	free(tmp_s);
	free(tmp_n);
	return (csp);
}
