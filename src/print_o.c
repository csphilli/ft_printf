/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 10:15:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/09 13:59:31 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_o_zero(t_struct *csp, uintmax_t nbr)
{
	if (csp->c_flags[3] == '#' && nbr)
		write(1, "0", 1);
		// print_alt(csp, 1, '0');
	// else if (nbr == 0)
	// 	print_alt(csp, 1, '0');
}

static int		collect_o(t_struct *csp, uintmax_t nbr)
{
	int n_blank;

	if (csp->c_flags[3] == '#' && nbr)
		csp->s_len++;	
	n_blank = csp->s_len;
	if (csp->c_flags[4] == '0' && csp->prec == -1 && csp->c_flags[0] != '-')
	{
		// printf("prec1\n");
		csp->prec = csp->width;
	}
	else if (csp->c_flags[0] == '-' && csp->c_flags[4] == '0' && csp->prec == -1)
	{
		// printf("prec2\n");
		csp->prec = csp->s_len;
	}
	if (csp->s_len <= csp->prec && csp->prec > 0)
		n_blank = csp->prec;
	nbr += 0;
	return (n_blank);
}

t_struct			*print_o(t_struct *csp)
{
	char		*tmp;
	uintmax_t	nbr;
	int			n_blank;

	nbr = get_oux_nbr(csp);	
	if (nbr == 0 && csp->prec == 0 && csp->c_flags[3] != '#')
	{
		print_alt(csp, csp->width, ' ');
		return (csp);
	}
	tmp = nbr == 0 ? ft_strdup("0") : ft_itoa_base(nbr, 8);
	// printf("\ntmp:%s:\n", tmp);
	csp->s_len = nbr == 0 ? 1 : ft_strlen(tmp);
	// printf("csp->len ONE:%d\n", csp->len);
	// printf("csp->s_len ONE:%d\n", csp->s_len);
	n_blank = collect_o(csp, nbr);
	if (csp->c_flags[0] != '-')
		print_alt(csp, csp->width - n_blank, ' ');
	print_o_zero(csp, nbr);
	// printf("\ncsp->len TWO:%d\n", csp->len);
	// printf("csp->s_len TWO:%d\n", csp->s_len);
	// printf("prec:%ld\n", csp->prec);
	print_alt(csp, csp->prec - csp->s_len, '0');
	ft_putstr(tmp);
	if (csp->c_flags[0] == '-')
		print_alt(csp, csp->width - n_blank, ' ');
	// printf("\ncsp->len THREE:%d\n", csp->len);
	// printf("csp->s_len THREE:%d\n", csp->s_len);
	csp->len += csp->s_len;
	free(tmp);
	return (csp);
}