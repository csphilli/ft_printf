/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/06 13:33:11 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static uintmax_t	get_nbr(t_struct *csp)
{
	uintmax_t nbr;
	//print_specifiers(csp);
	if (ft_strcmp(csp->len_flags, "h") == 0)
	{
		nbr = (unsigned short)va_arg(csp->args, unsigned int);
		//printf("h: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "hh") == 0)
	{
		nbr = (unsigned char)va_arg(csp->args, unsigned int);
		//printf("hh: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "l") == 0)
	{
		nbr = (unsigned long)va_arg(csp->args, unsigned long int);
		//printf("l: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "ll") == 0)
	{
		nbr = (unsigned long long)va_arg(csp->args, unsigned long long int);
		//printf("ll: %ld\n", nbr);
	}
	else
	{
		nbr = (unsigned int)va_arg(csp->args, unsigned int);
		//printf("no flag: %ld\n", nbr);
	}
	nbr = (uintmax_t)nbr;
	return (nbr);
}

t_struct	*print_x(t_struct *csp)
{
	char		*tmp;
	int			s_len;
	int			padding;
	uintmax_t	nbr;
	// correct s_len size?
	// need another function to handle the signed ints.
	s_len = 0;
	nbr = get_nbr(csp);
	tmp = convert_nbr(nbr, 16);
	if (csp->specifier == 'X')
		tmp = ft_s_toupper(tmp);
	s_len = ft_strlen(tmp);
	padding = get_padding(csp, s_len);
	align_print(csp, tmp, s_len);
	update_len(csp, s_len);
	return (csp);
}




