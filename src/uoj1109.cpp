#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

map <string ,int> dict;
bool end=false;
//debug
#ifdef LOCAL
#define fp stdin 
#else
FILE *fp;
#endif

char last=0;
char ch;

struct node{
	string s;
	int count;
}
struct{
	int mincount;
	string min;
	char count;

	priority_queue<node,vector<node>,cmp>pq;

	void push(string str){
		if(dict[str]>mincount){
			mincount=dict[str];
		
			
			
		}
	}
}listt;
string getword(){
	
	string s;

	if (last){
		s.push_back(last);
		last=0;
	}

	while((ch=getc(fp))!=EOF){
		//printf("is :%c\n",ch);
		if(ch=='-'){

			if((ch=getc(fp))=='\n'){
				continue;
			}else{
				last=ch;
				break;
			}

		}

		if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z')
			s.push_back(ch);
		else
			break;

	}

	if(ch==EOF) end=true;

	transform(s.begin(), s.end(), s.begin(), (int (*)(int))tolower);  
	return s;
}
void printdict(){
	map <string, int>::iterator dit;
	 for ( dit = dict.begin( ); dit != dict.end( ); dit++ ){
	 	cout<<dit->first<<"="<<dit->second<<endl;
	 }
}
int main(int argc, char const *argv[])
{
	#ifndef LOCAL
	fp=fopen("case1.in","r");
	#else
	printf("used LOCAL");
	#endif
	string word;

	while(!end){
		word=getword();
		if(!dict.count(word)) dict[word]=1;
		else{
			dict[word]++;
		}

		cout<<word<<endl;
	}
	printdict();

	return 0;
}


