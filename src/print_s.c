/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:08:21 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/05 16:43:13 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// i think i need to update the length first and then pass that to padding function.


char	*ft_strndup(char *str, int size);

t_struct	*print_s(t_struct *csp)
{
	//printf("into print s\n");
	char	*tmp;
	int		s_len;
	int		padding;

	tmp = va_arg(csp->args, char *);
	//printf("tmp1st:%s", tmp);
	//write(1, "A:", 2);
	//printf("\n");
	s_len = tmp == NULL ? 0 : ft_strlen(tmp);
	
	if (csp->precision == -1 && tmp)
	{
		//printf("First\n");
		tmp = ft_strdup(tmp);
		//printf("tmp:%s\n", tmp);
	}
	else if (csp->precision == -1 && !tmp)
	{
		//printf("Second\n");
		tmp = ft_strdup("(null)");
		//printf("tmp:%s\n", tmp);
	}
	else if (csp->precision > -1 && tmp)
	{
		//printf("Third\n");
		//printf("tmp before:%s", tmp);
		//write(1, "A:\n", 3);
		tmp = ft_strndup(tmp, s_len);
		//printf("tmp:%s\n", tmp);
	}
	else if (csp->precision > -1 && !tmp)
	{
		//printf("Fourth\n");
		tmp = ft_strndup("(null)", 6);
		//printf("tmp:%s\n", tmp);
	}

	//printf("tmp2nd:%s", tmp);
	//write(1, "A:", 2);
	//printf("\n");
	
	s_len = ft_strlen(tmp);
	//printf("ft_strlen:%d\n", s_len);
	s_len = update_len(csp, s_len);
	//printf("s_len: %d\n", s_len);
	padding = get_padding(csp, s_len);
	//printf("padding: %d\n", padding);
	//printf("prec: %ld\n", csp->precision);
	//printf("width: %ld\n", csp->width);

	//printf("length: %d\n", csp->len);
	align_print(csp, padding, tmp, s_len);
	free(tmp);
	return (csp);
}

char	*ft_strndup(char *str, int size)
{
	char	*new;
	int		i;
	
	i = 0;
	if(!(new = ft_strnew(size)))
		return (NULL);
	while (str && i <= size)
	{		
		new[i] = str[i];
		i++;
	}
	return (new);
}

