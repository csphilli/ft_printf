/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 09:44:30 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/07 00:47:15 by csphilli         ###   ########.fr       */
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
	int			padding;
	char		specifier;
	long int	width;
	int			s_len;
	long int	prec;
	char		len_flags[3];
	char		c_flags[6];
	char		*hex_chars;
	char		*format_flags; // (#0-+ )
	char		*a_flags;// lLh (l ll h hh L)
	char		*spec_flags; // "dif"
	char		get_plus;
	
}				t_struct;

void			print_specifiers(t_struct *csp); // remove before submitting.
long double		get_float(t_struct *csp);
intmax_t		get_d_nbr(t_struct *csp);
uintmax_t		get_oux_nbr(t_struct *csp);
t_struct		*print_s_la_p(t_struct *csp, char *tmp, int s_len);
t_struct		*print_s_ra_p(t_struct *csp, char *tmp, int s_len);
t_struct		*print_s_la_no_p(t_struct *csp, char *tmp, int s_len);
t_struct		*print_s_ra_no_p(t_struct *csp, char *tmp, int s_len);
t_struct		*print_pcent(t_struct *csp);
t_struct		*print_alt(t_struct *csp, int amount, int c);
void			print_other(t_struct *csp);
t_struct		*chk_conv_flags(t_struct *csp);
t_struct		*initialize(t_struct *csp);
t_struct		*re_init(t_struct *csp);
t_struct		*chk_width(t_struct *csp);
t_struct		*chk_precision(t_struct *csp);
t_struct		*chk_arg_flags(t_struct *csp);
t_struct		*chk_specifier(t_struct *csp);
void			staging(t_struct *csp);
t_struct		*print_c(t_struct *csp);
t_struct		*print_s(t_struct *csp);
t_struct		*print_p(t_struct *csp);
t_struct		*print_x(t_struct *csp);
t_struct		*print_o(t_struct *csp);
t_struct		*print_u(t_struct *csp);
t_struct		*print_d(t_struct *csp);
t_struct		*print_f(t_struct *csp);
t_struct		*align_print(t_struct *csp, char *str, int s_len);
t_struct		*x_padding(t_struct *csp, int m_z, int mod, uintmax_t nbr);
int				get_mz(t_struct *csp, uintmax_t nbr, int s_len, int mod);
int				ft_printf(const char *format, ...);
int				parse(t_struct *csp);
int				pre_staging(t_struct *csp);
t_struct		*get_padding(t_struct *csp, long int s_len);
int				update_len(t_struct *csp, int s_len);
char			*cvt_nbr(t_struct *csp, uintmax_t nbr, int base);
t_struct		*print_zero(t_struct *csp, char spec, uintmax_t nbr);
// void			do_x(t_struct *csp, uintmax_t nbr, int m_z, char *tmp);
int				chk_is_valid(t_struct *csp);

#endif
