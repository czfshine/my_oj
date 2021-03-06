#include <stdio.h>  
#include <math.h>  
int pc[100001], p[100001] ;
int count = 1,T,m;  

int Prime(int n)  
{  
    int tmp =sqrt(n);  
    for (int i = 0; p[i] <= tmp; ++i) {  
        if (n % p[i] == 0)  
            return 0;  
    }  
    return 1;  
}  
int main()  
{  
    p[0] = 2;  
    pc[2] = 1;  
    for (int i = 3; i <= 100000; ++i) {  
        if (Prime(i))  
            p[count++] = i;
        pc[i] = count;  
    }  
    scanf("%d", &T);  
    while (T--) {   
        scanf("%d", &m);  
        printf("%d\n", pc[m]);  
    }  
    return 0;  
}  
