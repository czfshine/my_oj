/*

**************************************
1017 求数的位数
**************************************
Description
由键盘输入一个不多于9位的正整数，要求输出它是几位数。
**************************************
Input
一个整数
**************************************
Output
输出该数为几位数
**************************************
Sample Input
349213
**************************************
Sample Output
6
**************************************
Author0*/
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	char data[10];
	scanf("%s",data);
	printf("%d",strlen(data));

	return 0;
}