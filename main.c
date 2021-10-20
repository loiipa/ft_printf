/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:45:49 by cjang             #+#    #+#             */
/*   Updated: 2021/06/16 15:36:54 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <locale.h>

#define DBL_INF    0x7FF0000000000000
#define DBL_NINF   0xFFF0000000000000
#define DBL_NAN    0x7FF0000000100000
#define DBL_PZERO  0x0000000000000000
#define DBL_NZERO  0x8000000000000000

int	test_func_e(double e);

static void about_c(void)
{
	//setbuf(stdout, NULL);
	setlocale(LC_ALL, "en_US.UTF-8");
	ft_printf("%lc", L'😀');
	int c = L'흙';
	printf("<about c>\n\n");

	printf("p_%%c		'%c'\n", 0);
	ft_printf("f_%%c		'%c'\n\n", 0);

	printf("p_%%-c	'%-c'\n", c);
	ft_printf("f_%%-c	'%-c'\n\n", c);

	printf("p_%%-3c	'%-3c'\n", c);
	ft_printf("f_%%-3c	'%-3c'\n\n", c);

	printf("p_%%0c	'%0c'\n", c);
	ft_printf("f_%%0c	'%0c'\n\n", c);

	printf("p_%%5c	'%5c'\n", c);
	ft_printf("f_%%5c	'%5c'\n\n", c);

	printf("p_%%.3c	'%.3c'\n", c);
	ft_printf("f_%%.3c	'%.3c'\n\n", c);

	printf("p_%%#c	'%#c'\n", c);
	ft_printf("f_%%#c	'%#c'\n\n", c);

	printf("p_%% c	'% c'\n", c);
	ft_printf("f_%% c	'% c'\n\n", c);

	printf("p_%%+c	'%+c'\n", c);
	ft_printf("f_%%+c	'%+c'\n\n", c);

	printf("p_%%lc	'%lc'\n", c);
	ft_printf("f_%%lc	'%lc'\n\n", c);

	printf("p_%%llc	'%llc'\n", c);
	ft_printf("f_%%llc	'%llc'\n\n", c);

	printf("p_%%hc	'%hc'\n", c);
	ft_printf("f_%%hc	'%hc'\n\n", c);

	printf("p_%%hhc	'%hhc'\n", c);
	ft_printf("f_%%hhc	'%hhc'\n\n", c);

	//etc
	printf("p_%%5.5c	'%-----5.2c'\n", c);
	ft_printf("f_%%5.5c	'%-----5.2c'\n\n", c);
	printf("p_%%5lc	'%5lc'\n", c);
	ft_printf("f_%%5lc	'%5lc'\n\n", c);
}
static void about_s(void)
{
	//setbuf(stdout, NULL);
	setlocale(LC_ALL, "en_US.UTF-8");

	int		*s = "안녕하세요";
	int		*ls = L"안하세요?";
	printf("<about s>\n\n");

	printf("p_%%s		'%s'\n", s);
	ft_printf("f_%%s		'%s'\n\n", s);

	printf("p_%%-s	'%-s'\n", s);
	ft_printf("f_%%-s	'%-s'\n\n", s);

	printf("p_%%-30s	'%-30s'\n", s);
	ft_printf("f_%%-30s	'%-30s'\n\n", s);

	printf("p_%%0s	'%0s'\n", s);
	ft_printf("f_%%0s	'%0s'\n\n", s);

	printf("p_%%30s	'%30s'\n", s);
	ft_printf("f_%%30s	'%30s'\n\n", s);

	printf("p_%%.30s	'%.30s'\n", s);
	ft_printf("f_%%.30s	'%.30s'\n\n", s);

	printf("p_%%.3s	'%.3s'\n", s);
	ft_printf("f_%%.3s	'%.3s'\n\n", s);

	printf("p_%%#s	:%#s\n", s);
	ft_printf("f_%%#s	:%#s\n\n", s);

	printf("p_%% s	:% s\n", s);
	ft_printf("f_%% s	:% s\n\n", s);

	printf("p_%%+s	:%+s\n", s);
	ft_printf("f_%%+s	:%+s\n\n", s);

	printf("p_%%ls	|%ls|\n", ls);
	ft_printf("f_%%ls	|%ls|\n\n", ls);

	printf("p_%%lls	:%lls\n", s);
	ft_printf("f_%%lls	:%lls\n\n", s);

	printf("p_%%hs	:%hs\n", s);
	ft_printf("f_%%hs	:%hs\n\n", s);

	printf("p_%%hhs	:%hhs\n", s);
	ft_printf("f_%%hhs	:%hhs\n\n", s);
	//ect
	printf("p_%%5.3s	'%5.3s'\n", s);
	ft_printf("f_%%5.3s	'%5.3s'\n\n", s);

	printf("p_%%-5.3s	'%-5.3s'\n", s);
	ft_printf("f_%%-5.3s	'%-5.3s'\n\n", s);

	printf("p_%%.-3s	'%.-3s'\n", s);
	ft_printf("f_%%.-3s	'%.-3s'\n\n", s);

	printf("p_%%.s	'%.s'\n", s);
	ft_printf("f_%%.s	'%.s'\n\n", s);

	printf("p :%-2s.\n", NULL);
	ft_printf("f :%-2s.\n\n", NULL);

	printf("p_%%010.6s	'%010.6s'\n", s);
	ft_printf("f_%%010.6s	'%010.6s'\n\n", s);

	printf("p_%%090s	'%090s'\n", s);
	ft_printf("f_%%090s	'%090s'\n\n", s);

	printf("p_%%ls	|%12ls|\n", ls);
	ft_printf("f_%%ls	|%12ls|\n\n", ls);

}
static void about_p(void)
{
	printf("<about p>\n\n");

	printf("p_%%p	:%p\n", "hi");
	ft_printf("f_%%p	:%p\n\n", "hi");
	printf("p_%%-p	:%-p\n", "hi");
	ft_printf("f_%%-p	:%-p\n\n", "hi");
	printf("p_%%-16p	:'%-16p'\n", "hi");
	ft_printf("f_%%-16p	:'%-16p'\n\n", "hi");
	printf("p_%%-16.p	|%-16.p|\n", "hi");
	ft_printf("f_%%-16.p	|%-16.p|\n\n", "hi");
	printf("p_%%0p	:%0p\n", "hi");
	ft_printf("f_%%0p	:%0p\n\n", "hi");
	printf("p_%%016p	:%016p\n", "hi");
	ft_printf("f_%%016p	:%016p\n\n", "hi");
	printf("p_%%16p	|%16p|\n", "hi");
	ft_printf("f_%%16p	|%16p|\n\n", "hi");

	printf("p_%%.4p	:%.4p\n", "hi");
	ft_printf("f_%%.4p	:%.4p\n\n", "hi");
	printf("p_%%.16p	:%.16p\n", "hi");
	ft_printf("f_%%.16p	:%.16p\n\n", "hi");
	printf("p_%%.32p	:%.32p\n", "hi");
	ft_printf("f_%%.32p	:%.32p\n\n", "hi");

	printf("p_%%#p	:%#p\n", "hi");
	ft_printf("f_%%#p	:%#p\n\n", "hi");
	printf("p_%% p	:% p\n", "hi");
	ft_printf("f_%% p	:% p\n\n", "hi");
	printf("p_%%+p	:%+p\n", "hi");
	ft_printf("f_%%+p	:%+p\n\n", "hi");
	printf("p_%%+18p	:%+18p\n", "hi");
	ft_printf("f_%%+18p	:%+18p\n\n", "hi");
	printf("p_%%lp	:%lp\n", "hi");
	ft_printf("f_%%lp	:%lp\n\n", "hi");
	printf("p_%%llp	:%llp\n", "hi");
	ft_printf("f_%%llp	:%llp\n\n", "hi");
	printf("p_%%hp	:%hp\n", "hi");
	ft_printf("f_%%hp	:%hp\n\n", "hi");
	printf("p_%%hhp	:%hhp\n", "hi");
	ft_printf("f_%%hhp	:%hhp\n\n", "hi");

	printf("p_%%20.16p	:%20.16p\n", "hi");
	ft_printf("f_%%20.16p	:%20.16p\n\n", "hi");
	printf("p_%%3.16p	:%3.16p\n", "hi");
	ft_printf("f_%%3.16p	:%3.16p\n\n", "hi");

	printf("p_%% 18.16p	:% 18.16p\n", "hi");
	ft_printf("f_%% 18.16p	:% 18.16p\n\n", "hi");
	printf("p_%% 19.16p	:% 19.16p\n", "hi");
	ft_printf("f_%% 19.16p	:% 19.16p\n\n", "hi");
	printf("p_%% 20.16p	:% 20.16p\n", "hi");
	ft_printf("f_%% 20.16p	:% 20.16p\n\n", "hi");
	printf("p_%%.0p	:%.0p\n", 0);
	ft_printf("f_%%.0p	:%.0p\n\n", 0);
	printf("p_%%.1p	:%.1p\n", 100);
	ft_printf("f_%%.1p	:%.1p\n\n", 100);
	printf("p_%%-16.p	|%-16.p|\n", 0);
	ft_printf("f_%%-16.p	|%-16.p|\n\n", 0);
}
static void about_d(void)
{
	int d;
	d = 7890;

	printf("<about d>\n\n");

	printf("p_%%d		:%d\n", d);
	ft_printf("f_%%d		:%d\n\n", d);

	printf("p_%%-d	:%-d\n", d);
	ft_printf("f_%%-d	:%-d\n\n", d);

	printf("p_%%-16d	:%-16d\n", d);
	ft_printf("f_%%-16d	:%-16d\n\n", d);

	printf("p_%%0d	:%0d\n", d);
	ft_printf("f_%%0d	:%0d\n\n", d);
	printf("p_%%016d	:%016d\n", d);
	ft_printf("f_%%016d	:%016d\n\n", d);

	printf("p_%%16d	:'%16d'\n", d);
	ft_printf("f_%%16d	:'%16d'\n\n", d);

	printf("p_%%.16d	:%.16d\n", d);
	ft_printf("f_%%.16d	:%.16d\n\n", d);

	printf("p_%%#d	:%#d\n", d);
	ft_printf("f_%%#d	:%#d\n\n", d);

	printf("p_%% d	:% d\n", d);
	ft_printf("f_%% d	:% d\n\n", d);

	printf("p_%%+d	:%+d\n", d);
	ft_printf("f_%%+d	:%+d\n\n", d);
	printf("p_%%+16d	:%+16d\n", d);
	ft_printf("f_%%+16d	:%+16d\n\n", d);
	printf("p_%%+016d	:%+016d\n", d);
	ft_printf("f_%%+016d	:%+016d\n\n", d);

	printf("p_%%ld	:%ld\n", (long)d);
	ft_printf("f_%%ld	:%ld\n\n", (long)d);

	printf("p_%%lld	:%lld\n", (long long)d);
	ft_printf("f_%%lld	:%lld\n\n", (long long)d);

	printf("p_%%hd	:%hd\n", d);
	ft_printf("f_%%hd	:%hd\n\n", d);

	printf("p_%%hhd	:%hhd\n", d);
	ft_printf("f_%%hhd	:%hhd\n\n", d);

	printf("p_%%0.d	:%0.d\n", 0);
	ft_printf("f_%%0.d	:%0.d\n\n", 0);
	printf("p_%%*d	:%*d\n", 10, 10);
	ft_printf("f_%%*d	:%*d\n\n", 10, 10);
	printf("p_%%.*d	:%.*d\n", 10, 10);
	ft_printf("f_%%.*d	:%.*d\n\n", 10, 10);
	printf("p_%%-*d	:'%-*d'\n", -21, 10);
	ft_printf("f_%%-*d	:'%-*d'\n\n", -21, 10);
	printf("p_%%-*d	:'%-*d'\n", 10, 10);
	ft_printf("f_%%-*d	:'%-*d'\n\n", 10, 10);

	printf("p_%%0*.*d	:'%0*.*d'\n", 1, 0, 0);
	ft_printf("f_%%0*.*d	:'%0*.*d'\n\n", 1, 0, 0);
	printf("p_%%0*.*d	:'%0*.*d'\n", 15, 10, -500);
	ft_printf("f_%%0*.*d	:'%0*.*d'\n\n", 15, 10, -500);

	printf("p_%%+-5.d	|%+-5.d|\n", -12);
	ft_printf("f_%%+-5.d	|%+-5.d|\n\n", -12);
	printf("p_%%+-5.d	|%+-5.d|\n", 0);
	ft_printf("f_%%+-5.d	|%+-5.d|\n\n", 0);

	printf("p_%%d		:%lld %d%d%d%d%d%d%d%d\n");
	ft_printf("f_%%d		:%lld %d%d%d%d%d%d%d%d%d\n\n");
}
static void about_i(void)
{

	printf("<about i>\n\n");

	printf("p_%%i		:%i\n", 0b100);
	ft_printf("f_%%i		:%i\n\n", 0b100);

	printf("p_%%-i	:%-i\n", 7890);
	ft_printf("f_%%-i	:%-i\n\n", 7890);

	printf("p_%%-16i	:%-16i\n", 7890);
	ft_printf("f_%%-16i	:%-16i\n\n", 7890);

	printf("p_%%0i	:%0i\n", 7890);
	ft_printf("f_%%0i	:%0i\n\n", 7890);

	printf("p_%%16i	:%16i\n", 7890);
	ft_printf("f_%%16i	:%16i\n\n", 7890);

	printf("p_%%.16i	:%.16i\n", 7890);
	ft_printf("f_%%.16i	:%.16i\n\n", 7890);

	printf("p_%%#i	:%#i\n", 7890);
	ft_printf("f_%%#i	:%#i\n\n", 7890);

	printf("p_%% i	:% i\n", 7890);
	ft_printf("f_%% i	:% i\n\n", 7890);

	printf("p_%%+i	:%+i\n", 7890);
	ft_printf("f_%%+i	:%+i\n\n", 7890);

	printf("p_%%li	:%li\n", (long)7890);
	ft_printf("f_%%li	:%li\n\n", (long)7890);

	printf("p_%%lli	:%lli\n", (long long)7890);
	ft_printf("f_%%lli	:%lli\n\n", (long long)7890);

	printf("p_%%hi	:%hi\n", 7890);
	ft_printf("f_%%hi	:%hi\n\n", 7890);

	printf("p_%%hhi	:%hhi\n", 7890);
	ft_printf("f_%%hhi	:%hhi\n\n", 7890);
}
static void about_u(void)
{
	unsigned int u;

	u = -78980;
	printf("<about u>\n\n");

	printf("p_%%u		:%u\n", (unsigned int)4282621618);
	ft_printf("f_%%u		:%u\n\n", (unsigned int)4282621618);

	printf("p_%%u		:%u\n", 0b100);
	ft_printf("f_%%u		:%u\n\n", 0b100);

	printf("p_%%-u	:%-u\n", u);
	ft_printf("f_%%-u	:%-u\n\n", u);

	printf("p_%%-16u	:%-16u\n", u);
	ft_printf("f_%%-16u	:%-16u\n\n", u);

	printf("p_%%0u	:%0u\n", u);
	ft_printf("f_%%0u	:%0u\n\n", u);
	printf("p_%%.0u	:%.0u\n", u);
	ft_printf("f_%%.0u	:%.0u\n\n", u);

	printf("p_%%16u	:%16u\n", u);
	ft_printf("f_%%16u	:%16u\n\n", u);

	printf("p_%%.16u	:%.16u\n", u);
	ft_printf("f_%%.16u	:%.16u\n\n", u);

	printf("p_%%#u	:%#u\n", u);
	ft_printf("f_%%#u	:%#u\n\n", u);

	printf("p_%% u	:% u\n", u);
	ft_printf("f_%% u	:% u\n\n", u);
	printf("p_%% 4u	:% 4u\n", u);
	ft_printf("f_%% 4u	:% 4u\n\n", u);

	printf("p_%%+u	:%+u\n", u);
	ft_printf("f_%%+u	:%+u\n\n", u);

	printf("p_%%lu	:%lu\n", (long)u);
	ft_printf("f_%%lu	:%lu\n\n", (long)u);

	printf("p_%%llu	:%llu\n", (long long)u);
	ft_printf("f_%%llu	:%llu\n\n", (long long)u);

	printf("p_%%hu	:%hu\n", u);
	ft_printf("f_%%hu	:%hu\n\n", u);

	printf("p_%%hhu	:%hhu\n", u);
	ft_printf("f_%%hhu	:%hhu\n\n", u);

	printf("p_%%-4llu	:%-4.llu\n", (long long)10000000000000000000);
	ft_printf("f_%%-4llu	:%-4.llu\n", (long long)10000000000000000000);
}
static void about_x(void)
{
	int x;

	x = 7890;
	printf("<about x>\n\n");

	printf("p_%%x		:%x\n", (unsigned int)5282621618);
	ft_printf("f_%%x		:%x\n\n", (unsigned int)5282621618);

	printf("p_%%x		:%x\n", 0b100);
	ft_printf("f_%%x		:%x\n\n", 0b100);

	printf("p_%%-x	:%-x\n", x);
	ft_printf("f_%%-x	:%-x\n\n", x);

	printf("p_%%-16x	:%-16x\n", x);
	ft_printf("f_%%-16x	:%-16x\n\n", x);

	printf("p_%%0x	:%0x\n", x);
	ft_printf("f_%%0x	:%0x\n\n", x);

	printf("p_%%16x	:%16x\n", x);
	ft_printf("f_%%16x	:%16x\n\n", x);

	printf("p_%%.16x	:%.16x\n", x);
	ft_printf("f_%%.16x	:%.16x\n\n", x);

	printf("p_%%#x	:%#x\n", x);
	ft_printf("f_%%#x	:%#x\n\n", x);
	printf("p_%%10#x	:%#10x\n", x);
	ft_printf("f_%%10#x	:%#10x\n\n", x);
	printf("p_%%010#x	:%#010x\n", x);
	ft_printf("f_%%010#x	:%#010x\n\n", x);
	printf("p_%%.10#x	:%#.10x\n", x);
	ft_printf("f_%%.10#x	:%#.10x\n\n", x);
	printf("p_%%#010.5x	:%#010.5x\n", x);
	ft_printf("f_%%#010.5x	:%#010.5x\n\n", x);
	printf("p_%%#010.22x	:%#010.22x\n", x);
	ft_printf("f_%%#010.22x	:%#010.22x\n\n", x);
	printf("p_%%# x	:%# x\n", x);
	ft_printf("f_%%# x	:%# x\n\n", x);

	printf("p_%% x	:% x\n", x);
	ft_printf("f_%% x	:% x\n\n", x);

	printf("p_%%+x	:%+x\n", x);
	ft_printf("f_%%+x	:%+x\n\n", x);

	printf("p_%%+18x	:%+18x\n", x);
	ft_printf("f_%%+18x	:%+18x\n\n", x);
	printf("p_%%18x	:%18x\n", x);
	ft_printf("f_%%18x	:%18x\n\n", x);

	printf("p_%%lx	:%lx\n", (long)x);
	ft_printf("f_%%lx	:%lx\n\n", (long)x);

	printf("p_%%llx	:%llx\n", (long long)x);
	ft_printf("f_%%llx	:%llx\n\n", (long long)x);

	printf("p_%%hx	:%hx\n", x);
	ft_printf("f_%%hx	:%hx\n\n", x);

	printf("p_%%hhx	:%hhx\n", x);
	ft_printf("f_%%hhx	:%hhx\n\n", x);

	printf("p_%%#4.p		|%#4.p|\n", 0);
	ft_printf("f_%%#4.p		|%#4.p|\n", 0);
	printf("p_%%#4.x		|%#4.x|\n", 0);
	ft_printf("f_%%#4.x		|%#4.x|\n\n", 0);

	printf("p_%%#-4.p	|%#-4.p|\n", 0);
	ft_printf("f_%%#-4.p	|%#-4.p|\n", 0);
	printf("p_%%#-4.x	|%#-4.x|\n", 0);
	ft_printf("f_%%#-4.x	|%#-4.x|\n\n", 0);

	printf("p_%%#4.*p	|%#4.*p|\n", -4, 0);
	ft_printf("f_%%#4.*p	|%#4.*p|\n", -4, 0);
	printf("p_%%#4.*x	|%#4.*x|\n", -4, 0);
	ft_printf("f_%%#4.*x	|%#4.*x|\n\n", -4, 0);

	printf("p_%%#-4.*p	|%#-4.*p|\n", -4, 0);
	ft_printf("f_%%#-4.*p	|%#-4.*p|\n", -4, 0);
	printf("p_%%#-4.*x	|%#-4.*x|\n", -4, 0);
	ft_printf("f_%%#-4.*x	|%#-4.*x|\n\n", -4, 0);
}
static void about_big_x(void)
{
	int x;

	x = 789078907;
	printf("<about X>\n\n");

	printf("p_%%X		:%X\n", (unsigned int)5282621618);
	ft_printf("f_%%X		:%X\n\n", (unsigned int)5282621618);

	printf("p_%%X		:%X\n", 0b100);
	ft_printf("f_%%X		:%x\n\n", 0b100);

	printf("p_%%-X	:%-X\n", x);
	ft_printf("f_%%-X	:%-X\n\n", x);

	printf("p_%%-16X	:%-16X\n", x);
	ft_printf("f_%%-16X	:%-16X\n\n", x);

	printf("p_%%0X	:%0X\n", x);
	ft_printf("f_%%0X	:%0X\n\n", x);

	printf("p_%%16X	:%16X\n", x);
	ft_printf("f_%%16X	:%16X\n\n", x);

	printf("p_%%.16X	:%.16X\n", x);
	ft_printf("f_%%.16X	:%.16X\n\n", x);

	printf("p_%%#X	:%#X\n", x);
	ft_printf("f_%%#X	:%#X\n\n", x);
	printf("p_%%10#X	:%#10X\n", x);
	ft_printf("f_%%10#X	:%#10X\n\n", x);
	printf("p_%%010#X	:%#010X\n", x);
	ft_printf("f_%%010#X	:%#010X\n\n", x);
	printf("p_%%.10#X	:%#.10X\n", x);
	ft_printf("f_%%.10#X	:%#.10X\n\n", x);
	printf("p_%%#010.5X	:%#010.5X\n", x);
	ft_printf("f_%%#010.5X	:%#010.5X\n\n", x);
	printf("p_%%#010.22X	:%#010.22X\n", x);
	ft_printf("f_%%#010.22X	:%#010.22X\n\n", x);
	printf("p_%%# X	:%# X\n", x);
	ft_printf("f_%%# X	:%# X\n\n", x);

	printf("p_%% X	:% X\n", x);
	ft_printf("f_%% X	:% X\n\n", x);

	printf("p_%%+X	:%+X\n", x);
	ft_printf("f_%%+X	:%+X\n\n", x);

	printf("p_%%+18X	:%+18X\n", x);
	ft_printf("f_%%+18X	:%+18X\n\n", x);
	printf("p_%%18X	:%18X\n", x);
	ft_printf("f_%%18X	:%18X\n\n", x);

	printf("p_%%lX	:%lX\n", (long)x);
	ft_printf("f_%%lX	:%lX\n\n", (long)x);

	printf("p_%%llX	:%llX\n", (long long)x);
	ft_printf("f_%%llX	:%llX\n\n", (long long)x);

	printf("p_%%hX	:%hX\n", x);
	ft_printf("f_%%hX	:%hX\n\n", x);

	printf("p_%%hhX	:%hhX\n", x);
	ft_printf("f_%%hhX	:%hhX\n\n", x);

	printf("p_%%#4.p		|%#4.p|\n", x);
	ft_printf("f_%%#4.p		|%#4.p|\n", x);
	printf("p_%%#4.X		|%#4.X|\n", x);
	ft_printf("f_%%#4.X		|%#4.X|\n\n", x);

	printf("p_%%#-4.p	|%#-4.p|\n", x);
	ft_printf("f_%%#-4.p	|%#-4.p|\n", x);
	printf("p_%%#-4.X	|%#-4.X|\n", x);
	ft_printf("f_%%#-4.X	|%#-4.X|\n\n", x);

	printf("p_%%#4.*p	|%#4.*p|\n", -4, x);
	ft_printf("f_%%#4.*p	|%#4.*p|\n", -4, x);
	printf("p_%%#4.*X	|%#4.*X|\n", -4, x);
	ft_printf("f_%%#4.*X	|%#4.*X|\n\n", -4, x);

	printf("p_%%#-4.*p	|%#-4.*p|\n", -4, x);
	ft_printf("f_%%#-4.*p	|%#-4.*p|\n", -4, x);
	printf("p_%%#-4.*X	|%#-4.*X|\n", -4, x);
	ft_printf("f_%%#-4.*X	|%#-4.*X|\n\n", -4, x);
}
static void about_percent(void)
{
	printf("<about %%>\n\n");

	printf("p			:|%%|\n");
	ft_printf("f			:|%%|\n");

	printf("p_%%%%		:|%%|\n");
	ft_printf("f_%%%%		:|%%|\n\n");

	printf("p_%%-%%	:|%-%|\n");
	ft_printf("f_%%-%%	:|%-%|\n\n");

	printf("p_%%-16%%	:|%-16%|\n");
	ft_printf("f_%%-16%%	:|%-16%|\n\n");

	printf("p_%%0%%	:|%0%|\n");
	ft_printf("f_%%0%%	:|%0%|\n\n");

	printf("p_%%16%%	:%16%\n");
	ft_printf("f_%%16%%	:%16%\n\n");

	printf("p_%%.16%%	:%.16%\n");
	ft_printf("f_%%.16%%	:%.16%\n\n");

	printf("p_%%#%%	:%#%\n");
	ft_printf("f_%%#%%	:%#%\n\n");

	printf("p_%% %%	:% %\n");
	ft_printf("f_%% %%	:% %\n\n");

	printf("p_%%+%%	:%+%\n");
	ft_printf("f_%%+%%	:%+%\n\n");

	printf("p_%%l%%	:%l%\n");
	ft_printf("f_%%l%%	:%l%\n\n");

	printf("p_%%ll%%	:%ll%\n");
	ft_printf("f_%%ll%%	:%ll%\n\n");

	printf("p_%%h%%	:%h%\n");
	ft_printf("f_%%h%%	:%h%\n\n");

	printf("p_%%hh%%	:%hh%\n");
	ft_printf("f_%%hh%%	:%hh%\n\n");
	printf("p_%%05%	:%05%\n");
	ft_printf("f_%%05%	:%05%\n\n");
	printf("p_%%0-5%	:%0-5%.\n");
	ft_printf("f_%%0-5%	:%0-5%.\n\n");
	printf("p_%%	|%|\n");
	ft_printf("f_%%	|%|\n\n");
}
static void about_n(void)
{
	int a1;
	int a2;

	printf("<about n>\n\n");

	printf("p_%%n		:%n\n", NULL);
	ft_printf("f_%%n		:%n\n\n", NULL);

	printf("p_%%d		:%d\n", NULL);
	ft_printf("f_%%d		:%d\n\n", NULL);

	printf("p_%%n		:%nllllllllll\n", &a1);
	ft_printf("f_%%n		:%nllllllllll\n\n", &a2);

	printf("p_%%d		:%d\n", a1);
	ft_printf("f_%%d		:%d\n\n", a2);

	printf("p_%%-n	:%-n\n", &a1);
	ft_printf("f_%%-n	:%-n\n\n", &a2);

	printf("p_%%-16n	:%-16n\n", &a1);
	ft_printf("f_%%-16n	:%-16n\n\n", &a2);

	printf("p_%%0n	:%0n\n", &a1);
	ft_printf("f_%%0n	:%0n\n\n", &a2);

	printf("p_%%16n	:%16n\n", &a1);
	ft_printf("f_%%16n	:%16n\n\n", &a2);

	printf("p_%%.16n	:%.16n\n", &a1);
	ft_printf("f_%%.16n	:%.16n\n\n", &a2);

	printf("p_%%#n	:%#n\n", &a1);
	ft_printf("f_%%#n	:%#n\n\n", &a2);

	printf("p_%% n	:% n\n", &a1);
	ft_printf("f_%% n	:% n\n\n", &a2);

	printf("p_%%+n	:%+n\n", &a1);
	ft_printf("f_%%+n	:%+n\n\n", &a2);

	printf("p_%%ln	:%ln\n", &a1);
	ft_printf("f_%%ln	:%ln\n\n", &a1);

	printf("p_%%lln	:%lln\n", &a2);
	ft_printf("f_%%lln	:%lln\n\n", &a2);

	printf("p_%%hn	:%hn\n", &a1);
	ft_printf("f_%%hn	:%hn\n\n", &a2);

	printf("p_%%hhn	:%hhn\n", &a1);
	ft_printf("f_%%hhn	:%hhn\n\n", &a2);

	printf("p_%%d		:%d\n", a1);
	ft_printf("f_%%d		:%d\n\n", a2);
}

static void about_f(void)
{
	//double f = 0.87650894255;
	//int f = 1;
	//double f = 100.5;
	double f = 2;
	//double f = 4.9406564584124654E-324;
	int		d;
	printf("<about f>\n\n");

	printf("p_%%f		:%f\n", f);
	ft_printf("f_%%f		:%f\n\n", f);

	printf("p_%%-f	:%-f\n", f);
	ft_printf("f_%%-f	:%-f\n\n", f);

	printf("p_%%-16f	:%-16f\n", f);
	ft_printf("f_%%-16f	:%-16f\n\n", f);

	printf("p_%%0f	:%0f\n", f);
	ft_printf("f_%%0f	:%0f\n\n", f);

	printf("p_%%16f	|%16f|\n", f);
	ft_printf("f_%%16f	|%16f|\n\n", f);

	printf("p_%%.16f	:%.16f\n", f);
	ft_printf("f_%%.16f	:%.16f\n\n", f);

	printf("p_%%#f	:%#f\n", f);
	ft_printf("f_%%#f	:%#f\n\n", f);

	printf("p_%% f	:% f\n", f);
	ft_printf("f_%% f	:% f\n\n", f);

	printf("p_%%+f	:%+f\n", f);
	ft_printf("f_%%+f	:%+f\n\n", f);

	printf("p_%%.90lf	:%.90lf\n", f);
	ft_printf("f_%%.90lf	:%.90lf\n\n", f);

	printf("p_%%llf	:%llf\n", f);
	ft_printf("f_%%llf	:%llf\n\n", f);

	printf("p_%%hf	:%hf\n", f);
	ft_printf("f_%%hf	:%hf\n\n", f);

	printf("p_%%hhf	:%hhf\n", f);
	ft_printf("f_%%hhf	:%hhf\n\n", f);

	printf("p_%%-4.f	|%-4.f|\n", f);
	ft_printf("f_%%-4.f	|%-4.f|\n\n", f);
	printf("p_%%-4.*f	|%-4.*f|\n", 1, f);
	ft_printf("f_%%-4.*f	|%-4.*f|\n\n", 1, f);
	printf("p_%%*.*f	|%*.*f|\n", -16, 2, f);
	ft_printf("f_%%*.*f	|%*.*f|\n\n", -16, 2, f);
	printf("p_%%*.*f	|%*.*f|\n", 16, 2, f);
	ft_printf("f_%%*.*f	|%*.*f|\n\n", 16, 2, f);
	d = printf("p_%%#-4.f	|%#-4.f|\n", f);
	printf("|%d|\n", d);
	d = ft_printf("f_%%#-4.f	|%#-4.f|\n", f);
	printf("|%d|\n", d);
	d = printf("p_%%0*.f		|%0*.f|\n", 20, f);
	printf("|%d|\n", d);
	d = ft_printf("f_%%0*.f		|%0*.f|\n", 20, f);
	printf("|%d|\n", d);
	d = printf("p_%%0*.1f		|%0*.4f|\n", 20, f);
	printf("|%d|\n", d);
	d = ft_printf("f_%%0*.1f		|%0*.4f|\n", 20, f);
	printf("|%d|\n", d);
	printf("p_%%.10f	|%.10f|\n", f);
	ft_printf("f_%%.10f	|%.10f|\n\n", f);
	printf("p_%%+6f	|%+6f|\n", f);
	ft_printf("f_%%+6f	|%+6f|\n\n", f);

	double special; *((unsigned long *)(&special)) = DBL_INF;
	ft_printf("|%+6f|", special);

	void		*v;
	int			bina[8];
	v = &f;
	unsigned char* s;
	s = (unsigned char *)v;
	for (int i = sizeof(f) - 1; i >= 0; i--)
		bina[i] = s[i];

	for (int i = sizeof(f) - 1; i >= 0; i--)
	{
		if (bina[i] >= 128)
		{
			printf("1");
			bina[i] -= 128;
		}
		else
			printf("0");
		if (bina[i] >= 64)
		{
			printf("1");
			bina[i] -= 64;
		}
		else
			printf("0");
		if (bina[i] >= 32)
		{
			printf("1");
			bina[i] -= 32;
		}
		else
			printf("0");
		if (bina[i] >= 16)
		{
			printf("1");
			bina[i] -= 16;
		}
		else
			printf("0");
		if (bina[i] >= 8)
		{
			printf("1");
			bina[i] -= 8;
		}
		else
			printf("0");
		if (bina[i] >= 4)
		{
			printf("1");
			bina[i] -= 4;
		}
		else
			printf("0");
		if (bina[i] >= 2)
		{
			printf("1");
			bina[i] -= 2;
		}
		else
			printf("0");
		if (bina[i] >= 1)
		{
			printf("1");
			bina[i] -= 1;
		}
		else
			printf("0");
		printf(" ");
	}
}
static void about_g(void)
{
	double g = 0.0;
	printf("<about g>\n\n");

	ft_printf("f_%%g		:%g\n\n", g);

	printf("p_%%-g	:%-g\n", g);
	ft_printf("f_%%-g	:%-g\n\n", g);

	printf("p_%%-16g	:%-16g\n", g);
	ft_printf("f_%%-16g	:%-16g\n\n", g);

	printf("p_%%0g	:%0g\n", g);
	ft_printf("f_%%0g	:%0g\n\n", g);

	printf("p_%%16g	:%16g\n", g);
	ft_printf("f_%%16g	:%16g\n\n", g);

	printf("p_%%.16g	:%.16g\n", g);
	ft_printf("f_%%.16g	:%.16g\n\n", g);

	printf("p_%%#g	:%#g\n", g);
	ft_printf("f_%%#g	:%#g\n\n", g);

	printf("p_%% g	:% g\n", g);
	ft_printf("f_%% g	:% g\n\n", g);

	printf("p_%%+g	:%+g\n", g);
	ft_printf("f_%%+g	:%+g\n\n", g);

	printf("p_%%lg	:%lg\n", g);
	ft_printf("f_%%lg	:%lg\n\n", g);

	printf("p_%%llg	:%llg\n", g);
	ft_printf("f_%%llg	:%llg\n\n", g);

	printf("p_%%hg	:%hg\n", g);
	ft_printf("f_%%hg	:%hg\n\n", g);

	printf("p_%%hhg	:%hhg\n", g);
	ft_printf("f_%%hhg	:%hhg\n\n", g);

	printf("|%#-4.*g|<--\n", 16, 0.0);
	ft_printf("|%#-4.*g|<--\n", 16, 0.0);

	printf("|%-4.g|\n", 4.0);
	ft_printf("|%-4.g|\n", 4.0);

	double		gfe[100];
	gfe[0] = 9.99;
	gfe[1] = 51.75;
	gfe[2] = 0.00009999999999999;
	gfe[3] = 0.0001;
	gfe[4] = 0.85034539093;
	gfe[5] = 1.000000912317283912;
	gfe[6] = 10.48896435;
	gfe[7] = 1228.5166666;
	gfe[8] = 999999.998;
	gfe[9] = 1000000.5166666;
	gfe[10] = 123456789.87654321;
	gfe[11] = 9045094537563.556476843;
	gfe[12] = -5.0 / 0.0;
	gfe[13] = 0.0 / 0.0;
	gfe[14] = 5.0 / 0.0;

	for (int i = 0; i < 2; i++)
	{
		printf("|%d = %f|\n", i, gfe[i]);
		printf("p_%%g		|%g|\n", gfe[i]);
		printf("p_%%f		|%f|\n", gfe[i]);
		printf("p_%%e		|%e|\n", gfe[i]);
		ft_printf("f_%%g		|%g|\n", gfe[i]);
		ft_printf("f_%%f		|%f|\n", gfe[i]);
		ft_printf("f_%%e		|%e|\n\n", gfe[i]);

		printf("p_%%.3g		|%.3g|\n", gfe[i]);
		printf("p_%%.3f		|%.3f|\n", gfe[i]);
		printf("p_%%.3e		|%.3e|\n", gfe[i]);
		ft_printf("f_%%.3g		|%.3g|\n", gfe[i]);
		ft_printf("f_%%.3f		|%.3f|\n", gfe[i]);
		ft_printf("f_%%.3e		|%.3e|\n\n", gfe[i]);

		for (int j = -1; j < 30; j++)
		{
			printf("p_%%.%dg		|%.*g|\n", j, j, gfe[i]);
			ft_printf("f_%%.%dg		|%.*g|\n\n", j, j, gfe[i]);
		}
		/*
		printf("p_%%.10g		|%.10g|\n", gfe[i]);
		printf("p_%%.10f		|%.10f|\n", gfe[i]);
		printf("p_%%.10e		|%.10e|\n", gfe[i]);
		ft_printf("f_%%.10g		|%.10g|\n", gfe[i]);
		ft_printf("f_%%.10f		|%.10f|\n", gfe[i]);
		ft_printf("f_%%.10e		|%.10e|\n\n", gfe[i]);

		printf("p_%%.100g		|%.100g|\n", gfe[i]);
		printf("p_%%.100f		|%.100f|\n", gfe[i]);
		printf("p_%%.100e		|%.100e|\n", gfe[i]);
		ft_printf("f_%%.100g		|%.100g|\n", gfe[i]);
		ft_printf("f_%%.100f		|%.100f|\n", gfe[i]);
		ft_printf("f_%%.100e		|%.100e|\n\n", gfe[i]);

		printf("p_%%30.100g		|%-30.100g|\n", gfe[i]);
		printf("p_%%30.100f		|%-30.100f|\n", gfe[i]);
		printf("p_%%30.100e		|%-30.100e|\n", gfe[i]);
		ft_printf("f_%%30.100g		|%-30.100g|\n", gfe[i]);
		ft_printf("f_%%30.100f		|%-30.100f|\n", gfe[i]);
		ft_printf("f_%%30.100e		|%-30.100e|\n\n", gfe[i]);
		*/
	}

}
static void about_e(void)
{
	double f = 0.87650894255;
	f = 0.0;
	//int f = 1;
	//f = 4.9406564584124654E-324;
	int		d;
	printf("<about e>\n\n");

	printf("p_%%e		:%e\n", f);
	ft_printf("f_%%e		:%e\n\n", f);

	printf("p_%%-f	:%-e\n", f);
	ft_printf("f_%%-f	:%-e\n\n", f);

	printf("p_%%-16f	:%-16e\n", f);
	ft_printf("f_%%-16f	:%-16e\n\n", f);

	printf("p_%%0f	:%0e\n", f);
	ft_printf("f_%%0f	:%0e\n\n", f);

	printf("p_%%16f	|%16e|\n", f);
	ft_printf("f_%%16f	|%16e|\n\n", f);

	printf("p_%%.16f	:%.16e\n", f);
	ft_printf("f_%%.16f	:%.16e\n\n", f);

	printf("p_%%#f	:%#e\n", f);
	ft_printf("f_%%#f	:%#e\n\n", f);

	printf("p_%% f	:% e\n", f);
	ft_printf("f_%% f	:% e\n\n", f);

	printf("p_%%+f	:%+e\n", f);
	ft_printf("f_%%+f	:%+e\n\n", f);

	printf("p_%%.90lf	:%.90le\n", f);
	ft_printf("f_%%.90lf	:%.90le\n\n", f);

	printf("p_%%llf	:%lle\n", f);
	ft_printf("f_%%llf	:%lle\n\n", f);

	printf("p_%%hf	:%he\n", f);
	ft_printf("f_%%hf	:%he\n\n", f);

	printf("p_%%hhf	:%hhe\n", f);
	ft_printf("f_%%hhf	:%hhe\n\n", f);

	printf("p_%%-4.f	|%-4.e|\n", f);
	ft_printf("f_%%-4.f	|%-4.e|\n\n", f);
	printf("p_%%-4.*f	|%-4.*e|\n", 1, f);
	ft_printf("f_%%-4.*f	|%-4.*e|\n\n", 1, f);
	printf("p_%%*.*f	|%*.*e|\n", -16, 2, f);
	ft_printf("f_%%*.*f	|%*.*e|\n\n", -16, 2, f);
	printf("p_%%*.*f	|%*.*e|\n", 16, 2, f);
	ft_printf("f_%%*.*f	|%*.*e|\n\n", 16, 2, f);
	d = printf("p_%%#-4.f	|%#-4.e|\n", f);
	printf("|%d|\n", d);
	d = ft_printf("f_%%#-4.f	|%#-4.e|\n", f);
	printf("|%d|\n", d);
	d = printf("p_%%0*.f		|%0*.e|\n", 20, f);
	printf("|%d|\n", d);
	d = ft_printf("f_%%0*.f		|%0*.e|\n", 20, f);
	printf("|%d|\n", d);
	d = printf("p_%%0*.1f		|%0*.4e|\n", 20, f);
	printf("|%d|\n", d);
	d = ft_printf("f_%%0*.1f		|%0*.4e|\n", 20, f);
	printf("|%d|\n", d);
	printf("p_%%.10f	|%.10e|\n", f);
	ft_printf("f_%%.10f	|%.10e|\n\n", f);
	printf("p_%%.10f	|%.10e|\n", f);
	ft_printf("f_%%.10f	|%.10e|\n\n", f);

	printf("p_%% 6.e	|% 6.e|\n", -16, f);
	ft_printf("f_%% 6.e	|% 6.e|\n\n", -16, f);
	printf("p_%% -6.e	|% -6.e|\n", -16, f);
	ft_printf("f_%% -6.e	|% -6.e|\n\n", -16, f);
	printf("p_%% 6.e	|% 6e|\n", f);
	ft_printf("f_%% 6.e	|% 6e|\n\n", f);
	printf("p_%% -6e	|% -6e|\n", f);
	ft_printf("f_%% -6e	|% -6e|\n\n", f);
	printf("p_%% e	|% e|\n", f);
	ft_printf("f_%% e	|% e|\n\n", f);

	void		*v;
	int			bina[8];
	v = &f;
	unsigned char* s;
	s = (unsigned char *)v;
	for (int i = sizeof(f) - 1; i >= 0; i--)
		bina[i] = s[i];

	for (int i = sizeof(f) - 1; i >= 0; i--)
	{
		if (bina[i] >= 128)
		{
			printf("1");
			bina[i] -= 128;
		}
		else
			printf("0");
		if (bina[i] >= 64)
		{
			printf("1");
			bina[i] -= 64;
		}
		else
			printf("0");
		if (bina[i] >= 32)
		{
			printf("1");
			bina[i] -= 32;
		}
		else
			printf("0");
		if (bina[i] >= 16)
		{
			printf("1");
			bina[i] -= 16;
		}
		else
			printf("0");
		if (bina[i] >= 8)
		{
			printf("1");
			bina[i] -= 8;
		}
		else
			printf("0");
		if (bina[i] >= 4)
		{
			printf("1");
			bina[i] -= 4;
		}
		else
			printf("0");
		if (bina[i] >= 2)
		{
			printf("1");
			bina[i] -= 2;
		}
		else
			printf("0");
		if (bina[i] >= 1)
		{
			printf("1");
			bina[i] -= 1;
		}
		else
			printf("0");
		printf(" ");
	}
}

static void		about_o(void)
{
	int o;

	o = 7890;
	printf("<about o>\n\n");

	printf("p_%%o		:%o\n", (unsigned int)5282621618);
	ft_printf("f_%%o		:%o\n\n", (unsigned int)5282621618);

	printf("p_%%o		:%o\n", 0b100);
	ft_printf("f_%%o		:%o\n\n", 0b100);

	printf("p_%%-o	:%-o\n", o);
	ft_printf("f_%%-o	:%-o\n\n", o);

	printf("p_%%-16o	:%-16o\n", o);
	ft_printf("f_%%-16o	:%-16o\n\n", o);

	printf("p_%%0o	:%0o\n", o);
	ft_printf("f_%%0o	:%0o\n\n", o);

	printf("p_%%16o	:%16o\n", o);
	ft_printf("f_%%16o	:%16o\n\n", o);

	printf("p_%%.16o	:%.16o\n", o);
	ft_printf("f_%%.16o	:%.16o\n\n", o);

	printf("p_%%#o	:%#o\n", o);
	ft_printf("f_%%#o	:%#o\n\n", o);
	printf("p_%%10#o	:%#10o\n", o);
	ft_printf("f_%%10#o	:%#10o\n\n", o);
	printf("p_%%010#o	:%#010o\n", o);
	ft_printf("f_%%010#o	:%#010o\n\n", o);
	printf("p_%%.10#o	:%#.10o\n", o);
	ft_printf("f_%%.10#o	:%#.10o\n\n", o);
	printf("p_%%#010.5o	:%#010.5o\n", o);
	ft_printf("f_%%#010.5o	:%#010.5o\n\n", o);
	printf("p_%%#010.22o	:%#010.22o\n", o);
	ft_printf("f_%%#010.22o	:%#010.22o\n\n", o);
	printf("p_%%# o	:%# o\n", o);
	ft_printf("f_%%# o	:%# o\n\n", o);

	printf("p_%% o	:% o\n", o);
	ft_printf("f_%% o	:% o\n\n", o);

	printf("p_%%+o	:%+o\n", o);
	ft_printf("f_%%+o	:%+o\n\n", o);

	printf("p_%%+18o	:%+18o\n", o);
	ft_printf("f_%%+18o	:%+18o\n\n", o);
	printf("p_%%18o	:%18o\n", o);
	ft_printf("f_%%18o	:%18o\n\n", o);

	printf("p_%%lo	:%lo\n", (long)o);
	ft_printf("f_%%lo	:%lo\n\n", (long)o);

	printf("p_%%llo	:%llo\n", (long long)o);
	ft_printf("f_%%llo	:%llo\n\n", (long long)o);

	printf("p_%%ho	:%ho\n", o);
	ft_printf("f_%%ho	:%ho\n\n", o);

	printf("p_%%hho	:%hho\n", o);
	ft_printf("f_%%hho	:%hho\n\n", o);

	printf("p_%%#4.x		|%#4.x|\n", 0);
	ft_printf("f_%%#4.x		|%#4.x|\n", 0);
	printf("p_%%#4.o		|%#4.o|\n", 0);
	ft_printf("f_%%#4.o		|%#4.o|\n\n", 0);

	printf("p_%%#-4.x	|%#-4.x|\n", 0);
	ft_printf("f_%%#-4.x	|%#-4.x|\n", 0);
	printf("p_%%#-4.o	|%#-4.o|\n", 0);
	ft_printf("f_%%#-4.o	|%#-4.o|\n\n", 0);

	printf("p_%%#4.*x	|%#4.*x|\n", -4, 0);
	ft_printf("f_%%#4.*x	|%#4.*x|\n", -4, 0);
	printf("p_%%#4.*o	|%#4.*o|\n", -4, 0);
	ft_printf("f_%%#4.*o	|%#4.*o|\n\n", -4, 0);

	printf("p_%%#-4.*x	|%#-4.*x|\n", -4, 0);
	ft_printf("f_%%#-4.*x	|%#-4.*x|\n", -4, 0);
	printf("p_%%#-4.*o	|%#-4.*o|\n", -4, 0);
	ft_printf("f_%%#-4.*o	|%#-4.*o|\n\n", -4, 0);

	printf("p_%%#.5x	|%#.5x|\n", 21);
	ft_printf("f_%%#.5x	|%#.5x|\n", 21);
	printf("p_%%#.5o	|%#10.5o|\n", 21);
	ft_printf("f_%%#.5o	|%#10.5o|\n\n", 21);

	printf("p_%%-4.x	|%-4.x|\n", 0);
	ft_printf("f_%%-4.x	|%-4.x|\n", 0);
	printf("p_%%-4.o	|%-4.o|\n", 0);
	ft_printf("f_%%-4.o	|%-4.o|\n\n", 0);
}

int main(void)
{
	//printf		("p	:hello world\n");
	//ft_printf	("f	:hello world\n\n");

	about_c();
	//about_s();
	//about_p();
	//about_d();
	//about_u();
	//about_x();
	//about_big_x();
	//about_percent();
	//about_n();
	//about_f();
	//about_g();
	//about_e();
	//about_o();
	//test_func_e(1.5634890);
	//about_o();
}
