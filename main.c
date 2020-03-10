/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:23:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/10 14:21:24 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"


int	main()
{
	
	setvbuf(stdout, NULL, _IONBF, 0);

	char	*str;
	str = "hi low  ";
	char *s_hidden;

	s_hidden = "hi low\0don't print me lol\0";

	int p_len;
	p_len = 0;
	int mine;
	int n_mine;
	mine = 0;
	n_mine = 0;

	int		*i;
	char	*simple;

	i = 42;
	simple = "test";
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

*/


printf("------------------\n");
printf("BEGIN %%p TESTS\n");
printf("------------------\n");
char *p;
p = "";


ft_printf("133:%-25p:\n", (void *)p);
printf("133:%-25p:\n", (void *)p);

ft_printf("134:%p: :%%p: :%p:\n", -55432, 77777777777777);
printf("134:%p: :%%p: :%p:\n", -55432, 77777777777777);


ft_printf("135:%10p: :%10p: :%-10p: :%-10p:\n", -55432, -55432, -55432, -55432);
printf("135:%10p: :%10p: :%-10p: :%-10p:\n", -55432, -55432, -55432, -55432);


ft_printf("136:%#017.12p:\n", -55432);
printf("136:%#017.12p:\n", -55432);

ft_printf("137:%016p:\n", -55432);
printf("137:%016p:\n", -55432);

ft_printf("138:%p: :%p:\n", 3000000000, 4000000000);
printf("138:%p: :%p:\n", 3000000000, 4000000000);

ft_printf("139:24.: :%p: :%.p: :%.2p: :%p: :%p:\n", NULL, NULL, NULL, 0 , 0);
printf("139:24.: :%p: :%.p: :%.2p: :%p: :%p:\n", NULL, NULL, NULL, 0 , 0);

ft_printf("140:%6p: :%-6p: :%-20p: :%20p:\n", -55432, -55432, -55432, -55432);
printf("140:%6p: :%-6p: :%-20p: :%20p:\n", -55432, -55432, -55432, -55432);

ft_printf("141:%5%:\n");
printf("141:%5%:\n");

ft_printf("142:%05%:\n");
printf("142:%05%:\n");

ft_printf("143:%p:\n", NULL);
printf("143:%p:\n", NULL);

ft_printf("144:%p:\n", NULL);
printf("144:%p:\n", NULL);


ft_printf("145:%p:\n", 0);
printf("145:%p:\n", 0);

ft_printf("146:%p:\n", 0);
printf("146:%p:\n", 0);

ft_printf("147:%.p:\n", 0);
printf("147:%.p:\n", 0);

ft_printf("148:%.2p:\n", 0);
printf("148:%.2p:\n", 0);

ft_printf("149:{%5p}:\n", 0);
printf("149:{%5p}:\n", 0);

ft_printf("150:%p:\n", &i);
printf("150:%p:\n", &i);

ft_printf("151:%.17p:\n", &i);
printf("151:%.17p:\n", &i);

printf("1002:");
mine = ft_printf("%.17p", &i);
printf("\t\tmine\t:%d\n", mine);
printf("1002:");
n_mine = printf("%.17p", &i);
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1003:");
mine = ft_printf("%17p", &i);
printf("\t\tmine\t:%d\n", mine);
printf("1003:");
n_mine = printf("%17p", &i);
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1004:");
mine = ft_printf("%017p", &i);
printf("\t\tmine\t:%d\n", mine);
printf("1004:");
n_mine = printf("%017p", &i);
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1004:");
mine = ft_printf("%017.14p", &i);
printf("\t\tmine\t:%d\n", mine);
printf("1004:");
n_mine = printf("%017.14p", &i);
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1004:");
mine = ft_printf("%.0p, %.p", 0, 0);
printf("\t\tmine\t:%d\n", mine);
printf("1004:");
n_mine = printf("%.0p, %.p", 0, 0);
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1004:");
mine = ft_printf("%.p, %.0p", 0, 0);
printf("\t\tmine\t:%d\n", mine);
printf("1004:");
n_mine = printf("%.p, %.0p", 0, 0);
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1004:");
mine = ft_printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l);
printf("\t\tmine\t:%d\n", mine);
printf("1004:");
n_mine = printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l);
printf("\t\tn_mine\t:%d\n", n_mine);

/*
printf("------------------\n");
printf("BEGIN %%x TESTS\n");
printf("------------------\n");

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

ft_printf("16:%#8.5x:\n", 0);
printf("16:%#8.5x:\n", 0);

ft_printf("17:%#-8.5x:\n", 0);
printf("17:%#-8.5x:\n", 0);

ft_printf("18:%#0-8.5x:\n", 0);
printf("18:%#0-8.5x:\n", 0);

ft_printf("19:%.0x:\n", 0);
printf("19:%.0x:\n", 0);

ft_printf("20:%#-08x:\n", 42);
printf("20:%#-08x:\n", 42);


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

ft_printf("35:%-05o:\n", 2500);
printf("35:%-05o:\n", 2500);

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

ft_printf("68:%0+-8.5d:\n", 0);
printf("68:%0+-8.5d:\n", 0);

ft_printf("69:%0+3.7d:\n", -2375);
printf("69:%0+3.7d:\n", -2375);

ft_printf("70:%0+-3.3d:\n", 6983);
printf("70:%0+-3.3d:\n", 6983);

ft_printf("71:%+07d:\n", 6983);
printf("71:%+07d:\n", 6983);

ft_printf("72:% .4d:\n", 6983);
printf("72:% .4d:\n", 6983);

ft_printf("73:this % d number:\n", -267);
printf("73:this % d number:\n", -267);

ft_printf("74a:% d:\n", -4);
printf("74a:% d:\n", -4);

ft_printf("74b:%- 5d:\n", -4);
printf("74b:%- 5d:\n", -4);

ft_printf("75:%+7d:\n", 0);
printf("75:%+7d:\n", 0);

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

ft_printf("82a:%-05d:\n", 42);
printf("82a:%-05d:\n", 42);

ft_printf("83:%0+3.7d:\n", 3267);
printf("83:%0+3.7d:\n", 3267);

ft_printf("84:%08.3d:\n", 3267);
printf("84:%08.3d:\n", 3267);

ft_printf("85:% 0+8.5d:\n", 34);
printf("85:% 0+8.5d:\n", 34);

ft_printf("86:% 05d:\n", 43);
printf("86:% 05d:\n", 43);

ft_printf("87:% 07d:\n", -43);
printf("87:% 07d:\n", -43);

ft_printf("88:% +05d:\n", 432);
printf("88:% +05d:\n", 432);

ft_printf("89:% +04d:\n", 0);
printf("89:% +04d:\n", 0);

ft_printf("90:%lld:\n", -9223372036854775808);
printf("90:%lld:\n", -9223372036854775808);


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
printf("\n");

ft_printf("106: this %x number\n", 3);
printf("106: this %x number\n", 3);

ft_printf("107:%37llo:\n", 522337203685470);
printf("107:%37llo:\n", 522337203685470);

printf("------------------\n");
printf("LEAK TESTING\n");
printf("------------------\n");

ft_printf("%c\n", 'c'); // no leaks
ft_printf("%s\n", "Hello"); // no leaks
ft_printf("%p\n", 111); // no leak
ft_printf("%i\n", 222); // no leak
ft_printf("%d\n", 333); // no leak
ft_printf("%o\n", 444); // no leak
ft_printf("%u\n", 555); // no leak
ft_printf("%x\n", 666); // no leak
ft_printf("%X\n", 777); // no leaks
ft_printf("%i\n", 888); // no leak
ft_printf("%f\n", 999.999);// no leak
ft_printf("%F\n", 100.000); // no leak

ft_printf(":%p:\n", NULL); // leaks
ft_printf("%p\n", NULL);
ft_printf("%.p\n", NULL);
ft_printf("%.2p\n", NULL);

ft_printf(":%x:\n", NULL); // leaks
ft_printf("%x\n", NULL);
ft_printf("%.x\n", NULL);
ft_printf("%.2x\n", NULL);

ft_printf(":%X:\n", NULL); // leaks
ft_printf("%X\n", NULL);
ft_printf("%.X\n", NULL);
ft_printf("%.2X\n", NULL);


printf("------------------\n");
printf("LEN TESTING\n");
printf("------------------\n");



mine = ft_printf("%x", 42);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%x", 42);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%x", 0);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%x", 0);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%X", 0);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%X", 0);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%hx", 4294967296);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%hx", 4294967296);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%010x", 542);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%010x", 542);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%#llx", 9223372036854775807);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%#llx", 9223372036854775807);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%#-08x", 42);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%#-08x", 42);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%s  ", "this is a string");
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%s  ", "this is a string");
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf(":%5c:", 42);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf(":%5c:", 42);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("@moulitest: %c", 0);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("@moulitest: %c", 0);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("null %c and text", 0);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("null %c and text", 0);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("05o", 42);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("05o", 42);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%-5.10o", 2500);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%-5.10o", 2500);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("@moulitest: %.10o", 42);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("@moulitest: %.10o", 42);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("@moulitest: %o", 0);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("@moulitest: %o", 0);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%d", 2147483648);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%d", 2147483648);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("% d", 42);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("% d", 42);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%   +d", -42);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%   +d", -42);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%#6o", 2500);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%#6o", 2500);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%-#6o", 2500);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%-#6o", 2500);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%lld", -9223372036854775808);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%lld", -9223372036854775808);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%p", 0);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%p", 0);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("{%5p}", 0);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("{%5p}", 0);
printf("\t\tn_mine\t:%d\n", n_mine);

mine = ft_printf("%.0p", 0);
printf("\t\tmine\t:%d\n", mine);
n_mine = printf("%.0p", 0);
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1000:");
mine = ft_printf(":%p:", &i);
printf("\t\tmine\t:%d\n", mine);
printf("1000:");
n_mine = printf(":%p:", &i);
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1001:");
mine = ft_printf("%s", "a string");
printf("\t\tmine\t:%d\n", mine);
printf("1001:");
n_mine = printf("%s", "a string");
printf("\t\tn_mine\t:%d\n", n_mine);

printf("1002:");
mine = ft_printf("%p", &i);
printf("\t\tmine\t:%d\n", mine);
printf("1002:");
n_mine = printf("%p", &i);
printf("\t\tn_mine\t:%d\n", n_mine);
*/
while (1)
{
	
}
}
