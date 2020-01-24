/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:08:21 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/24 13:13:40 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_struct	*print_s(t_struct *csp)
{
	char	*tmp;
	int		s_len;
	int		padding;

	tmp = ft_strdup(va_arg(csp->args, char *));
	s_len = ft_strlen(tmp);
	padding = get_padding(csp, s_len);
	update_len(csp, padding, s_len);
	final_print(csp, padding, tmp);
	return (csp);
}
