/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:36:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/03 14:23:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_s_la_p(t_struct *csp, int padding, char *tmp)
{
	printf("padding %d\n", padding);
	while (csp->precision--)
		ft_putchar(*(tmp++));
	while ((padding--) > 0)
		ft_putchar(32);
}

void		print_s_ra_p(t_struct *csp, int padding, char *tmp)
{
	printf("padding %d\n", padding);
	while ((padding--) > 0)
		ft_putchar(32);
	while (csp->precision--)
		ft_putchar(*(tmp++));
}

void		print_s_la_no_p(int padding, char *tmp)
{
	printf("padding %d\n", padding);
	while (*tmp)
		ft_putchar(*(tmp++));
	while ((padding--) > 0)
		ft_putchar(32);
}

void		print_s_ra_no_p(int padding, char *tmp)
{
	printf("padding %d\n", padding);
	while ((padding--) > 0)
		ft_putchar(32);
	while (*tmp)
		ft_putchar(*(tmp++));
}
