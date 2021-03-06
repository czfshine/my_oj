/*

**************************************
8629 热身游戏
**************************************
Description

    ACM 程序设计竞赛是一项激励人心的竞赛，除了考验大家的编程功底，更多的是考验大家的思维以

及数学运算能力。开赛前15分钟，我们华农的某队开始了以下对话：

ipc：“我们玩接龙热一下身吧！免得一会没睡醒。”

Arokenda：“好啊！没问题！怎么玩？”

ipc：“我先写两个数，然后你我轮流接着已经写好的数列继续写数，每人写1 个数。接龙的规则就是，

下一个数是前两个数的和。”

Arokenda：“这还不简单！不就是Fibonacci数列嘛。绝对秒杀啦！”

    此时，ipc 开始写数：1、3。居然不是Fibonacci 数列！下一个就是4 啦！接着数列成型了：1、3、

4、7、11、18……一直写了N 项，ipc 觉得热身还不够。于是他忽然说了句：“求前N 项和怎么样？”两

个人顿时“卡”了一下……

若ipc写出数列的前两项以及项数，你能算出来吗？


**************************************
Input

输入一个整数T(T<=20)，表示ipc写了T个数列。

接下来T行， 每行三个整数， 分别为a1,a2,n ， 分别表示该数列的前两项和项数。其中0<a1,a2,n<=1000


**************************************
Output每组数据输出一行，该数列的前n项和sum(n)。
**************************************
Sample Input

3

1 2 15

1 1 10

2 2 10


**************************************
Sample Output

2582

143

286


**************************************
Hint
**************************************
Source
**************************************
Author0*/
#include "stdio.h"
#include <math.h>
//广义斐波那契数列求和
//233333333
int main(int argc, char const *argv[])
{
	//输入框架：
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		long a,b,N;
		scanf("%d %d %d",&a,&b,&N);

		double P,T,S;
		P=0.4472136*pow(1.618034,N);
		T=0.4472136*pow(1.618034,N+1)-1;
		S=a*P+T*b;
		printf("%d\n",(long)floor(S));
	}
	return 0;
}