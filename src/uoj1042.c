/*

**************************************
1042 百万富翁
**************************************
Description

一个百万富翁遇到一个陌生人，陌生人找他谈了一个换钱的计划。该计划如下：我每天给你m元，

而你第一天只需给我一分钱。第二天我仍给你m元，你给我2分钱。第三天，我仍给你m元，

你给我4分钱。依次类推，你每天给我的钱是前一天的两倍，直到一个月(30天)。

百万富翁很高兴，欣然接受这个契约。现要求，编写一个程序，由键盘输入m，

计算多少天后，百万富翁开始亏钱。
**************************************
Sample Input

100
**************************************
Sample Output

18
**************************************
Author0*/
#include "stdio.h"
int main(int argc, char const *argv[])
{
	int m,sum_m=0,sum_b=0,day=0,b=1;
	scanf("%d",&m);
	sum_m+=m;
		sum_b+=b;
		b*=2;
		day++;
	while(sum_b<=sum_m*100){
		sum_m+=m;
		sum_b+=b;
		b*=2;
		day++;
	}
	printf("%d",day);
	return 0;
}