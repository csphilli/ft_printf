/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/27 23:03:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*switch_bits(char *nbr, int size); // ADD TO FT_PRINTF.H
char	*binary_to_dec(char *nbr); // ADD TO FT_PRINTF.H
char	*dec_to_binary(int nbr, int size); // ADD TO FT_PRINTF.H

static uintmax_t	get_nbr(t_struct *csp)
{
	uintmax_t nbr;

	if (ft_strequ(csp->len_flags, "h") == 0)
		nbr = (unsigned short)va_arg(csp->args, unsigned int);
	else if (ft_strequ(csp->len_flags, "hh") == 0)
		nbr = (unsigned char)va_arg(csp->args, unsigned int);
	else if (ft_strequ(csp->len_flags, "l") == 0)
		nbr = (unsigned long)va_arg(csp->args, unsigned int);
	else if (ft_strequ(csp->len_flags, "ll") == 0)
		nbr = (unsigned long long)va_arg(csp->args, unsigned int);
	else
		nbr = (unsigned int)va_arg(csp->args, unsigned int);
	nbr = (uintmax_t)nbr;
	return (nbr);
}

t_struct	*print_xX(t_struct *csp)
{
	char		*tmp;
	//int			padding;

	int	len;
	uintmax_t nbr;


	nbr = get_nbr(csp);
	printf("sizeof nbr: %ld\n", sizeof(nbr));
	printf("sizeof unsigned short %ld\n", sizeof(unsigned short));
	printf("sizeof unsigned char %ld\n", sizeof(unsigned char));
	printf("sizeof unsigned long %ld\n", sizeof(unsigned long));
	printf("sizeof unsigned long long %ld\n", sizeof(unsigned long long));

	tmp = convert_nbr(nbr, 2);
	len = ft_strlen(tmp);
	//printf("hex:%s\n", tmp);
	printf("binary char length: %d\n", len);

	tmp = dec_to_binary(nbr, sizeof(nbr) * 2);

	printf("binary:%s\n", tmp);
	tmp = switch_bits(tmp, len);
	printf("switch:%s\n", tmp);
	//printf("printf %%lx:%lx\n", nbr);
	//tmp = binary_to_dec(tmp);
	printf("decimal: %s\n", tmp);

//00000000000000000010011101111000 -55432 into 32 bit binary
//11111111111111111101100010000111	two's compliment of that.
//converting the two's compliment to HEX is the output I want.
// convert the two's compliment back to decimal and then convert
// the decimal into hex.


	//printf("number:%ld\n", nbr);
	/*
	s_len = ft_strlen(tmp);
	padding = get_padding(csp, s_len);
	csp->len += ft_strlen(tmp);
	final_print(csp, padding, tmp);
	*/
	return (csp);
}
// This is functioning properly now
char	*binary_to_dec(char *nbr)
{
	//good to create a t_struct to house all of these variables. and then make function

	long int len;
	int pow;
	int i;
	long int res;
	long int value;
	void	*vp;
	vp = &value;
	value = 0;
	len = ft_strlen(nbr);
	pow = 0;
	len--;
	while (len >= 0)
	{
		res = 1;
		i = pow;
		if (*(nbr + len) == '1' && i != 0)
		{
			while (i <= pow && i > 0)
			{
				res *= 2;
				i--;
			}
		}
		if (*(nbr + len) == '1' && i == 0)
		{
			res *= 1;
			value += res;
		}
		pow++;
		len--;
	}
	ft_itoa(value);
	return (vp);
}

char	*switch_bits(char *nbr, int size)
{
	char	*new;
	int		counter;
	counter = 0;
	if (!(new = (char*)malloc(size + 1)))
        return (NULL);
	while (*nbr)
	{
		if (*nbr == '0')
			*(new + counter) = '1' + 0;
		else
			*(new + counter) = '0' + 0;
		counter++;
		nbr++;
	}
	*(new + counter) = '\0';
	return (new);
}

char *dec_to_binary(int nbr, int size)
{
    int i;
    int d;
    int counter;
    char *new;
    i = size - 1;
    counter = 0;

    if (!(new = (char*)malloc(size + 1)))
        return (NULL);
    while (i >= 0)
    {
        d = nbr >> i;
        if (d & 1)
            *(new + counter) = 1 + '0';
        else
            *(new + counter) = 0 + '0';
        counter++;
        i--;
    }
    *(new + counter) = '\0';
    return (new);
}
