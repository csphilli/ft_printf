/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:55:36 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/22 12:51:57 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// s_len = 9;
// :%-20.25s:

int		get_padding(t_struct *csp, int s_len)
{
	int		padding;
	int		stp;

	stp = '\0';
	if (csp->precision == -1)
		stp = s_len;
	else if (csp->precision != -1 && csp->precision > s_len)
		stp = s_len;
	else if (csp->precision != -1 && csp->precision <= s_len)
		stp = csp->precision;
	if (csp->width > stp)
		padding = csp->width - stp;
	else
		padding = 0;
	return (padding);
}

int		update_len(t_struct *csp, int padding, int s_len)
{
	if (csp->width < s_len)
		csp->len += csp->width;
	else if (csp->precision != -1)
		csp->len += (csp->precision % s_len) + padding;
	else
		csp->len += s_len + padding;
	return (s_len);
}


char	*convert_nbr(long unsigned int nbr, int base)
{
	char 				*str;
	char				*symbols;
	char		res;
	int					i;
	int					mod;
	long unsigned int	tmp;
	tmp = nbr;
	symbols = "0123456789abcde";
	if (!(str = (char *)malloc(sizeof(nbr))))
		exit (-1);
	while (tmp != 0)
	{
		mod = tmp % base;
		printf("mod: %d\n", mod);
		i = 0;
		while (symbols[i])
		{
			if (i == mod)
			{
				res = symbols[i];
				break;
			}
			i++;
		}
		str = ft_strjoin(str, &res);
		printf("str: %s\n\n", str);
		//printf("symbol: %c\n", symbols[mod]);
		//printf("string: %s\n", str);
		tmp /= base;
	}
	printf("%s\n", str);
	return (0);
}

/*

char	*ft_itoa_base(int n, unsigned int base)
{
	char			*new;
	unsigned int	nbr;
	int				len;
	int				sign;

	sign = n < 0;
	len = ft_nbr_size(n);
	if (!(new = ft_strnew(len + 1)))
		return (NULL);
	nbr = n < 0 ? -n : n;
	new[len] = '\0';
	while (nbr >= base)
	{
		new[len--] = (char)(nbr % base + 48);
		nbr /= base;
	}
	new[len--] = (char)(nbr % base + 48);
	if (sign == 1)
		new[len] = '-';
	return (new);
}
*/