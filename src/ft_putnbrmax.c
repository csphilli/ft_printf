/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:38:36 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/24 12:42:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbrmax(intmax_t nbr)
{
	if (nbr > 9)
		ft_putnbrmax(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}