/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:36:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/06 14:42:44 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



t_struct		*print_s_la_p(t_struct *csp, char *tmp, int s_len)
{
	//printf("1:\n");
	//printf("padding %d\n", padding);
	//printf("prec: %ld\n", csp->precision);
	//printf("4th:%s", tmp);
	//write(1, "A", 1);
	//printf("s_len:%d\n", s_len);

	if (csp->precision < s_len && csp->specifier == 's')
		while (csp->precision--)
			ft_putchar(*(tmp++));
	else
		while (s_len--)
			ft_putchar(*(tmp++));
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	return(csp);
}

t_struct	*print_s_ra_p(t_struct *csp, char *tmp, int s_len)
{
	
	//printf("2:\n");
	//printf("padding %d\n", padding);
	//printf("prec: %ld\n", csp->precision);
	//printf("tmp: %s", tmp);
	//write(1, "A", 1);
	//printf("test cmp: %d\n", ft_strcmp(tmp, "(null)"));
	
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	
	if (csp->precision < s_len && csp->specifier == 's')
		while (csp->precision--)
			ft_putchar(*(tmp++));
	else
		while (s_len--)
			ft_putchar(*(tmp++));
	return(csp);
}

t_struct	*print_s_la_no_p(t_struct *csp, char *tmp, int s_len)
{
	
	//printf("3:\n");
	//printf("padding %d\n", padding);
	

	while (*tmp)
		ft_putchar(*(tmp++));
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	return(csp);
}

t_struct	*print_s_ra_no_p(t_struct *csp, char *tmp, int s_len)
{
	
	//printf("4:\n");
	//printf("padding %d\n", padding);
	
	if (csp->conv_flags[4] == '0')
		print_alt(csp, csp->width - s_len, '0');
	else
		print_alt(csp, csp->width - s_len, ' ');
	ft_putstr(tmp);
	return (csp);
}

t_struct	*print_alt(t_struct *csp, int padding, int c)
{
	char *new;

	if (padding > 0)
	{
		if(!(new = ft_strnew(padding)))
			exit(-1);
		ft_memset(new, c, padding);
		write(1, new, padding);
		csp->len += padding;
		free(new);
	}
	return (csp);
}

