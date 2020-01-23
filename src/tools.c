/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:55:36 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/22 16:17:46 by cphillip         ###   ########.fr       */
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
	char			*str;
	char			*symbols;
	unsigned int	i;
	int				j;

	j = 0;
	symbols = "0123456789abcdef";
	if (!(str = (char *)malloc(sizeof(ft_nbr_size_base(nbr, base) * (char) + 1))))
		exit (-1);
	while (nbr != 0)
	{
		i = 0;
		while (symbols[i])
		{
			if (i == nbr % base)
			{
				str[j] = symbols[i];
				j++;
				break;
			}
			i++;
		}
		nbr /= base;
	}
	return (str);
}

char	*rev_str(char *str)
{
	char 	*tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (!(tmp = (char *)malloc(sizeof(len * (char) + 1))))
		return (NULL);
	tmp[len] = '\0';
	while (len--)
	{
		tmp[len] = str[i];
		i++;
	}
	return (tmp);

}
