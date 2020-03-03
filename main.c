/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:23:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/03 12:06:27 by cphillip         ###   ########.fr       */
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
	str = "hi low  ";
	char *s_hidden;

	s_hidden = "hi low\0don't print me lol\0";

	int p_len;
	p_len = 0;

	printf("FT_PRINTF TESTING\n");
	line();
	printf("VALID STRINGS\n");
	printf("ENSURING FT_PRINTF MATCHES PRINTF\n");
	printf("FT_PRINTF IS THE FIRST OUTPUT\n");
	line();
	//setvbuf(stdout, NULL, _IONBF, 0);

//------------  START STRING TESTING (VALID PRINTF CONVERSIONS)---------------
/*
printf("[1]\n");
ft_printf("%.7s", "hello");
//write(1, "A", 1);
printf("\n");
printf("%.7s", "hello");
printf("\n\n");

printf("[2]\n");
ft_printf(":%7.7s%3.3s:", "hello", "world");
//write(1, "A", 1);
printf("\n");
printf(":%7.7s%3.3s:", "hello", "world");
printf("\n\n");

printf("[3]\n");
ft_printf("%3.3s%3.7s", "hello", "world");
//write(1, "A", 1);
printf("\n");
printf("%3.3s%3.7s", "hello", "world");
printf("\n\n");

printf("[4]\n");
ft_printf("%3.7s%3.3s", "hello", "world");
printf("\n");
printf("%3.7s%3.3s", "hello", "world");
printf("\n");

printf("[5]\n");
ft_printf("%.03s", s_hidden);
printf("\n");
printf("%.03s", s_hidden);
printf("\n");
printf("[6]\n");
ft_printf(":%6s:\n", str);
printf(":%6s:\n\n", str);
printf("[7]\n");
ft_printf(":%8s:\n", str);
printf(":%8s:\n\n", str);

printf("[no prec]\n");
ft_printf(":%1s:\n", NULL);
printf(":%1s:\n\n", NULL);

printf("[w1p1]\n");
ft_printf(":%2.1s:\n", NULL);
printf(":%2.1s:\n\n", NULL);

printf("[w1p2]\n");
ft_printf(":%3.2s:\n", NULL);
printf(":%3.2s:\n\n", NULL);

printf("[w1p3]\n");
ft_printf(":%4.3s:\n", NULL);
printf(":%4.3s:\n\n", NULL);

printf("[w1p4]\n");
ft_printf(":%5s:\n", NULL);
printf(":%5s:\n\n", NULL);

printf("[w1p5]\n");
ft_printf(":%6.5s:\n", NULL);
printf(":%6.5s:\n\n", NULL);

printf("[w1p5]\n");
ft_printf(":%6.6s:\n", NULL);
printf(":%6.6s:\n\n", NULL);

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


//----------  START STRING TESTING (IN-VALID PRINTF CONVERSIONS)---------------



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


//----------  START CHAR TESTING (VALID PRINTF CONVERSIONS)---------------


line();
printf("TESTING CHAR\n");
printf("ENSURING FT_PRINTF MATCHES PRINTF\n");
line();

char c;
c = 'a';
printf("[125]\n");
ft_printf("!%34lc!", c);
printf("\n");
printf("!%34lc!", c);
printf("\n\n");

printf("[126]\n");
ft_printf("^.^/%40lc^.^/", '`');
printf("\n");
printf("^.^/%40lc^.^/", '`');
printf("\n\n");

printf("[127]\n");
ft_printf(":testing %25c and %s:\n", c, str);
printf(":testing %25c and %s:\n\n:", c, str);

printf("[128]\n");
ft_printf(":testing %%25s and %%5c:\n", str, c);
printf(":testing %%25s and %%5c:\n\n:");

 //----------  START CHAR TESTING (IN-VALID PRINTF CONVERSIONS)---------------


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


//----------  START POINTER TESTING (VALID PRINTF CONVERSIONS)---------------

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
ft_printf(":%#017.12X:", -55432);
printf("\n");
printf(":%#017.12X:", -55432);
printf("\n\n");

printf("[138]\n");
ft_printf(":%016X:", -55432);
printf("\n");
printf(":%016X:", -55432);
printf("\n\n");

printf("[139]\n");
ft_printf("%lx %lX", 3000000000, 4000000000);
printf("\n");
printf("%lx %lX", 3000000000, 4000000000);
printf("\n\n");

printf("[140]\n");
ft_printf("24. %p %.p %.2p %.x X %.X\n", NULL, NULL, NULL, 0 , 0);
printf("\n");
//printf("24. %p %.p %.2p %.x X %.X\n", NULL, NULL, NULL, 0, 0);
printf("\n\n");


printf("[141]\n");
ft_printf("%6X %-6x %-20x %20x", -55432, -55432, -55432, -55432);
printf("\n");
printf("%6X %-6x %-20x %20x", -55432, -55432, -55432, -55432);
printf("\n\n");

printf("[7]\n");
ft_printf(":%5%:");
printf("\n");
printf(":%5%:");
printf("\n\n");

printf("[9]\n");
ft_printf(":%05%:");
printf("\n");
printf(":%05%:");
printf("\n\n");

printf("[1284]\n");
ft_printf(":%p:", NULL);
printf("\n");
printf(":%p:", NULL);
printf("\n\n");



printf("[-37.17]\n");
ft_printf(":%-37.17lx:", 522337203685470);
printf("\n");
printf(":%-37.17lx:", 522337203685470);
printf("\n\n");

printf("[1012]\n");
ft_printf(":%-5.0x:", 0);
printf("\n");
printf(":%-5.0x:", 0);
printf("\n\n");

printf("[037l]\n");
ft_printf(":%037lx:", 22337203685477ul);
printf("\n");
printf(":%037lx:", 22337203685477ul);
printf("\n\n");

printf(":-#37.10l:\n");
ft_printf(":%-#37.10lx:", 22337203685477ul);
printf("\n");
printf(":%-#37.10lx:", 22337203685477ul);
printf("\n\n");

printf("[#037.20]\n");
ft_printf(":%-7x:", 33);
printf("\n");
printf(":%-7x:", 33);
printf("\n\n");

printf("[#037.5]\n");
ft_printf(":%#037.5lx:", 22337203685477ul);
printf("\n");
printf(":%#037.5lx:", 22337203685477ul);
printf("\n\n");

ft_printf("1:%#010x:\n", 12345);
printf("1:%#010x:\n", 12345);

ft_printf("2:%-10x:\n", 12345);
printf("2:%-10x:\n", 12345);

ft_printf("3:%#015.7x:\n", 12345);
printf("3:%#015.7x:\n", 12345);

ft_printf("4:%.5x:\n", 12345);
printf("4:%.5x:\n", 12345);

ft_printf("5:%#010x:\n", 12345);
printf("5:%#010x:\n", 12345);

ft_printf("6:%10x:\n", 12345);
printf("6:%10x:\n", 12345);

ft_printf("7:%x:\n", 12345);
printf("7:%x:\n", 12345);

ft_printf("8:%#.5x:\n", 12345);
printf("8:%#.5x:\n", 12345);

ft_printf("9:%#10.5x:\n", 12345);
printf("9:%#10.5x:\n", 12345);

ft_printf("10:%#0.10x:\n", 12345);
printf("10:%#0.10x:\n", 12345);

ft_printf("11:%#014x:\n", 12345);
printf("11:%#014x:\n", 12345);

ft_printf("12:this %x number\n", 0);
printf("12:this %x number\n", 0);

ft_printf("13:this %#x number\n", 0);
printf("13:this %#x number\n", 0);

ft_printf("14:%#03x\n", 0);
printf("14:%#03x\n", 0);

ft_printf("15:%#-3x:\n", 0);
printf("15:%#-3x:\n", 0);

ft_printf("16:%#8.5x\n", 0);
printf("16:%#8.5x\n", 0);

ft_printf("17:%#-8.5x\n", 0);
printf("17:%#-8.5x\n", 0);

ft_printf("18:%#0-8.5x\n", 0);
printf("18:%#0-8.5x\n", 0);

ft_printf("19:%.0x\n", 0);
printf("19:%.0x\n", 0);
printf("------------------\n");
printf("BEGIN %%o TESTS\n");
printf("------------------\n");

ft_printf("20:%.o:\n", 12345);
printf("20:%.o:\n", 12345);

ft_printf("21:%5o:\n", 12345);
printf("21:%5o:\n", 12345);

ft_printf("22:%-5.2o:\n", 12345);
printf("22:%-5.2o:\n", 12345);

ft_printf("23:%5.10o:\n", 12345);
printf("23:%5.10o:\n", 12345);

ft_printf("24:%010.3o:\n", 12345);
printf("24:%010.3o:\n", 12345);

ft_printf("25:%-15.3o:\n", 12345);
printf("25:%-15.3o:\n", 12345);

ft_printf("26:%#2.10o:\n", 12345);
printf("26:%#2.10o:\n", 12345);

ft_printf("27:%5.0o:\n", 12345);
printf("27:%5.0o:\n", 12345);

ft_printf("28:%#5.0o:\n", 0);
printf("28:%#5.0o:\n", 0);

ft_printf("29:%#5o:\n", 0);
printf("29:%#5o:\n", 0);

ft_printf("30:%8.5o:\n", 0);
printf("30:%8.5o:\n", 0);

ft_printf("31:%llo:\n", 12345);
printf("31:%llo:\n", 12345);

ft_printf("32:%3o:\n", 0);
printf("32:%3o:\n", 0);

ft_printf("33:%03o:\n", 0);
printf("33:%03o:\n", 0);

ft_printf("34:this %o is nothing:\n", 0);
printf("34:this %o is nothing:\n", 0);

printf("------------------\n");
printf("BEGIN %%u TESTS\n");
printf("------------------\n");

ft_printf("35:%.u:\n", 12345);
printf("35:%.u:\n", 12345);

ft_printf("36:%5u:\n", 12345);
printf("36:%5u:\n", 12345);

ft_printf("37:%-5.2u:\n", 12345);
printf("37:%-5.2u:\n", 12345);

ft_printf("38:%5.10u:\n", 12345);
printf("38:%5.10u:\n", 12345);

ft_printf("39:%010.3u:\n", 12345);
printf("39:%010.3u:\n", 12345);

ft_printf("40:%-15.3u:\n", 12345);
printf("40:%-15.3u:\n", 12345);

ft_printf("41:%#2.10u:\n", 12345);
printf("41:%#2.10u:\n", 12345);

ft_printf("42:%5.0u:\n", 12345);
printf("42:%5.0u:\n", 12345);

ft_printf("43:%#5.0u:\n", 0);
printf("43:%#5.0u:\n", 0);

ft_printf("44:%5u:\n", 0);
printf("44:%5u:\n", 0);

ft_printf("45:%8.5u:\n", 0);
printf("45:%8.5u:\n", 0);

ft_printf("46:%llu:\n", 522337203685470ull);
printf("46:%llu:\n", 522337203685470ull);

ft_printf("47:%3u:\n", 0);
printf("47:%3u:\n", 0);

ft_printf("48:%03u:\n", 0);
printf("48:%03u:\n", 0);

ft_printf("49:this %u is nuthing:\n", 111);
printf("49:this %u is nuthing:\n", 111);

ft_printf("50:%llu:\n", 9223372036854775807);
printf("50:%llu:\n", 9223372036854775807);

printf("------------------\n");
printf("BEGIN %%d TESTS\n");
printf("------------------\n");

ft_printf("81:%-35ld:\n", -522337203685470);
printf("81:%-35ld:\n", -522337203685470);

ft_printf("51:%-.lld:\n", -23432445234123450);
printf("51:%-.lld:\n", -23432445234123450);

ft_printf("52:%5d:\n", 12345);
printf("52:%5d:\n", 12345);

ft_printf("53:%-5.2d:\n", 12345);
printf("53:%-5.2d:\n", 12345);

ft_printf("54:%5.10d:\n", 12345);
printf("54:%5.10d:\n", 12345);

ft_printf("55:%010.3d:\n", 12345);
printf("55:%010.3d:\n", 12345);

ft_printf("56:%-15.3d:\n", 12345);
printf("56:%-15.3d:\n", 12345);

ft_printf("57:%#2.10d:\n", 12345);
printf("57:%#2.10d:\n", 12345);

ft_printf("58:%5.0d:\n", 12345);
printf("58:%5.0d:\n", 12345);

ft_printf("59:%#5.0d:\n", 0);
printf("59:%#5.0d:\n", 0);

ft_printf("60:%5d:\n", 0);
printf("60:%5d:\n", 0);

ft_printf("61:%8.5d:\n", 0);
printf("61:%8.5d:\n", 0);

ft_printf("62:%-lld:\n", 22337203685477);
printf("62:%-lld:\n", 22337203685477);

ft_printf("63:%3d:\n", 0);
printf("63:%3d:\n", 0);

ft_printf("64:%03d:\n", 0);
printf("64:%03d:\n", 0);

ft_printf("65:this %d is nothing:\n", 111);
printf("65:this %d is nothing:\n", 111);

ft_printf("66:%lld:\n", 9223372036854775807);
printf("66:%lld:\n", 9223372036854775807);

ft_printf("67:%d:\n", -247);
printf("67:%d:\n", -247);

ft_printf("68:%+-8.5d:\n", 34);
printf("68:%+-8.5d:\n", 34);

ft_printf("69:%+3.3d:\n", 6983);
printf("69:%+3.3d:\n", 6983);

ft_printf("70:%0+-3.3d:\n", 6983);
printf("70:%0+-3.3d:\n", 6983);

ft_printf("71:%+07d:\n", 6983);
printf("71:%+07d:\n", 6983);

ft_printf("72:% .4d:\n", 6983);
printf("72:% .4d:\n", 6983);

ft_printf("73:this % d number:\n", -267);
printf("73:this % d number:\n", -267);

ft_printf("74:% d:\n", -4);
printf("74:% d:\n", -4);

ft_printf("74:%- 5d:\n", -4);
printf("74:%- 5d:\n", -4);

ft_printf("75:%+7d\n", 0);
printf("75:%+7d\n", 0);

ft_printf("76:%-5.d:\n", 0);
printf("76:%-5.d:\n", 0);

ft_printf("77:%-7d:\n", -54);
printf("77:%-7d:\n", -54);

ft_printf("78:%04d:\n", -532);
printf("78:%04d:\n", -532);

ft_printf("79:%lld:\n", -22337203685477);
printf("79:%lld:\n", -22337203685477);

ft_printf("80:%lld:\n", 9223372036854775807);
printf("80:%lld:\n", 9223372036854775807);

ft_printf("81:%+-37lld:\n", -522337203685470ll);
printf("81:%+-37lld:\n", -522337203685470ll);

ft_printf("82:%+-37lli:\n", -522337203685470ll);
printf("82:%+-37lli:\n", -522337203685470ll);
*/
printf("------------------\n");
printf("BEGIN %%f TESTS\n");
printf("------------------\n");

ft_printf("83:%-25.15f:\n", -00000123456789.0123456789);
printf("83:%-25.15f:\n", -0000123456789.0123456789);

ft_printf("84:this %.0f:\n", 4.0);
printf("84:this %.0f:\n", 4.0);

ft_printf("85:%#.0f:\n", 4.5);
printf("85:%#.0f:\n", 4.5);

ft_printf("86:%-05.0f:\n", 4.0);
printf("86:%-05.0f:\n", 4.0);

ft_printf("87:%+05.0f:\n", 4.0);
printf("87:%+05.0f:\n", 4.0);

ft_printf("88:%+-05.1f:\n", 7.3);
printf("88:%+-05.1f:\n", 7.3);

ft_printf("89:this %.0f float:\n", 1.6);
printf("89:this %.0f float:\n", 1.6);

ft_printf("90:%.0f:\n", 573.924);
printf("90:%.0f:\n", 573.924);

ft_printf("91:%05.1f:\n", -7.3);
printf("91:%05.1f:\n", -7.3);

ft_printf("92:% #-6.1f:\n", -7.3);
printf("92:% #-6.1f:\n", -7.3);

ft_printf("93:%+#-5.0f:\n", -7.3);
printf("93:%+#-5.0f:\n", -7.3);

ft_printf("94:% +5.1f:\n", -7.3);
printf("94:% +5.1f:\n", -7.3);

ft_printf("95:% 5.1f:\n", -7.3);
printf("95:% 5.1f:\n", -7.3);

ft_printf("96:%+5.1f:\n", -7.3);
printf("96:%+5.1f:\n", -7.3);

ft_printf("97:% -5.3f:\n", 7.3);
printf("97:% -5.3f:\n", 7.3);

ft_printf("98:% -05.3f:\n", 7.3);
printf("98:% -05.3f:\n", 7.3);

ft_printf("99:%- 5.0f:\n", 7.3);
printf("99:%- 5.0f:\n", 7.3);

ft_printf("100:%+ .1f:\n", 7.3);
printf("100:%+ .1f:\n", 7.3);

ft_printf("101:%+ .3f:\n", 7.3);
printf("101:%+ .3f:\n", 7.3);

ft_printf("102:% #-5.1f:\n", 7.3);
printf("102:% #-5.1f:\n", 7.3);

ft_printf("103:% #-5.0f:\n", 7.3);
printf("103:% #-5.0f:\n", 7.3);

ft_printf("104:%.20f\n", 1.025978542436587568678);
printf("104:%.20f\n", 1.025978542436587568678);

ft_printf("105:%f\n", 23.00041);
printf("105:%f\n", 23.00041);

ft_printf("106: this %X number\n", 3);
printf("106: this %X number\n", 3);

ft_printf("106: this %x number\n", 3);
printf("106: this %x number\n", 3);

ft_printf("107:%37llo:\n", 522337203685470);
printf("107:%37llo:\n", 522337203685470);

ft_printf("107:%-05:\n", 522337203685470);
printf("107:%-05:\n", 522337203685470);

}

