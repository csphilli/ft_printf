/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:08:21 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/03 21:23:10 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_s(t_struct *csp)
{
	char	*tmp;
	int		s_len;
	int		padding;

	if (*va_arg(csp->args, char *) == '\0')
		tmp = 0;
	else
		tmp = ft_strdup(va_arg(csp->args, char *));
	s_len = tmp != 0 ? ft_strlen(tmp) : 0;
	padding = get_padding(csp, s_len);
	update_len(csp, padding, s_len);
	align_print(csp, padding, tmp);
	return (csp);
}
