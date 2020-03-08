/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:19:47 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/08 20:22:09 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdint.h>



void		print_specifiers(t_struct *csp)
{
	printf("\n");
	printf("width: '%ld'\n", csp->width);
	printf("len flag[0]: '%c'\n", csp->len_flags[0]);
	printf("len flag[1]: '%c'\n", csp->len_flags[1]);
	printf("convert flag[0]: '%c'\n", csp->c_flags[0]);
	printf("convert flag[1]: '%c'\n", csp->c_flags[1]);
	printf("convert flag[2]: '%c'\n", csp->c_flags[2]);
	printf("convert flag[3]: '%c'\n", csp->c_flags[3]);
	printf("convert flag[4]: '%c'\n", csp->c_flags[4]);
	printf("precision: '%ld'\n", csp->prec);
	printf("specifier: '%c'\n", csp->specifier);
	printf("s_len: '%d'\n", csp->s_len);
}

t_struct 	*staging(t_struct *csp)
{
	char	*spec;
	
	spec = &csp->specifier;
	if (ft_strchr("cspxXdDioufF%", (int)csp->srch_fmt[csp->i]))
	{
		if (*spec == 'c')
			print_c(csp);
		else if (*spec == 's')
			print_s(csp);
		else if (*spec == 'p')
			print_p(csp);
		else if (*spec == 'x' || *spec == 'X')
			print_x(csp);
		else if (*spec == 'o')
			print_o(csp);
		else if (*spec == 'u')
			print_u(csp);
		else if (*spec == 'd' || *spec == 'i' || *spec == 'D')
			print_d(csp);
		else if (*spec == 'f' || *spec == 'F')
			print_f(csp);
		else
			print_other(csp);
	}
	return (csp);
}
