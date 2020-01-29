/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/29 15:55:03 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*switch_bits(char *nbr, int size); // ADD TO FT_PRINTF.H
char	*binary_to_dec(char *nbr); // ADD TO FT_PRINTF.H
char	*dec_to_binary(int nbr, int size); // ADD TO FT_PRINTF.H
char 	*twos_compliment(char *nbr, int len);
int 	*dec_2_bin(int nbr);

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
	//char		*tmp;

	//int			padding;

	//int	len;
	uintmax_t nbr;
	int *test;
	int i;
	i = 0;

	nbr = get_nbr(csp);
	// there are 8 bits per byte. 1 char = 1 byte. So a single char has 8 bits.
	printf("sizeof nbr: %ld\n", sizeof(nbr));
	printf("sizeof unsigned short %ld\n", sizeof(unsigned short));
	printf("sizeof unsigned char %ld\n", sizeof(unsigned char));
	printf("sizeof unsigned long %ld\n", sizeof(unsigned long));
	printf("sizeof unsigned long long %ld\n", sizeof(unsigned long long));

	test = dec_2_bin(nbr);
	
	
	//len = ft_strlen(tmp);
	//tmp = binary_to_dec(test);
	

	//tmp = dec_to_binary(nbr, sizeof(nbr));

	//printf("b:%s\n", tmp);
	//tmp = twos_compliment(tmp, len);

	//tmp = switch_bits(tmp, len);
	//printf("s:%s\n", tmp);
	//printf("printf %%lx:%lx\n", nbr);
	//tmp = binary_to_dec(tmp);
	//printf("decimal: %s\n", tmp);
	//printf("size of tmp: %s\n", tmp);

//0000 0000 0000 0000 0010 0111 0111 1000 -55432 into 32 bit binary
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

char *twos_compliment(char *nbr, int len)
{
	char *tmp;
	int i;
	i = 0;
	tmp = switch_bits(nbr, len);
	printf("s:%s\n", tmp);
	return (0);

}
// issue on return.
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
	//printf("%ld\n", value);
	return (vp);
}

int *dec_2_bin(int nbr)
{
	static int bi_number[32];
	int i;
	i = 0;

	while (nbr > 0)
	{
		bi_number[i] = nbr % 2;
		nbr /= 2;
		i++;
	}
	while (i > 0)
	{
		printf("%d", bi_number[i]);
		if (i % 8 == 0)
			printf(" ");
		i--;
	}
	return (bi_number);
}

char	*switch_bits(char *nbr, int size)
{
	//printf("test in bits\n");
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
