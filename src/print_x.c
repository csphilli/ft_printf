/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/08 13:00:23 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char				*do_x(t_struct *csp, uintmax_t nbr, int m_z, char *tmp)
{
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->padding, ' ');
	print_zero(csp, csp->specifier, nbr);
	print_alt(csp, m_z, '0');
	if (csp->specifier == 'X')
		ft_s_toupper(tmp);
	else
		ft_putstr(tmp);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->padding, ' ');
	return (0);
}

t_struct			*print_x(t_struct *csp)
{
	char		*tmp;
	uintmax_t	nbr;
	int			m_z;
	int			mod;

	m_z = 0;
	nbr = get_oux_nbr(csp);
	if (nbr == 0 && csp->prec == 0)
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	tmp = ft_itoa_base(nbr, 16);
	// printf("tmp:%s\n", tmp);
	mod = (csp->c_flags[3] == '#' && nbr) ? 2 : 0;
	csp->s_len = ft_strlen(tmp); // += mod?
	// printf("s_len1:%d\n", csp->s_len);
	m_z = get_mz(csp, nbr, csp->s_len, mod);
	x_padding(csp, m_z, mod, nbr);
	do_x(csp, nbr, m_z, tmp);
	// printf("s_len2:%d\n", csp->s_len);
	// printf("len2:%d\n", csp->len);
	csp->len += update_len(csp, csp->s_len);
	// printf("csp->len:%d\n", csp->len);
	// printf("csp->s_len:%d\n", csp->s_len);
	free(tmp);
	return (csp);
}



t_struct			*print_zero(t_struct *csp, char spec, uintmax_t nbr)
{
	if (nbr && csp->c_flags[3] == '#')
	{
		if (spec == 'X')
		{
			write(1, "0X", 2);
			csp->len += 2;
		}
		else if (spec == 'x')
		{
			write(1, "0x", 2);
			csp->len += 2;
		}
	}
	return (csp);
}
