#include <cstdio>
#include <cstdlib>
#include <iostream>
#define  MAXSTRLEN  255                   // 用户可在255以内定义最大串长
typedef unsigned char SString[MAXSTRLEN+1];	// 0号单元存放串的长度

void get_next(SString T,int next[]){

	int i=1,j;
	next[1]=0;
	j=0;
	while(i<T[0]){	

		if(j == 0 || T[i]==T[j]){
			++i;
			++j;

			//if(T[i]!=T[j]){
				next[i]=j;
			//}else{

			//	next[i]=next[j];
			//} 
		}

		else
			j=next[j];	
	}
}



int Index_KMP(SString S,SString T,int pos){
// 算法4.6
// 利用模式串T的next函数求T在主串S中第pos个字符之后的位置
// KMP算法。请补全代码
	int i=pos,j=1;
	int next[2000]={0};
	get_next(T,next);

	while(i<=S[0] &&j<=T[0]){
		printf("%d",j);
		if(j==0 || S[i] == T[i]){
			++i;
			++j;

		}else{

			j=next[j];
		}

	}
	printf("%d",j);
	if(j>T[0]) return  i-T[0];
	return 0;
}
int main()
{
	SString T,S;
 	int i,j,n;
 	char ch;
 	int pos;
 	scanf("%d",&n);    // 指定n对需进行模式匹配的字符串
	ch=getchar();
	for(j=1;j<=n;j++)
	{
		ch=getchar();
 		for( i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // 录入主串
  		{
			S[i]=ch;
  			ch=getchar();
		}
		S[0]=i-1;    // S[0]用于存储主串中字符个数
		ch=getchar();
		for( i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // 录入模式串
		{
  			T[i]=ch;
  			ch=getchar();
		}
		T[0]=i-1;    // T[0]用于存储模式串中字符个数
		pos=Index_KMP(S,T,1);    // 请填空
		printf("%d\n",pos);
	}
}