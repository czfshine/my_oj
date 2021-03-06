/*

**************************************
8593 最大覆盖问题
**************************************
Description

第1行是正整数n，(n<=10000)

第2行是整数序列 a1   a2   ...   an


**************************************
Input计算出的最大覆盖区间长度
**************************************
Output10

1 6 2 1 -2 3 5 2 -4 3
**************************************
Sample Input5
**************************************
Sample Output


**************************************
Hint

若依次去求出每个数的最大覆盖长度，则必须有两个嵌套的循环，时间复杂度为O(n^2)。

但此处求所有数的一个最大覆盖长度，倒没有必要每个数的最大覆盖长度都求出来。



初始时，用两个指针i和j指向串末，当ai和aj的关系满足不等式时，j不动，i往左

走，……，直到不等式不满足，记录下长度。

下一步j往左移一个，i不回退，继续上面的比较，若找到更长的覆盖长度，更新。

每循环一次要么i要么j少1；最后i=-1,j=0;共进行了2(n-1)次。所以时间复杂度为O(n)。


**************************************
Author0*/
#include "stdio.h"
#define max(x,y) (x)>(y)?x:y
#include "stdlib.h"
#include "math.h"
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int data[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",data+i);
	}
	int count=0,c=0;
	int *p,*q;
	for (p =data+n-1; p >=data; --p)
	{	count=0;
		for (q=p;q>=data;--q)
		{
			if(*q<=abs(*p)){
				count++;
			}else{
				break;
			}
		}
		c=max(count,c);
	}

	printf("%d",c);


	return 0;
}