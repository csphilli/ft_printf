/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:23:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/02/03 16:40:04 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"


void	line()
{
	int nbr;
	nbr = 40;
	char dash;
	dash = '-';
	while (nbr--)
		printf("%c", dash);
	printf("\n");
}

int	main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	char	*str;
	str = "HelloHell";
	printf("FT_PRINTF TESTING\n");
	line();
	printf("VALID STRINGS\n");
	printf("ENSURING FT_PRINTF MATCHES PRINTF\n");
	printf("FT_PRINTF IS THE FIRST OUTPUT\n");
	line();
	setvbuf(stdout, NULL, _IONBF, 0);
/*
** ------------  START STRING TESTING (VALID PRINTF CONVERSIONS)---------------
*/
printf("[1]\n");
ft_printf("%-10.8s", str);
printf("%-10.8s", str);
printf("[2]\n");
ft_printf(":%-14.5s :\n", str);
printf(":%-14.5s :\n\n", str);
printf("[3]\n");
ft_printf(":%-4.24s:\n", str);
printf(":%-4.24s:\n\n", str);
printf("[4]\n");
ft_printf(":%s:\n", str);
printf(":%s:\n\n", str);
printf("[5]\n");
ft_printf(":%8.5s:\n", str);
printf(":%8.5s:\n\n", str);
printf("[6]\n");
ft_printf(":%6s:\n", str);
printf(":%6s:\n\n", str);
printf("[7]\n");
ft_printf(":%8s:\n", str);
printf(":%8s:\n\n", str);
printf("[8]\n");
ft_printf(":%1.5s:\n", str);
printf(":%1.5s:\n\n", str);
printf("[9]\n");
ft_printf(":%8.2s:\n", str);
printf(":%8.2s:\n\n", str);
printf("[10]\n");
ft_printf(":%-1s:\n", str);
printf(":%-1s:\n\n", str);
printf("[11]\n");
ft_printf(":%-.4s:\n", str);
printf(":%-.4s:\n\n", str);
printf("[12]\n");
ft_printf(":%6s:\n", str);
printf(":%6s:\n\n", str);
printf("[13]\n");
ft_printf(":%-2s:\n", str);
printf(":%-2s:\n\n", str);
printf("[14]\n");
ft_printf(":%-.5s:\n", str);
printf(":%-.5s:\n\n", str);
printf("[15]\n");
ft_printf(":%-5.0s:\n", str);
printf(":%-5.0s:\n\n", str);
printf("[16]\n");
ft_printf(":%6.0s:\n", str);
printf(":%6.0s:\n\n", str);
printf("[17]\n");
ft_printf(":%6.7s:\n", str);
printf(":%6.7s:\n\n", str);
printf("[18]\n");
ft_printf(":%6.8s:\n", str);
printf(":%6.8s:\n\n", str);
printf("[19]\n");
ft_printf(":%3.1s:\n", str);
printf(":%3.1s:\n\n", str);
printf("[20]\n");
ft_printf(":%-2s:\n", str);
printf(":%-2s:\n\n", str);
printf("[21]\n");
ft_printf(":%-3s:\n", str);
printf(":%-3s:\n\n", str);
printf("[22]\n");
ft_printf(":%-7.2s:\n", str);
printf(":%-7.2s:\n\n", str);
printf("[23]\n");
ft_printf(":%-2.0s:\n", str);
printf(":%-2.0s:\n\n", str);
printf("[24]\n");
ft_printf(":%7.2s:\n", str);
printf(":%7.2s:\n\n", str);
printf("[25]\n");
ft_printf(":%5.6s:\n", str);
printf(":%5.6s:\n\n", str);
printf("[26]\n");
ft_printf(":%6s:\n", str);
printf(":%6s:\n\n", str);
printf("[27]\n");
ft_printf(":%3s:\n", str);
printf(":%3s:\n\n", str);
printf("[28]\n");
ft_printf(":%6s:\n", str);
printf(":%6s:\n\n", str);
printf("[29]\n");
ft_printf(":%-5.3s:\n", str);
printf(":%-5.3s:\n\n", str);
printf("[30]\n");
ft_printf(":%-1s:\n", str);
printf(":%-1s:\n\n", str);
printf("[31]\n");
ft_printf(":%8.5s:\n", str);
printf(":%8.5s:\n\n", str);
printf("[32]\n");
ft_printf(":%7.3s:\n", str);
printf(":%7.3s:\n\n", str);
printf("[33]\n");
ft_printf(":%7s:\n", str);
printf(":%7s:\n\n", str);
printf("[34]\n");
ft_printf(":%1s:\n", str);
printf(":%1s:\n\n", str);
printf("[35]\n");
ft_printf(":%-8.5s:\n", str);
printf(":%-8.5s:\n\n", str);
printf("[36]\n");
ft_printf(":%-5.3s:\n", str);
printf(":%-5.3s:\n\n", str);
printf("[37]\n");
ft_printf(":%-6s:\n", str);
printf(":%-6s:\n\n", str);
printf("[38]\n");
ft_printf(":%-5.5s:\n", str);
printf(":%-5.5s:\n\n", str);
printf("[39]\n");
ft_printf(":%1s:\n", str);
printf(":%1s:\n\n", str);
printf("[40]\n");
ft_printf(":%-3s:\n", str);
printf(":%-3s:\n\n", str);
printf("[41]\n");
ft_printf(":%5.2s:\n", str);
printf(":%5.2s:\n\n", str);
printf("[42]\n");
ft_printf(":%8.3s:\n", str);
printf(":%8.3s:\n\n", str);
printf("[43]\n");
ft_printf(":%8.8s:\n", str);
printf(":%8.8s:\n\n", str);
printf("[44]\n");
ft_printf(":%1s:\n", str);
printf(":%1s:\n\n", str);
printf("[45]\n");
ft_printf(":%5.6s:\n", str);
printf(":%5.6s:\n\n", str);
printf("[46]\n");
ft_printf(":%-1.7s:\n", str);
printf(":%-1.7s:\n\n", str);
printf("[47]\n");
ft_printf(":%-3s:\n", str);
printf(":%-3s:\n\n", str);
printf("[48]\n");
ft_printf(":%-2.1s:\n", str);
printf(":%-2.1s:\n\n", str);
printf("[49]\n");
ft_printf(":%2s:\n", str);
printf(":%2s:\n\n", str);
printf("[50]\n");
ft_printf(":%-4.3s:\n", str);
printf(":%-4.3s:\n\n", str);
printf("[51]\n");
ft_printf(":%20.1s:\n", str);
printf(":%20.1s:\n\n", str);
printf("[52]\n");
ft_printf(":%3s:\n", str);
printf(":%3s:\n\n", str);
printf("[53]\n");
ft_printf(":%22s:\n", str);
printf(":%22s:\n\n", str);
printf("[54]\n");
ft_printf(":%-2.5s:\n", str);
printf(":%-2.5s:\n\n", str);
printf("[55]\n");
ft_printf(":%-10.20s:\n", str);
printf(":%-10.20s:\n\n", str);
printf("[56]\n");
ft_printf(":%-22s:\n", str);
printf(":%-22s:\n\n", str);
printf("[57]\n");
ft_printf(":%9.8s:\n", str);
printf(":%9.8s:\n\n", str);
printf("[58]\n");
ft_printf(":%-22s:\n", str);
printf(":%-22s:\n\n", str);
printf("[59]\n");
ft_printf(":%-10.6s:\n", str);
printf(":%-10.6s:\n\n", str);
printf("[60]\n");
ft_printf(":%-22s:\n", str);
printf(":%-22s:\n\n", str);
printf("[61]\n");
ft_printf(":%14.21s:\n", str);
printf(":%14.21s:\n\n", str);
printf("[62]\n");
ft_printf(":%-2.17s:\n", str);
printf(":%-2.17s:\n\n", str);
printf("[63]\n");
ft_printf(":%16.13s:\n", str);
printf(":%16.13s:\n\n", str);
printf("[64]\n");
ft_printf(":%-21.23s:\n", str);
printf(":%-21.23s:\n\n", str);
printf("[65]\n");
ft_printf(":%13s:\n", str);
printf(":%13s:\n\n", str);
printf("[66]\n");
ft_printf(":%7.7s:\n", str);
printf(":%7.7s:\n\n", str);
printf("[67]\n");
ft_printf(":%-25s:\n", str);
printf(":%-25s:\n\n", str);
printf("[68]\n");
ft_printf(":%-7.13s:\n", str);
printf(":%-7.13s:\n\n", str);
printf("[69]\n");
ft_printf(":%10s:\n", str);
printf(":%10s:\n\n", str);
printf("[70]\n");
ft_printf(":%-s:\n", str);
printf(":%-s:\n\n", str);
printf("[71]\n");
ft_printf(":%-10.6s:\n", str);
printf(":%-10.6s:\n\n", str);
printf("[72]\n");
ft_printf(":%-25s:\n", str);
printf(":%-25s:\n\n", str);
printf("[73]\n");
ft_printf(":%14s:\n", str);
printf(":%14s:\n\n", str);
printf("[74]\n");
ft_printf(":%-10.8s:\n", str);
printf(":%-10.8s:\n\n", str);

/*
** ------------  START STRING TESTING (IN-VALID PRINTF CONVERSIONS)---------------
*/


	line();
	printf("INVALID PRINTF STRINGS\n");
	printf("CHECKING TO SEE IF PROGRAM QUITS\n");
	line();


setvbuf(stdout, NULL, _IONBF, 0);
printf("[75]\n");
ft_printf(":%020s:\n\n", str);
printf("[76]\n");
ft_printf(":%04.1s:\n\n", str);
printf("[77]\n");
ft_printf(":%#7.18s:\n\n", str);
printf("[78]\n");
ft_printf(":%03.11s:\n\n", str);
printf("[79]\n");
ft_printf(":%+3s:\n\n", str);
printf("[80]\n");
ft_printf(":%-16.13s:\n\n", str);
printf("[81]\n");
ft_printf(":%-25s:\n\n", str);
printf("[82]\n");
ft_printf(":%018s:\n\n", str);
printf("[83]\n");
ft_printf(":%-22s:\n\n", str);
printf("[84]\n");
ft_printf(":%07s:\n\n", str);
printf("[85]\n");
ft_printf(":%019.14s:\n\n", str);
printf("[86]\n");
ft_printf(":%-23.15s:\n\n", str);
printf("[87]\n");
ft_printf(":%024.23s:\n\n", str);
printf("[88]\n");
ft_printf(":%#18.2s:\n\n", str);
printf("[89]\n");
ft_printf(":%+3.22s:\n\n", str);
printf("[90]\n");
ft_printf(":%-25s:\n\n", str);
printf("[91]\n");
ft_printf(":%011.10s:\n\n", str);
printf("[92]\n");
ft_printf(":%+17s:\n\n", str);
printf("[93]\n");
ft_printf(":%+20s:\n\n", str);
printf("[94]\n");
ft_printf(":%07s:\n\n", str);
printf("[95]\n");
ft_printf(":%-11.20s:\n\n", str);
printf("[96]\n");
ft_printf(":%013s:\n\n", str);
printf("[97]\n");
ft_printf(":%#17s:\n\n", str);
printf("[98]\n");
ft_printf(":%-17s:\n\n", str);
printf("[99]\n");
ft_printf(":%+.24s:\n\n", str);
printf("[100]\n");
ft_printf(":%#22.9s:\n\n", str);
printf("[101]\n");
ft_printf(":%#5s:\n\n", str);
printf("[102]\n");
ft_printf(":%020.2s:\n\n", str);
printf("[103]\n");
ft_printf(":%+23s:\n\n", str);
printf("[104]\n");
ft_printf(":%-20s:\n\n", str);
printf("[105]\n");
ft_printf(":%+21s:\n\n", str);
printf("[106]\n");
ft_printf(":%-s:\n\n", str);
printf("[107]\n");
ft_printf(":%-15s:\n\n", str);
printf("[108]\n");
ft_printf(":%+23s:\n\n", str);
printf("[109]\n");
ft_printf(":%-7.16s:\n\n", str);
printf("[110]\n");
ft_printf(":%#22s:\n\n", str);
printf("[111]\n");
ft_printf(":%#19s:\n\n", str);
printf("[112]\n");
ft_printf(":%#9s:\n\n", str);
printf("[113]\n");
ft_printf(":%+14.7s:\n\n", str);
printf("[114]\n");
ft_printf(":%-20.24s:\n\n", str);
printf("[115]\n");
ft_printf(":%04.8s:\n\n", str);
printf("[116]\n");
ft_printf(":%-3s:\n\n", str);
printf("[117]\n");
ft_printf(":%+21.7s:\n\n", str);
printf("[118]\n");
ft_printf(":%-3s:\n\n", str);
printf("[119]\n");
ft_printf(":%+10.13s:\n\n", str);
printf("[120]\n");
ft_printf(":%-22s:\n\n", str);
printf("[121]\n");
ft_printf(":%-12.17s:\n\n", str);
printf("[122]\n");
ft_printf(":%-16s:\n\n", str);
printf("[123]\n");
ft_printf(":%#24.6s:\n\n", str);
printf("[124]\n");
ft_printf("0\n", str);

/*
** ------------  START CHAR TESTING (VALID PRINTF CONVERSIONS)---------------
*/

line();
printf("TESTING CHAR\n");
printf("ENSURING FT_PRINTF MATCHES PRINTF\n");
line();

char c;
c = 'a';
printf("[125]\n");
ft_printf(":testing %3c:\n", c);
printf(":testing %3c:\n\n:", c);

printf("[126]\n");
ft_printf(":testing %-3c and %s:\n", c, str);
printf(":testing %-3c and %s:\n\n:", c, str);

printf("[127]\n");
ft_printf(":testing %25c and %s:\n", c, str);
printf(":testing %25c and %s:\n\n:", c, str);

printf("[128]\n");
ft_printf(":testing %%25s and %%5c:\n", str, c);
printf(":testing %%25s and %%5c:\n\n:");

/*
** ------------  START CHAR TESTING (IN-VALID PRINTF CONVERSIONS)---------------
*/

line();
printf("TESTING INVALID CHAR MODIFIERS\n");
printf("CHECKING TO SEE IF PROGRAM QUITS\n");
line();

printf("[129]\n");
ft_printf(":testing %#3c:\n\n", c);

printf("[130]\n");
ft_printf(":testing %0-3c and %s:\n\n", c, str);

printf("[131]\n");
ft_printf(":testing %##25c and %s:\n\n", c, str);

printf("[132]\n");
ft_printf(":testing %-25s and %0#-5.5c:\n\n", str, c);

/*
** ------------  START POINTER TESTING (VALID PRINTF CONVERSIONS)---------------
*/
line();
printf("TESTING POINTERS\n");
printf("ENSURING FT_PRINTF MATCHES PRINTF\n");
line();

char *p;
p = "";

printf("[133]\n");
ft_printf(":%-25p:\n", (void *)p);
printf(":%-25p:\n\n", (void *)p);


printf("[134]\n");
ft_printf("%X, %%x, %lx", -55432, 77777777777777);
printf("\n");
printf("%X, %%x, %lx", -55432, 77777777777777);
printf("\n\n");

printf("[135]\n");
ft_printf("%10x, %10X, %-10x, %-10X", -55432, -55432, -55432, -55432);
printf("\n");
printf("%10x, %10X, %-10x, %-10X", -55432, -55432, -55432, -55432);
printf("\n\n");

printf("[136]\n");
ft_printf(":%10.5x:, :%#017X:, :%#-10X:, :%#20X:", -55432, -55432, -55432, -55432);
printf("\n");
printf(":%10.5x:, :%#017X:, :%#-10X:, :%#20X:", -55432, -55432, -55432, -55432);
printf("\n\n");

printf("[137]\n");
ft_printf("%#16X", -55432);
printf("\n");
printf("%#16X", -55432);
printf("\n\n");

printf("[138]\n");
ft_printf("%#016X", -55432);
printf("\n");
printf("%#016X", -55432);
printf("\n\n");
//printf("final: %d\n", t);
/*
printf("1 . %c %s %p %0x %%\n", 'a', "Hello!", "~", -55432);
printf("1 . %c %s %p %#0x %%\n", 'a', "Hello!", "~", -55432);
printf("1 . %c %s %p %5.10x %%\n", 'a', "Hello!", "~", -55432);
printf("1 . %c %s %p %#5.30x %%\n", 'a', "Hello!", "~", -55432);
printf("1 . %c %s %p %hhx %%\n", 'a', "Hello!", "~", -55432);
printf("1 . %c %s %p %hx %%\n", 'a', "Hello!", "~", -55432);
printf("1 . %c %s %p %hhx sizeof:%d %%\n", 'a', "Hello!", "~", -55432, -55432);
*/


}

