#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
using namespace std;

map <string ,int> Dict;
bool end=false;
//debug
#ifdef LOCAL
#define fp stdin 
#else
FILE *fp;
#endif

char last=0;
string getword(){
	char ch;
	string s;
	if (last)
		s.push_back(ch);
	while((ch=getc(fp))!=EOF){
		printf("is :%c\n",ch);
		if(ch=='-'){

			if(getc(fp)=='\n'){
				continue;
			}else{
				fseek(fp,ftell(fp)-1,SEEK_CUR);
				break;
			}
		}

		if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z')
			s.push_back(ch);
		else
			break;
	}
	if(ch==EOF) end=true;
	return s;
}
int main(int argc, char const *argv[])
{
	#ifndef LOCAL
	fp=fopen("case1.in","r");
	#else
	printf("used LOCAL");
	#endif

	while(!end)
	cout << getword()<<endl;
	return 0;
}


