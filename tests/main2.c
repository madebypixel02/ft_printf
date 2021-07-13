/* main test to ft_printf leaks*/

#include "../lib/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void) {
	static char *str = "hola";
	static int r00 = 0;
	static char *s_hidden = "hi low\0don't print me lol\0";
	static int			i_pos_1 = 878023;
	static char	a01;
	static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12;
	static unsigned int		mx_u = 235;
	static char				mx_c = 'G';
	static char			   *mx_s = "Hello, World!";
	static int					mx_i = 42;
	static int ncm_p = 5;
	ft_printf("%%\\n");
	ft_printf("%d\\n", 42);
	ft_printf("%d%d\\n", 42, 41);
	ft_printf("%d%d%d\\n", 42, 43, 44);
	ft_printf("%ld\\n", 2147483647);
	ft_printf("%lld\\n", 9223372036854775807);
	ft_printf("%x\\n", 505);
	ft_printf("%X\\n", 505);
	ft_printf("%p\\n", &ft_printf);
	ft_printf("%20.15u\\n", 4294967295);
	ft_printf("%21.15d\\n", 54321);
	ft_printf("%-10d\\n", 3);
	ft_printf("% d\\n", 3);
	ft_printf("%+d\\n", 3);
	ft_printf("%0100d\\n", 33);
	ft_printf("%hhd\\n", 0);
	ft_printf("%jd\\n", 9223372036854775807);
	ft_printf("%zd\\n", 4294967295);
	ft_printf("%\\n");
	ft_printf("%U\\n", 4294967295);
	ft_printf("%o\\n", 40);
	ft_printf("%%#08x\\n", 42);
	ft_printf("%x\\n", 1000);
	ft_printf("%#X\\n", 1000);
	ft_printf("%s\\n", NULL);
	ft_printf("%S\\n", L"ݗݜशব");
	ft_printf("%s%s\\n", "test", "test");
	ft_printf("%s%s%s\\n", "test", "test", "test");
	ft_printf("%C\\n", 15000);
	ft_printf("hello, %s.", "gavin");
	ft_printf("%s", "testing testing");
	ft_printf("%s%s", "hello", "world");
	ft_printf("..%s stuff %s", "a", "b");
	ft_printf("this %s is empty", "");
	ft_printf("this %s is %s", "hello", "");
	ft_printf("this %s is %s", "", "hello");
	ft_printf("%s%s%s", "1", "2", "3's a charm");
	ft_printf("%32s", "abc");
	ft_printf("%16s", "nark nark");
	ft_printf("%5s", "goes over");
	ft_printf("%-32s", "abc");
	ft_printf("%-16s", "nark nark");
	ft_printf("%-5s", "goes over");
	ft_printf("%.7s", "hello");
	ft_printf("%.3s", "hello");
	ft_printf("%.s", "hello");
	ft_printf("%.0s", "hello");
	ft_printf("%.3s%.2s", "holla", "bitch");
	ft_printf("%.2s%.7s", "hello", "world");
	ft_printf("%.7s%.2s", "hello", "world");
	ft_printf("%.5s%7s", "yo", "boi");
	ft_printf("%7.5s", "yolo");
	ft_printf("%7.5s", "bombastic");
	ft_printf("%-7.5s", "yolo");
	ft_printf("%-7.5s", "tubular");
	ft_printf("%7.7s%7.7s", "hello", "world");
	ft_printf("%3.7s%7.7s", "hello", "world");
	ft_printf("%7.7s%3.7s", "hello", "world");
	ft_printf("%3.7s%3.7s", "hello", "world");
	ft_printf("%7.3s%7.7s", "hello", "world");
	ft_printf("%3.3s%7.7s", "hello", "world");
	ft_printf("%7.3s%3.7s", "hello", "world");
	ft_printf("%3.3s%3.7s", "hello", "world");
	ft_printf("%7.7s%7.3s", "hello", "world");
	ft_printf("%3.7s%7.3s", "hello", "world");
	ft_printf("%7.7s%3.3s", "hello", "world");
	ft_printf("%3.7s%3.3s", "hello", "world");
	ft_printf("%7.3s%7.3s", "hello", "world");
	ft_printf("%3.3s%7.3s", "hello", "world");
	ft_printf("%7.3s%3.3s", "hello", "world");
	ft_printf("%3.3s%3.3s", "hello", "world");
	ft_printf("%3s%3s", "hello", "world");
	ft_printf("%-7s%5s", "hello", "world");
	ft_printf("%7s%-5s", "hello", "world");
	ft_printf("hello, %s.", NULL);
	ft_printf("%s", NULL);
	ft_printf("%32s", NULL);
	ft_printf("%2s", NULL);
	ft_printf("%-32s", NULL);
	ft_printf("%-16s", NULL);
	ft_printf("%-3s", NULL);
	ft_printf("%.9s", "NULL");
	ft_printf("%.3s", "NULL");
	ft_printf("%.s", "NULL");
	ft_printf("%.0s", "NULL");
	ft_printf("%s", s_hidden);
	ft_printf("%3s", s_hidden);
	ft_printf("%9s", s_hidden);
	ft_printf("%.s", s_hidden);
	ft_printf("%.9s", s_hidden);
	ft_printf("%.03s", s_hidden);
	ft_printf("%.09s", s_hidden);
	ft_printf("%.03s", NULL);
	ft_printf("%.09s", NULL);
	ft_printf("%.00s", "\0");
	ft_printf("%.01s", "\0");
	ft_printf("%.03s", "\0");
	ft_printf("%.09s", "\0");
	ft_printf("%3.s", s_hidden);
	ft_printf("%10.s", s_hidden);
	ft_printf("%3.s", NULL);
	ft_printf("%10.s", NULL);
	ft_printf("%1.s", "\0");
	ft_printf("%2.s", "\0");
	ft_printf("%9.s", "\0");
	ft_printf("%-3.s", s_hidden);
	ft_printf("%-8.s", s_hidden);
	ft_printf("%-3.s", NULL);
	ft_printf("%-8.s", NULL);
	ft_printf("%-1.s", "\0");
	ft_printf("%-2.s", "\0");
	ft_printf("%-6.s", "\0");
	ft_printf("%3.1s", s_hidden);
	ft_printf("%10.1s", s_hidden);
	ft_printf("%3.1s", NULL);
	ft_printf("%9.1s", NULL);
	ft_printf("%-3.1s", s_hidden);
	ft_printf("%-10.1s", s_hidden);
	ft_printf("%-3.1s", NULL);
	ft_printf("%-9.1s", NULL);
	ft_printf("%-3.1s", "\0");
	ft_printf("%-6.1s", "\0");
	ft_printf("%3.6s", s_hidden);
	ft_printf("%20.6s", s_hidden);
	ft_printf("%3.6s", NULL);
	ft_printf("%20.6s", NULL);
	ft_printf("%3.6s", "\0");
	ft_printf("%6.6s", "\0");
	ft_printf("%-3.6s", s_hidden);
	ft_printf("%-20.6s", s_hidden);
	ft_printf("%-3.8s", s_hidden);
	ft_printf("%-10.8s", s_hidden);
	ft_printf("%-3.8s", NULL);
	ft_printf("%-10.8s", NULL);
	ft_printf("%-.00s", s_hidden);
	ft_printf("%-.09s", s_hidden);
	ft_printf("%00s", s_hidden);
	ft_printf("%000s", s_hidden);
	ft_printf("%0000s", s_hidden);
	ft_printf("%-00s", s_hidden);
	ft_printf("%0-0s", s_hidden);
	ft_printf("%00-s", s_hidden);
	ft_printf("%03s", s_hidden);
	ft_printf("%09s", s_hidden);
	ft_printf("%-03s", s_hidden);
	ft_printf("%-09s", s_hidden);
	ft_printf("this %i number", 17);
	ft_printf("this %i number", -267);
	ft_printf("this %i number", 0);
	ft_printf("%i", 3);
	ft_printf("%i", -1);
	ft_printf("%i", 0);
	ft_printf("this %d number", 17);
	ft_printf("this %d number", -267);
	ft_printf("this %d number", 0);
	ft_printf("%i",  2147483647);
	ft_printf("%i", (int)(-2147483678));
	ft_printf("%7i", 33);
	ft_printf("%7i", -14);
	ft_printf("%3i", 0);
	ft_printf("%5i", 52625);
	ft_printf("%5i", -2562);
	ft_printf("%4i", 94827);
	ft_printf("%4i", -2464);
	ft_printf("%-7i", 33);
	ft_printf("%-7i", -14);
	ft_printf("%-3i", 0);
	ft_printf("%-5i", 52625);
	ft_printf("%-5i", -2562);
	ft_printf("%-4i", 94827);
	ft_printf("%-4i", -2464);
	ft_printf("%.5i", 2);
	ft_printf("%.6i", -3);
	ft_printf("%.3i", 0);
	ft_printf("%.4i", 5263);
	ft_printf("%.4i", -2372);
	ft_printf("%.3i", 13862);
	ft_printf("%.3i",-23646);
	ft_printf("%05i", 43);
	ft_printf("%07i", -54);
	ft_printf("%03i", 0);
	ft_printf("%03i", 634);
	ft_printf("%04i", -532);
	ft_printf("%04i", -4825);
	ft_printf("%8.5i", 34);
	ft_printf("%10.5i", -216);
	ft_printf("%8.5i", 0);
	ft_printf("%8.3i", 8375);
	ft_printf("%8.3i", -8473);
	ft_printf("%3.7i", 3267);
	ft_printf("%3.7i", -2375);
	ft_printf("%3.3i", 6983);
	ft_printf("%3.3i", -8462);
	ft_printf("%-8.5i", 34);
	ft_printf("%-10.5i", -216);
	ft_printf("%-8.5i", 0);
	ft_printf("%-8.3i", 8375);
	ft_printf("%-8.3i", -8473);
	ft_printf("%-3.7i", 3267);
	ft_printf("%-3.7i", -2375);
	ft_printf("%-3.3i", 6983);
	ft_printf("%-3.3i", -8462);
	ft_printf("%08.5i", 34);
	ft_printf("%010.5i", -216);
	ft_printf("%08.5i", 0);
	ft_printf("%08.3i", 8375);
	ft_printf("%08.3i", -8473);
	ft_printf("%03.7i", 3267);
	ft_printf("%03.7i", -2375);
	ft_printf("%03.3i", 6983);
	ft_printf("%03.3i", -8462);
	ft_printf("%0-8.5i", 34);
	ft_printf("%0-10.5i", -216);
	ft_printf("%0-8.5i", 0);
	ft_printf("%0-8.3i", 8375);
	ft_printf("%0-8.3i", -8473);
	ft_printf("%0-3.7i", 3267);
	ft_printf("%0-3.7i", -2375);
	ft_printf("%0-3.3i", 6983);
	ft_printf("%0-3.3i", -8462);
	ft_printf("[%i] [%i]", i_pos_1, i_pos_1);
	ft_printf("%.0i", 0);
	ft_printf("%.i", 0);
	ft_printf("%5.0i", 0);
	ft_printf("%5.i", 0);
	ft_printf("%-5.0i", 0);
	ft_printf("%-5.i", 0);
	ft_printf("this %d number", 17);
	ft_printf("this %d number", -267);
	ft_printf("this %d number", 0);
	ft_printf("%d", 3);
	ft_printf("%d", -1);
	ft_printf("%d", 0);
	ft_printf("%d",  2147483647);
	ft_printf("%d", (int)(-2147483678));
	ft_printf("%7d", 33);
	ft_printf("%7d", -14);
	ft_printf("%3d", 0);
	ft_printf("%5d", 52625);
	ft_printf("%5d", -2562);
	ft_printf("%4d", 94827);
	ft_printf("%4d", -2464);
	ft_printf("%-7d", 33);
	ft_printf("%-7d", -14);
	ft_printf("%-3d", 0);
	ft_printf("%-5d", 52625);
	ft_printf("%-5d", -2562);
	ft_printf("%-4d", 94827);
	ft_printf("%-4d", -2464);
	ft_printf("%.5d", 2);
	ft_printf("%.6d", -3);
	ft_printf("%.3d", 0);
	ft_printf("%.4d", 5263);
	ft_printf("%.4d", -2372);
	ft_printf("%.3d", 13862);
	ft_printf("%.3d",-23646);
	ft_printf("%05d", 43);
	ft_printf("%07d", -54);
	ft_printf("%03d", 0);
	ft_printf("%03d", 634);
	ft_printf("%04d", -532);
	ft_printf("%04d", -4825);
	ft_printf("%8.5d", 34);
	ft_printf("%10.5d", -216);
	ft_printf("%8.5d", 0);
	ft_printf("%8.3d", 8375);
	ft_printf("%8.3d", -8473);
	ft_printf("%3.7d", 3267);
	ft_printf("%3.7d", -2375);
	ft_printf("%3.3d", 6983);
	ft_printf("%3.3d", -8462);
	ft_printf("%-8.5d", 34);
	ft_printf("%-10.5d", -216);
	ft_printf("%-8.5d", 0);
	ft_printf("%-8.3d", 8375);
	ft_printf("%-8.3d", -8473);
	ft_printf("%-3.7d", 3267);
	ft_printf("%-3.7d", -2375);
	ft_printf("%-3.3d", 6983);
	ft_printf("%-3.3d", -8462);
	ft_printf("%08.5d", 34);
	ft_printf("%010.5d", -216);
	ft_printf("%08.5d", 0);
	ft_printf("%08.3d", 8375);
	ft_printf("%08.3d", -8473);
	ft_printf("%03.7d", 3267);
	ft_printf("%03.7d", -2375);
	ft_printf("%03.3d", 6983);
	ft_printf("%03.3d", -8462);
	ft_printf("%0-8.5d", 34);
	ft_printf("%0-10.5d", -216);
	ft_printf("%0-8.5d", 0);
	ft_printf("%0-8.3d", 8375);
	ft_printf("%0-8.3d", -8473);
	ft_printf("%0-3.7d", 3267);
	ft_printf("%0-3.7d", -2375);
	ft_printf("%0-3.3d", 6983);
	ft_printf("%0-3.3d", -8462);
	ft_printf("%.0d", 0);
	ft_printf("%.d", 0);
	ft_printf("%5.0d", 0);
	ft_printf("%5.d", 0);
	ft_printf("%-5.0d", 0);
	ft_printf("%-5.d", 0);
	ft_printf("this %u number", 17);
	ft_printf("this %u number", 0);
	ft_printf("%u", 3);
	ft_printf("%u", 4294967295u);
	ft_printf("%7u", 33);
	ft_printf("%3u", 0);
	ft_printf("%5u", 52625);
	ft_printf("%4u", 94827);
	ft_printf("%-7u", 33);
	ft_printf("%-3u", 0);
	ft_printf("%-5u", 52625);
	ft_printf("%-4u", 94827);
	ft_printf("%.5u", 2);
	ft_printf("%.3u", 0);
	ft_printf("%.4u", 5263);
	ft_printf("%.3u", 13862);
	ft_printf("%05u", 43);
	ft_printf("%03u", 0);
	ft_printf("%03u", 634);
	ft_printf("%8.5u", 34);
	ft_printf("%8.5u", 0);
	ft_printf("%8.3u", 8375);
	ft_printf("%3.7u", 3267);
	ft_printf("%3.3u", 6983);
	ft_printf("%-8.5u", 34);
	ft_printf("%-8.5u", 0);
	ft_printf("%-8.3u", 8375);
	ft_printf("%-3.7u", 3267);
	ft_printf("%-3.3u", 6983);
	ft_printf("%08.5u", 34);
	ft_printf("%08.5u", 0);
	ft_printf("%08.3u", 8375);
	ft_printf("%03.7u", 3267);
	ft_printf("%03.3u", 6983);
	ft_printf("%0-8.5u", 34);
	ft_printf("%0-8.5u", 0);
	ft_printf("%0-8.3u", 8375);
	ft_printf("%0-3.7u", 3267);
	ft_printf("%0-3.3u", 6983);
	ft_printf("%.0u", 0);
	ft_printf("%.u", 0);
	ft_printf("%5.0u", 0);
	ft_printf("%5.u", 0);
	ft_printf("%-5.0u", 0);
	ft_printf("%-5.u", 0);
	ft_printf("this %x number", 17);
	ft_printf("this %x number", 0);
	ft_printf("%x", 3);
	ft_printf("%x", 4294967295u);
	ft_printf("%7x", 33);
	ft_printf("%3x", 0);
	ft_printf("%5x", 52625);
	ft_printf("%2x", 94827);
	ft_printf("%-7x", 33);
	ft_printf("%-3x", 0);
	ft_printf("%-5x", 52625);
	ft_printf("%-4x", 9648627);
	ft_printf("%.5x", 21);
	ft_printf("%.3x", 0);
	ft_printf("%.4x", 5263);
	ft_printf("%.3x", 938862);
	ft_printf("%05x", 43);
	ft_printf("%03x", 0);
	ft_printf("%03x", 698334);
	ft_printf("%8.5x", 34);
	ft_printf("%8.5x", 0);
	ft_printf("%8.3x", 8375);
	ft_printf("%2.7x", 3267);
	ft_printf("%3.3x", 6983);
	ft_printf("%-8.5x", 34);
	ft_printf("%-8.5x", 0);
	ft_printf("%-8.3x", 8375);
	ft_printf("%-2.7x", 3267);
	ft_printf("%-3.3x", 6983);
	ft_printf("%08.5x", 34);
	ft_printf("%08.5x", 0);
	ft_printf("%08.3x", 8375);
	ft_printf("%02.7x", 3267);
	ft_printf("%03.3x", 6983);
	ft_printf("%0-8.5x", 34);
	ft_printf("%0-8.5x", 0);
	ft_printf("%0-8.3x", 8375);
	ft_printf("%0-2.7x", 3267);
	ft_printf("%0-3.3x", 6983);
	ft_printf("%.0x", 0);
	ft_printf("%.x", 0);
	ft_printf("%5.0x", 0);
	ft_printf("%5.x", 0);
	ft_printf("%-5.0x", 0);
	ft_printf("%-5.x", 0);
	ft_printf("this %X number", 17);
	ft_printf("this %X number", 0);
	ft_printf("%X", 3);
	ft_printf("%X", 4294967295u);
	ft_printf("%7X", 33);
	ft_printf("%3X", 0);
	ft_printf("%5X", 52625);
	ft_printf("%2X", 94827);
	ft_printf("%-7X", 33);
	ft_printf("%-3X", 0);
	ft_printf("%-5X", 52625);
	ft_printf("%-4X", 9648627);
	ft_printf("%.5X", 21);
	ft_printf("%.3X", 0);
	ft_printf("%.4X", 5263);
	ft_printf("%.3X", 938862);
	ft_printf("%05X", 43);
	ft_printf("%03X", 0);
	ft_printf("%03X", 698334);
	ft_printf("%8.5X", 34);
	ft_printf("%8.5X", 0);
	ft_printf("%8.3X", 8375);
	ft_printf("%2.7X", 3267);
	ft_printf("%3.3X", 6983);
	ft_printf("%-8.5X", 34);
	ft_printf("%-8.5X", 0);
	ft_printf("%-8.3X", 8375);
	ft_printf("%-2.7X", 3267);
	ft_printf("%-3.3X", 6983);
	ft_printf("%08.5X", 34);
	ft_printf("%08.5X", 0);
	ft_printf("%08.3X", 8375);
	ft_printf("%02.7X", 3267);
	ft_printf("%03.3X", 6983);
	ft_printf("%0-8.5X", 34);
	ft_printf("%0-8.5X", 0);
	ft_printf("%0-8.3X", 8375);
	ft_printf("%0-2.7X", 3267);
	ft_printf("%0-3.3X", 6983);
	ft_printf("%.0X", 0);
	ft_printf("%.X", 0);
	ft_printf("%5.0X", 0);
	ft_printf("%5.X", 0);
	ft_printf("%-5.0X", 0);
	ft_printf("%-5.X", 0);
	ft_printf("%p", NULL);
	ft_printf("%5p", NULL);
	ft_printf("%2p", NULL);
	ft_printf("%.p", NULL);
	ft_printf("%5.p", NULL);
	ft_printf("%2.p", NULL);
	ft_printf("%9.2p\n", 1234);
	ft_printf("%2.9p\n", 1234);
	ft_printf("%.5p", 0);
	ft_printf("%.0p", 0);
	ft_printf("%5p", 0);
	ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p%5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p%16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p%8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p%-70p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p%-5p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p%-16p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p%-8p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p%-32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	ft_printf("%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	ft_printf("%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c%1c%2c%3c%4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	ft_printf("%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)1,(char)2,(char)3,(char)4,(char)5,(char)6,(char)7,(char)8,(char)9,(char)10,(char)11,(char)12,(char)13,(char)14,(char)15,(char)16,(char)17,(char)18,(char)19,(char)20,(char)21,(char)22,(char)23,(char)24,(char)25,(char)26,(char)27,(char)28,(char)29,(char)30,(char)31);
	ft_printf("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	ft_printf("%c", '\0');
	ft_printf("%5c", '\0');
	ft_printf("%-5c", '\0');
	ft_printf("%1$"); 
	ft_printf("%0"); 
	ft_printf("% "); 
	ft_printf("%#"); 
	ft_printf("%-"); 
	ft_printf("%+"); 
	ft_printf("%23"); 
	ft_printf("%."); 
	ft_printf("%hh"); 
	ft_printf("%h"); 
	ft_printf("%ll"); 
	ft_printf("%l"); 
	ft_printf("%L"); 
	ft_printf("%p"); 
	ft_printf("%d"); 
	ft_printf("%u"); 
	ft_printf("%x"); 
	ft_printf("%X"); 
	ft_printf("%f"); 
	ft_printf("%c"); 
	ft_printf("%o"); 
	ft_printf("%1$s", NULL); 
	ft_printf("%0s", NULL); 
	ft_printf("% s", NULL); 
	ft_printf("%#s", NULL); 
	ft_printf("%-s", NULL); 
	ft_printf("%+s", NULL); 
	ft_printf("%23s", NULL); 
	ft_printf("%.s", NULL); 
	ft_printf("%hhs", NULL); 
	ft_printf("%hs", NULL); 
	ft_printf("%lls", NULL); 
	ft_printf("%ls", NULL); 
	ft_printf("%Ls", NULL); 
	ft_printf("%p", NULL); 
	ft_printf("%d", NULL); 
	ft_printf("%b", NULL); 
	ft_printf("%u", NULL); 
	ft_printf("%x", NULL); 
	ft_printf("%X", NULL); 
	ft_printf("%f", NULL); 
	ft_printf("%s", NULL); 
	ft_printf("%c", NULL); 
	ft_printf("%o", NULL); 
	ft_printf("%-021s", "abc");
	ft_printf("%-05s", "goes over");
	ft_printf("%04.3s%-7.4s", "hello", "world");
	ft_printf("%021s", NULL);
	ft_printf("%02s", NULL);
	ft_printf("%-021s", NULL);
	ft_printf("%-03s", NULL);
	ft_printf("%05c", '\0');
	ft_printf("%-05c", '\0');
	ft_printf("%  d", 42);
	ft_printf("%--5d", 42);
	ft_printf("%##x", 42);
	ft_printf("%.4c", 'a');
	ft_printf("%.c", 'a');
	ft_printf("%#c", 'a');
	ft_printf("%05c", 'a');
	ft_printf("%0c", 'a');
	ft_printf("% c", 'a');
	ft_printf("% c", -42);
	ft_printf("%hhc", 'a');
	ft_printf("%hc", 'a');
	ft_printf("%lc", L'a');
	ft_printf("%llc", L'a');
	ft_printf("%Lc", L'a');
	ft_printf("%-c", 'a');
	ft_printf("%#s", "hello");
	ft_printf("%05s", "hello");
	ft_printf("%0s", "hello");
	ft_printf("% s", "hello");
	ft_printf("%hhs", "hello");
	ft_printf("%hs", "hello");
	ft_printf("%ls", L"hello");
	ft_printf("%lls", L"hello");
	ft_printf("%Ls", L"hello");
	ft_printf("%-s", "hello");
	ft_printf("%.4p", &ncm_p);
	ft_printf("%.p", &ncm_p);
	ft_printf("%#p", &ncm_p);
	ft_printf("%05p", &ncm_p);
	ft_printf("%0p", &ncm_p);
	ft_printf("% p", &ncm_p);
	ft_printf("% p", &ncm_p);
	ft_printf("%hhp", &ncm_p);
	ft_printf("%hp", &ncm_p);
	ft_printf("%lp", &ncm_p);
	ft_printf("%llp", &ncm_p);
	ft_printf("%Lp", &ncm_p);
	ft_printf("%-p", &ncm_p);
	ft_printf("%Ld", 42);
	ft_printf("%#d", 42);
	ft_printf("%hhhd", 42);
	ft_printf("%hhhhd", 42);
	ft_printf("%hhld", 42);
	ft_printf("%hhlld", 42);
	ft_printf("%llhd", 42);
	ft_printf("%llld", 42);
	ft_printf("%Li", 42);
	ft_printf("%#i", 42);
	ft_printf("%hhhi", 42);
	ft_printf("%-i", 42);
	ft_printf("% o", 42);
	ft_printf("%Lo", 42);
	ft_printf("%hhho", 42);
	ft_printf("%hhhho", 42);
	ft_printf("%hhlo", 42);
	ft_printf("%hhllo", 42);
	ft_printf("%llho", 42);
	ft_printf("%lllo", 42);
	ft_printf("%-o", 42);
	ft_printf("%Lu", 42);
	ft_printf("%#u", 42);
	ft_printf("% u", 42);
	ft_printf("%hhhu", 42);
	ft_printf("%hhhhu", 42);
	ft_printf("%hhlu", 42);
	ft_printf("%hhllu", 42);
	ft_printf("%llhu", 42);
	ft_printf("%lllu", 42);
	ft_printf("%-u", 42);
	ft_printf("%Lx", 42);
	ft_printf("% x", 42);
	ft_printf("%hhhx", 42);
	ft_printf("%hhhhx", 42);
	ft_printf("%hhlx", 42);
	ft_printf("%hhllx", 42);
	ft_printf("%llhx", 42);
	ft_printf("%lllx", 42);
	ft_printf("%LX", 42);
	ft_printf("% X", 42);
	ft_printf("%hhhX", 42);
	ft_printf("%llhX", 42);
	ft_printf("%-x", 42);
	ft_printf("%hhf", 42.5);
	ft_printf("%hf", 42.5);
	ft_printf("%llf", 42.5);
	ft_printf("%lllf", 42.5);
	ft_printf("%llllf", 42.5);
	ft_printf("%LLf", 42.5);
	ft_printf("%Llf", 42.5);
	ft_printf("%lLf", 42.5);
	ft_printf("%-f", 42.5);
	ft_printf(" pouet %s !!", "camembert");
	ft_printf("%s !", "Ceci n'est pas un \0 exercice !");
	ft_printf("%s!", "Ceci n'est toujours pas un exercice !");
	ft_printf("%s!", str);
	ft_printf("%d", 42);
	ft_printf("Kashim a %d histoires à raconter", 1001);
	ft_printf("Il fait au moins %d\n", -8000);
	ft_printf("%d", -0);
	ft_printf("%d", 0);
	ft_printf("%d", INT_MAX);
	ft_printf("%d", INT_MIN);
	ft_printf("%d", INT_MIN - 1);
	ft_printf("%d", INT_MAX + 1);
	ft_printf("%%d 0000042 == |%d|\n", 0000042);
	ft_printf("%%d \t == |%d|\n", '\t');
	ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
	ft_printf("Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p", 100, "Ly", &r00);
	ft_printf("%c", 42);
	ft_printf("Kashim a %c histoires à raconter", 1001);
	ft_printf("Il fait au moins %c\n", -8000);
	ft_printf("%c", -0);
	ft_printf("%c", 0);
	ft_printf("%c\n", INT_MAX);
	ft_printf("%c\n", 'c');
	ft_printf("%c\n", '\n');
	ft_printf("%c", 'l');
	ft_printf("%c", 'y');
	ft_printf("%c", ' ');
	ft_printf("%c", 'e');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", ' ');
	ft_printf("%c", 'f');
	ft_printf("%c", 'a');
	ft_printf("%c", 'n');
	ft_printf("%c", 't');
	ft_printf("%c", 'a');
	ft_printf("%c", 's');
	ft_printf("%c", 't');
	ft_printf("%c", 'i');
	ft_printf("%c", 'q');
	ft_printf("%c", 'u');
	ft_printf("%c", 'e');
	ft_printf("%c\n", '!');
	ft_printf("%c\n", '\r');
	ft_printf("%c\n", '\t');
	ft_printf("%i", 42);
	ft_printf("Kashim a %i histoires à raconter", 1001);
	ft_printf("Il fait au moins %i\n", -8000);
	ft_printf("%i", -0);
	ft_printf("%i", 0);
	ft_printf("%i", INT_MAX);
	ft_printf("%i", INT_MIN);
	ft_printf("%i", INT_MIN - 1);
	ft_printf("%i", INT_MAX + 1);
	ft_printf("%%i 0000042 == |%i|\n", 0000042);
	ft_printf("%%i \t == |%i|\n", '\t');
	ft_printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');
	ft_printf("%u", 42);
	ft_printf("Kashim a %u histoires à raconter", 1001);
	ft_printf("Il fait au moins %u\n", -8000);
	ft_printf("%u", -0);
	ft_printf("%u", 0);
	ft_printf("%u", INT_MAX);
	ft_printf("%u", INT_MIN);
	ft_printf("%u", INT_MIN - 1);
	ft_printf("%u", INT_MAX + 1);
	ft_printf("%%u 0000042 == |%u|\n", 0000042);
	ft_printf("%%u \t == |%u|\n", '\t');
	ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');
	ft_printf("%x", 42);
	ft_printf("Kashim a %x histoires à raconter", 1001);
	ft_printf("Il fait au moins %x\n", -8000);
	ft_printf("%x", -0);
	ft_printf("%x", 0);
	ft_printf("%x", INT_MAX);
	ft_printf("%x", INT_MIN);
	ft_printf("%x", INT_MIN - 1);
	ft_printf("%x", INT_MAX + 1);
	ft_printf("%%x 0000042 == |%x|\n", 0000042);
	ft_printf("%%x \t == |%x|\n", '\t');
	ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	ft_printf("%%04i 42 == |%04i|\n", 42);
	ft_printf("%%05i 42 == |%05i|\n", 42);
	ft_printf("%%0i 42 == |%0i|\n", 42);
	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);
	ft_printf("%%-i 42 == %-i\n", 42);
	ft_printf("%%-d 42 == %-d\n", INT_MIN);
	ft_printf("%%-i -42 == %-i\n", -42);
	ft_printf("%%-4d 42 == |%-4d|\n", 42);
	ft_printf("%%-5d -42 == |%-5d|\n", -42);
	ft_printf("|%3i|%-3i|\n", 42, 42);
	ft_printf("%%-4i 42 == |%-4i|\n", 42);
	ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	ft_printf("%%*i 42 == |%*i|\n", 5, 42);
	ft_printf("%%*i 42 == |%*i|\n", 3, 42);
	ft_printf("%%*i 42 == |%*i|\n", 2, 42);
	ft_printf("%*s", 32, "abc");
	ft_printf("%-*s", 32, "abc");
	ft_printf("%*s", 3, "hello");
	ft_printf("%.*s", 3, "hello");
	ft_printf("%.*s", 0, "hello");
	ft_printf("%-*.*s", 7, 3, "yolo");
	ft_printf("%*i", 4, 94827);
	ft_printf("%*i", 14, 94827);
	ft_printf("%.*i", 6, -3);
	ft_printf("%0*i", 7, -54);
	ft_printf("%*s", -32, "abc");
	ft_printf("%-*s", -32, "abc");
	ft_printf("%*s", -3, "hello");
	ft_printf("%.*s", -3, "hello");
	ft_printf("%-*.*s", -7, -3, "yolo");
	ft_printf("%*i", -4, 94827);
	ft_printf("%*i", -14, 94827);
	ft_printf("%.*i", -6, -3);
	ft_printf("%0*i", -7, -54);
	ft_printf("\n\n\n");
	ft_printf("***********************\n");
	ft_printf("******END****TEST******\n");
	ft_printf("***********************\n");
	ft_printf("******LEAK REPORT******\n");
	ft_printf("***********************\n");
	ft_printf("\n\n\n");

	ft_printf("ft_printf:\n");
	ft_printf("u: %u %u %u %u %u %u %u %u %u %u %u %u\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	ft_printf("i: %i %i %i %i %i %i %i %i %i %i %i %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	ft_printf("d: %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	ft_printf("p: %p %p %p %p %p %p %p %p %p %p %p %p\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	ft_printf("x: %x %x %x %x %x %x %x %x %x %x %x %x\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	ft_printf("sys_printf:\n");
	printf("u: %u %u %u %u %u %u %u %u %u %u %u %u\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	printf("i: %i %i %i %i %i %i %i %i %i %i %i %i\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	printf("d: %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	printf("p: %p %p %p %p %p %p %p %p %p %p %p %p\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
	printf("x: %x %x %x %x %x %x %x %x %x %x %x %x\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
//	ft_printf("%09s", "hi Low");
	system("leaks -fullContent  a.out");
	return 0;
}
