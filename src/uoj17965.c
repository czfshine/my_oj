/*

**************************************
17965 幸运之星（必做）
**************************************
Description

每年新年派对的最后一个节目就是选出下年的“幸运之星”，有丰厚的大礼包的噢~~。  O(∩_∩)O

所以每位参加派对的人士都摩拳擦掌跃跃欲试。选择的办法是这样约定的：



（1）所有参与的人员数n，让n个人一字排开，然后至左向右从1开始报数，凡报到奇数号的全部后退剔除，剩下的人员，

又至左向右报数，逢奇剔除，如此不断的递归下去，直至只有一个人为止，这个人就是“幸运之星”。



（2）所有参与的人员数n，先随机抽取一个m值（从黑暗小箱中随机摸一个，m可能比n小或相等，也可能大于n），所有

参与的人员列成环形，然后从位置1开始报数，凡报到m的倍数的人后退剔除，剩下的人员，从刚才位置继续报数，逢m的

倍数的人剔除，如此不断的递归下去，直至只有一个人为止，这个人就是“幸运之星”。 如：n=8,m=4，如下图所示，幸

运之星为6号。




**************************************
Input





现在，请你分析上面两种节目方式，若想获得幸运大礼包，应该选哪个初始编号的位置来站？



注意此题设置的时限很短，也就不建议你采用队列或循环列表去模拟这个剔除的过程而得到最后的解答。这里，我们更应

该分析一下，这个问题的递归思路。有了分析的递归公式，就可以在很短时间内完成“幸运之星”的计算。


**************************************
Output

输入：n和m（m只和第二个问题有关，与第一个问题无关）。

n和m的范围：n,m <1000000。  
**************************************
Sample Input

输出：幸运之星游戏未开始剔除之前的最初的编号。（1）题和（2）题的解，中间空格相连。
**************************************
Sample Output

8 4
**************************************
Hint

8 6
**************************************
Author

0*/
#include "stdio.h"
//todo
int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	int data[n+1];
	long long t=1;
	while(1){
		if(n<t)
			break;
		t=t<<1;
	}
	t=t>>1;
	printf("%d ",t);
	data[1]=1;
	for (int i = 2; i <= n; ++i)
		data[i] = (data[i-1]+m-1)%i + 1;

	printf("%d",data[n]);
	return 0;
}
