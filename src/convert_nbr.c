/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:17:43 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/06 23:27:55 by csphilli         ###   ########.fr       */
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
		return (NULL);
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
	return (ft_revstr(str));
}