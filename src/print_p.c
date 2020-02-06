/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:58:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/06 13:23:40 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_p(t_struct *csp)
{
	char		*tmp;
	int			s_len;
	int			padding;
	uintmax_t	nbr;

// need to have if/else statement here in case value is NULL. TMP will then be '(nil)'
	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp = convert_nbr(nbr, 16);
	printf("tmp:%s\n", tmp);
	if (tmp == NULL)
		tmp = ft_strjoin(tmp, "0");
	tmp = ft_strjoin("0x", tmp);
	s_len = ft_strlen(tmp);
	
	padding = get_padding(csp, s_len);
	csp->len += ft_strlen(tmp);
	//align_print(csp, padding, tmp, s_len);
	return (csp);
}
