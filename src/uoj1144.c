/*

**************************************
1144 数星星
**************************************
Description

天文学家们喜欢观察星星。它们把每颗星星看成一个点，并把每颗星星左下方（即横坐标和纵坐标都不比它大）的星星颗数作为它的等级值。

现给出所有星星（星星个数为N）的坐标，计算并输出指定编号的星星的等级。



注意：不存在相同坐标的星星
**************************************
Input

第一行为N

后N行为编号为1到N的星星的坐标（坐标用整数）

此后是M

后一行是M个星星的编号



N<=100000

M<=1000



坐标范围0<=x,y<=1000000
**************************************
Output

要求依次输出这M个星星的等级，一行一个
**************************************
Sample Input

5

0 0

2 0

3 0

1 1

2 2

2

4 5


**************************************
Sample Output

1

3


**************************************
Author0*/
#include <stdio.h>
 main(){

	long data[100000][2]={{0},{0}};

	long N;
	scanf("%d",&N);
	for(long i=0;i<N;i++)
		scanf("%d %d",&data[i][0],&data[i][1]);
	long M;
	scanf("%d",&M);
	long temp;
	long x,y;
	long level =0;
	for (long i=0;i<M;i++){
		scanf("%d",&temp); 
		x=data[temp-1][0];
		y=data[temp-1][1];
		level=0;
		for(long j=0;j<N;j++){
			if(data[j][0]<=x&& data[j][1]<=y){
				level++;
			}
		}
		printf("%d\n",level-1);
	}
}

