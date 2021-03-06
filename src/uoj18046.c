/*

**************************************
18046 字母分类统计
**************************************
Description

输入一行以换行符结束的字符，统计并输出其中英文字母、数字、空格和其它字符的个数。
**************************************
Input

一行字符，以换行符结束
**************************************
Output

一行4个数字分别为：英文字母、数字、空格和其它字符的个数，两数据之间以一个空格分隔
**************************************
Sample Input

ABC 456!
**************************************
Sample Output

3 3 1 1


**************************************
Author0*/
#include "stdio.h"

int main(int argc, char const *argv[])
{
	int ca=0,cn=0,ck=0,co=0;
	char ch;
	while((ch=getchar())!='\n'){
		if(ch>='A' && ch<='Z' || ch >='a' && ch<='z'){
			ca++;
		}else{
			if(ch>='0' && ch<='9'){
				cn++;
			}else{

				if(ch==' '){
					ck++;
				}else{
					co++;
				}
			}
		}
	}

	printf("%d %d %d %d",ca,cn,ck,co);
	return 0;
}