/*

**************************************
1122 字符串的合并
**************************************
Description

从键盘输入3个字符串（每个字符串以回车符做为结束标志），将3个字符串以输入先后顺序合并到字符串s中，

请填空使用程序完整。
**************************************
Sample Input

123

abc

456


**************************************
Sample Output

123abc456
**************************************
Author0*/
#include "stdio.h"
#include "string.h"
main()
{
    char s[100]="";
    char a[30];
    int cur=0;
    int i,j,c=0;
    char ch;
    for(i=0;i<3;i++)  {
        while((ch=getchar())!='\n'){
            a[c++]=ch;
        }
        a[c]='\0';
        c=0;
        for (j=0;j<strlen(a);j++){
            s[cur++]=a[j];
        }
    }
    s[cur] ='\0';
    printf("%s", s);
}

