/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:17:43 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/12 15:40:51 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*cvt_nbr(t_struct *csp, uintmax_t nbr, int base)
{
	char			*str;
	unsigned int	i;
	int				j;

	j = 0;
	if (!(str = (char*)malloc(sizeof(ft_nbr_size_base(nbr, base) * (char)+1))))
		exit(-1);
	//printf("s_len:%zu\n", ft_strlen(str));
	while (nbr != 0)
	{
		i = 0;
		while (csp->hex_chars[i])
		{
			if (i == nbr % base)
			{
				str[j] = csp->hex_chars[i];
				j++;
				break ;
			}
			i++;
		}
		nbr /= base;
	}
	str[j] = '\0';
	printf("	str: %s\n", str);
	printf("rev str: %s\n", ft_revstr(str));
	return (ft_revstr(str));
}
