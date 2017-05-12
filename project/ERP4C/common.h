#ifndef COMMON_H

#define COMMON_H 
#define MAKE(type) (type * ) malloc(sizeof(type));

#define LOOP(fn) while(!fn()){};
int DEBUG = 0;
#ifdef LOCAL
DEBUG = 1;
#endif 

#define WithDebug(code) do{\
	if(DEBUG){\
		int oldstdout = dup(1);\
		freopen("testin1.txt", "r", stdin);\
		freopen("testout1.txt", "w", stdout);\
		code;\
		freopen("CON", "r", stdin);\
		freopen("CON", "w", stdout);\
		dup2(oldstdout, 1);} \
	else {\
			code;\
		}\
}while (0);



#endif