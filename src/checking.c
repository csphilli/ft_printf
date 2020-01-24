/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:16:22 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/24 13:09:38 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*chk_conv_flags(t_struct *csp)
{
	size_t	i;

	i = 0;
	while (csp->format_flags[i] != '\0')
	{
		while (csp->format_flags[i] == csp->srch_fmt[csp->i])
		{
			while (csp->srch_fmt[csp->i] == '-' && csp->i++)
				csp->conv_flags[0] = '-';
			while (csp->srch_fmt[csp->i] == '+' && csp->i++)
				csp->conv_flags[1] = '+';
			while (csp->srch_fmt[csp->i] == ' ' && csp->i++)
				csp->conv_flags[2] = ' ';
			while (csp->srch_fmt[csp->i] == '#' && csp->i++)
				csp->conv_flags[3] = '#';
			while (csp->srch_fmt[csp->i] == '0' && csp->i++)
				csp->conv_flags[4] = '0';
			i = 0;
		}
		i++;
	}
	return (csp);
}

t_struct	*chk_width(t_struct *csp)
{
	while (ft_isdigit(csp->srch_fmt[csp->i]))
	{
		csp->width *= 10;
		csp->width += (csp->srch_fmt[csp->i] - 48);
		csp->i++;
	}
	return (csp);
}

t_struct	*chk_precision(t_struct *csp)
{
	if (csp->srch_fmt[csp->i] == '.')
	{
		csp->precision = 0;
		csp->i++;
	}
	while (ft_isdigit(csp->srch_fmt[csp->i]))
	{
		csp->precision *= 10;
		csp->precision += (csp->srch_fmt[csp->i] - 48);
		csp->i++;
	}
	return (csp);
}

t_struct	*chk_len_flags(t_struct *csp)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (csp->l_flags[i] != '\0')
	{
		while (csp->l_flags[i] == csp->srch_fmt[csp->i])
		{
			csp->len_flags[j] = csp->srch_fmt[csp->i];
			csp->len_flags[j + 1] = '\0';
			csp->i++;
			j++;
		}
		i++;
	}
	return (csp);
}

t_struct	*chk_specifier(t_struct *csp)
{
	size_t i;

	i = 0;
	while (csp->spec_flags[i] != '\0')
	{
		if (csp->srch_fmt[csp->i] == csp->spec_flags[i])
			csp->specifier = csp->srch_fmt[csp->i];
		i++;
	}
	return (csp);
}
