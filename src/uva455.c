#include "stdio.h"
#include "string.h"
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		char s[81];
		scanf("%s",s);
		int len=strlen(s);
		int j;
		for (int i = 0; i <len; ++i)
		{
			for (j = 0; j < len-i; ++j)
			{
				if(s[j]!=s[j+i]) break;
			}
			if(j==len-i){
				printf("%d\n",i);
				break;
			}
		}

	}
	return 0;
}