/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:08:21 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/04 14:03:34 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strndup(char *str, size_t size);

t_struct	*print_s(t_struct *csp)
{
	//printf("into print s\n");
	char	*tmp;
	int		s_len;
	int		padding;

	tmp = va_arg(csp->args, char *);
	//printf("tmp: %s\n", tmp);

	if (csp->precision == -1 && tmp)
	{
		//printf("1\n");
		tmp = ft_strdup(tmp);
		//printf("tmp:%s\n", tmp);
	}
	else if (csp->precision == -1 && !tmp)
	{
		//printf("2\n");
		tmp = ft_strdup("(null)\0");
		//printf("tmp:%s\n", tmp);
	}
	else if (csp->precision > -1 && tmp)
	{
		//printf("3\n");
		tmp = ft_strndup(tmp, csp->precision);
		//printf("tmp:%s\n", tmp);
	}
	else if (csp->precision > -1 && !tmp)
	{
		//printf("4\n");
		tmp = ft_strndup("(null)\0", csp->precision);
		//printf("tmp:%s\n", tmp);
	}
	

	
	/*
	if (*s == '\0')
	{
		tmp = 0;
		printf("1\n");
	}
	
	else if (s == NULL)
	{
		printf("2nd if\n");
		tmp = "(null)";
		printf("2\n");
	}

	else if (!s)
	{
		tmp = "no string";
	}
	else
	{
		tmp = ft_strdup(va_arg(csp->args, char *));
		printf("3\n");
	}
	*/
	//printf("passed the if statements\n");
	s_len = ft_strlen(tmp);
	//printf("assigned a proper s_len value\n");
	//printf("s_len: %d\n", s_len);
	padding = get_padding(csp, s_len);
	//printf("padding: %d\n", padding);
	//printf("prec: %ld\n", csp->precision);
	//printf("width: %ld\n", csp->width);
	update_len(csp, padding, s_len);
	//printf("length: %d\n", csp->len);
	align_print(csp, padding, tmp);
	//free(tmp);
	return (csp);
}

char	*ft_strndup(char *str, size_t size)
{
	char	*new;
	int		i;

	i = 0;
	if(!(new = (char*)malloc(size +1)))
		return (NULL);
	while (*(str + i) && size)
	{
		*(new + i) = *(str + i);
		size--;
		i++; 
	}
	return (new);
}

