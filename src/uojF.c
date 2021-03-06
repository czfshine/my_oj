#include "stdio.h"
#include "string.h"

#define min(x,y) x<y?x:y

char  str[31];
int end=0;

int is_p(int n)
{
    for(int i = 2; i * i <= n; i++) if(n % i == 0) return 0;
    return 1;
}

int tonum(int s,int c){
	int l=0;
	for (int i = s; i <= c; ++i)
		l=l*10+str[i]-'0';
	return l;
}
int ok=0,no=0;
int find(int cur){
	for (int i = cur; i <=end; ++i)
	{
		if(i-cur>=6)
		{
			no=1;
			return -1;
		}
		if(is_p(tonum(cur,i))){
			if(i==end){
				if(!ok) printf("YES");
				ok=1;
				return 1;
			}else{
				find(i+1);
			}	
		}
		
	}
}

int main(int argc, char const *argv[])
{	
	scanf("%s",str);
	end=strlen(str)-1;
	find(0);
	if(!ok)
		printf("NO");
	return 0;
}

