/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:36:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/23 15:47:31 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*final_print(t_struct *csp, int padding, char *str)
{
	if (csp->conv_flags[0] == '-' && csp->precision != -1)
		print_s_la_p(csp, padding, str);
	else if (csp->conv_flags[0] == '-' && csp->precision == -1)
		print_s_la_no_p(padding, str);
	else if (csp->conv_flags[0] != '-' && csp->precision == -1)
		print_s_ra_no_p(padding, str);
	else
		print_s_ra_p(csp, padding, str);
	return (csp);
}

void	print_s_la_p(t_struct *csp, int padding, char *tmp)
{
	//printf("1\n");
	while (csp->precision--)
		ft_putchar(*(tmp++));
	while ((padding--) > 0)
		ft_putchar(' ');
}

void	print_s_ra_p(t_struct *csp, int padding, char *tmp)
{
	//printf("2\n");
	while ((padding--) > 0)
		ft_putchar(' ');
	while (csp->precision--)
		ft_putchar(*(tmp++));
}

void	print_s_la_no_p(int padding, char *tmp)
{
	//printf("3\n");
	while (*tmp)
		ft_putchar(*(tmp++));
	while ((padding--) > 0)
		ft_putchar(' ');
}

void	print_s_ra_no_p(int padding, char *tmp)
{
	//printf("4\n");
	while ((padding--) > 0)
		ft_putchar(' ');
	while (*tmp)
		ft_putchar(*(tmp++));
}
