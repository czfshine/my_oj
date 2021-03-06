/*

**************************************
18062 二维数组每行中的最大值
**************************************
Description

输入一个4*4的二维整型数组，使用指针变量查找并输出二维整型数组中每一行的最大值。
**************************************
Input

4*4的整数矩阵
**************************************
Output

每行最大值，一行一个
**************************************
Sample Input

1 2 3 4

8 7 6 5

1 1 1 1

2 2 2 2


**************************************
Sample Output

4

8

1

2


**************************************
Author0*/
#include <stdio.h> 

void find(int a[][4]) 
{ 
    int (*p)[4], *q, *max; 
    for(p=&a[0];p<a+4;p++) 
    { 
        max=*p; 
        for(q=*p;q<*p+4;q++) 
        	if(*q>*max) max=q;

        printf("%d\n", *max); 
    } 
} 

int main() 
{ 
    int a[4][4],i,j; 
    for(i=0; i<4; i++) 
        for(j=0; j<4; j++) 
            scanf("%d", &a[i][j]); 
    find(a); 
    return 0; 
} 