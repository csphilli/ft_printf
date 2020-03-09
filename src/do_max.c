/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:13:08 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/09 21:26:54 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**  In the event a max number is passed, this prints it out. The sign
**  is handled in the respective function. In this case, it's only print_d.c
*/

void    do_max()
{
    write(1, "9223372036854775808", 19);
}
