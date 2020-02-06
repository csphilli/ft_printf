/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 09:44:30 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/06 13:26:43 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <ctype.h>
# include <stdarg.h>
# include <stdio.h> // REMOVE BEFORE SUBMISSION
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <wchar.h>

typedef struct	s_struct
{
	const char	*fmt;
	char		*c_fmt;
	char		*srch_fmt;
	va_list		args;
	size_t		i;
	int			len;
	char		specifier;
	long int	width;
	long int	precision;
	char		len_flags[2];
	char		conv_flags[6];
	char		*format_flags; // (#0-+ )
	char		*a_flags;// lLh (l ll h hh L)
	char		*spec_flags; // "cspdiouxXf%"
}				t_struct;

void			print_specifiers(t_struct *csp); // remove before submitting.
t_struct		*print_s_la_p(t_struct *csp, int padding, char *tmp, int s_len);
t_struct		*print_s_ra_p(t_struct *csp, int padding, char *tmp, int s_len);
t_struct		*print_s_la_no_p(t_struct *csp, int padding, char *tmp, int s_len);
t_struct		*print_s_ra_no_p(t_struct *csp, int padding, char *tmp, int s_len);
void			print_alt(int padding, int c);
void			print_other(t_struct *csp);
t_struct		*chk_conv_flags(t_struct *csp);
t_struct		*initialize(t_struct *csp);
t_struct		*re_init(t_struct *csp);
t_struct		*chk_width(t_struct *csp);
t_struct		*chk_precision(t_struct *csp);
t_struct		*chk_arg_flags(t_struct *csp);
t_struct		*chk_specifier(t_struct *csp);
t_struct		*staging(t_struct *csp);
t_struct		*print_c(t_struct *csp);
t_struct		*print_s(t_struct *csp);
t_struct		*print_p(t_struct *csp);
t_struct		*print_x(t_struct *csp);
t_struct		*align_print(t_struct *csp, int padding, char *str, int s_len);
int				ft_printf(const char *format, ...);
int				parse(t_struct *csp);
int				pre_staging(t_struct *csp);
int				get_padding(t_struct *csp, long int s_len);
int				update_len(t_struct *csp, int s_len);
char			*convert_nbr(long long unsigned int nbr, int base);

#endif
