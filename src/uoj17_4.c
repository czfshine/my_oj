#include "stdio.h"

int main(int argc, char const *argv[])
{
	char data[201]={0};
	data[0]=1;
	data[1]=1;
	data[2]=0;


	for (int i = 2; i < 201; ++i)
	{
		if(!data[i]){
			for (int j = i+1; j < 201; ++j)
			{
				if(j%i==0) data[j]=1;
			}
		}
	}

	for (int i = 2; i < 201; ++i)
	{
		if(!data[i])
			printf("%d\n",i);
	}
	return 0;
}