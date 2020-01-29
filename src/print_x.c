/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:49:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/29 19:10:48 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*switch_bits(char *nbr, int size); // ADD TO FT_PRINTF.H
char		*binary_to_dec(char *nbr); // ADD TO FT_PRINTF.H
char		*dec_to_binary(int nbr, int size); // ADD TO FT_PRINTF.H
char 		*twos_compliment(char *nbr, int len);
int			*dec_2_bin(uintmax_t nbr);

static uintmax_t	get_nbr(t_struct *csp)
{
	uintmax_t nbr;
	//print_specifiers(csp);
	if (ft_strcmp(csp->len_flags, "h") == 0)
	{
		nbr = (unsigned short)va_arg(csp->args, unsigned int);
		//printf("h: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "hh") == 0)
	{
		nbr = (unsigned char)va_arg(csp->args, unsigned int);
		//printf("hh: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "l") == 0)
	{
		nbr = (unsigned long)va_arg(csp->args, unsigned long int);
		//printf("l: %ld\n", nbr);
	}
	else if (ft_strcmp(csp->len_flags, "ll") == 0)
	{
		nbr = (unsigned long long)va_arg(csp->args, unsigned long long int);
		//printf("ll: %ld\n", nbr);
	}
	else
	{
		nbr = (unsigned int)va_arg(csp->args, unsigned int);
		//printf("no flag: %ld\n", nbr);
	}
	nbr = (uintmax_t)nbr;
	return (nbr);
}

t_struct	*print_x(t_struct *csp)
{
	char		*tmp;

	//int			padding;

	//int	len;
	uintmax_t nbr;
	//int *test;
	//int i;
	//i = 0;

	nbr = get_nbr(csp);
	tmp = convert_nbr(nbr, 16);
	ft_putstr(tmp);
	/*
	printf("number:\n");
	printf("%ld", nbr);
	printf("\n");
	 there are 8 bits per byte. 1 char = 1 byte. So a single char has 8 bits.
	printf("sizeof nbr: %ld\n", sizeof(nbr));
	printf("sizeof unsigned short %ld\n", sizeof(unsigned short));
	printf("sizeof unsigned char %ld\n", sizeof(unsigned char));
	printf("sizeof unsigned long %ld\n", sizeof(unsigned long));
	printf("sizeof unsigned long long %ld\n", sizeof(unsigned long long));

	//dec_2_bin(nbr);
	//printf("%ld\n", nbr);
*/
	return (csp);
}

/*
char *twos_compliment(char *nbr, int len)
{
	char *tmp;
	int i;
	i = 0;
	tmp = switch_bits(nbr, len);
	printf("s:%s\n", tmp);
	return (0);

}
*/

int *dec_2_bin(uintmax_t nbr)
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
		i--;
		printf("%d", bi_number[i]);
		if (i % 8 == 0)
			printf(" ");
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
