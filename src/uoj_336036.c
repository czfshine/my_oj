#include "stdio.h"
#include "math.h"

int main(int argc, char const *argv[])
{
	double d,p,r;

	scanf("%lf%lf%lf",&d,&p,&r);

	if(d==0){
		printf("0.0\n");
		return 0;
	}

	if(p<d*r ||p/(p-d*r)<1)
		printf("God\n");
	else{
		double m=0;
	
	m=log(p/(p-d*r))/log(1+r);
		printf("%.1lf\n",m);}
	return 0;
}