/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:58:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/07 14:25:54 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_p(t_struct *csp)
{
	char		*tmp;
	int			s_len;
	uintmax_t	nbr;
	int			zeroes;

	zeroes = 0;
	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp = ft_itoa_base(nbr, 16);
	
	s_len = ft_strlen(tmp);
	s_len += (tmp == NULL || nbr == 0) ? 1 : 0;
	if (!csp->prec && !csp->c_flags[0] && csp->c_flags[4] == '0')
		zeroes = csp->width - s_len;
	else if (csp->prec && csp->prec > s_len && csp->c_flags[4] == '0')
		zeroes = csp->prec - s_len;
	s_len += 2;
	// printf("\nwidth:%ld", csp->width);
	// printf("\ns_len:%d\n", s_len);
	// printf("zeroes:%d\n", zeroes);
	
	if (csp->c_flags[0] != '-' && csp->c_flags[4] != '0')
	{
		// printf("\nnever findus\n");
		print_alt(csp, csp->width - s_len - zeroes, ' ');
	}
	else if (csp->c_flags[0] != '-' && csp->c_flags[4] == '0' && csp->prec > 0)
	{
		// printf("\nin here\n");
		print_alt(csp, csp->width - s_len - zeroes, ' ');
	}
	csp->specifier == 'X' ? write(1, "0X", 2) : write(1, "0x", 2);
	if (csp->c_flags[0] != '-' && csp->c_flags[4] == '0' && csp->prec == -1)
	{
		// printf("\nfindus\n");
		print_alt(csp, csp->width - s_len, '0');
	}
	print_alt(csp, zeroes, '0');
	
	ft_putstr(tmp);
	if (tmp == NULL || nbr == 0)
		print_alt(csp, (csp->prec != -1 ? csp->prec : 1), '0');
		// write(1, "0", 1);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - s_len - zeroes, ' ');
	free(tmp);
	return (csp);

}
/*
t_struct	*print_p(t_struct *csp)
{
	char		*tmp_s;
	char		*tmp_n;
	int			s_len;
	uintmax_t	nbr;

	nbr = (unsigned long)va_arg(csp->args, unsigned long int);
	nbr = (uintmax_t)nbr;
	tmp_n = ft_itoa_base(nbr, 16);
	
	// printf("tmp_n:%s:\n", tmp_n);
	tmp_s = ft_strjoin("0x", tmp_n);
	
	if (tmp_n == NULL || nbr == 0)
	{
		// printf("in here\n");
		tmp_s = ft_strjoin(tmp_s, "0");
		// write(1, "a", 1);
	}
	
	s_len = ft_strlen(tmp_s);
	// printf("slen:%d\n", s_len);
	get_padding(csp, s_len);
	csp->len += ft_strlen(tmp_s);
	align_print(csp, tmp_s, s_len);
	
	// free(tmp_s);
	free(tmp_n);
	return (csp);
}
*/
