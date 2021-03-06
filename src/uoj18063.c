/*

**************************************
18063 圈中的游戏
**************************************
Description

有n个人围成一圈，从第1个人开始报数1、2、3，每报到3的人退出圈子。编程使用链表找出最后留下的人。
**************************************
Input

输入一个数n，1000000>=n>0 
**************************************
Output

输出最后留下的人的编号
**************************************
Sample Input

3


**************************************
Sample Output

2
**************************************
Author0*/
#include "stdio.h"
//todo
long long data[1000000];
int main(int argc, char const *argv[])
{
	long long n,m=3;
	scanf("%lld",&n);
	
	data[1]=1;
	for (long long i = 2; i <= n; ++i)
		data[i] = (data[i-1]+m-1)%i + 1;
	printf("%lld\n",data[n]);
	return 0;
}