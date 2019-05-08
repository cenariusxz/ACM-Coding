#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

char s[1000];
string str[10];
int pos=0;

void init(){
	for(int i=0;i<10;++i)str[i].clear();
	pos=0;
}

void read1(){
	for(;s[pos];++pos){
		if(s[pos]=='('||s[pos]=='['||s[pos]=='{')break;
	}

	if(s[pos]=='{'){
		for(;s[pos];++pos){
			if(s[pos]=='}'){
				++pos;
				return;
			}
			if(s[pos]=='{')continue;
			str[1]+=s[pos];
		}
	}
	if(s[pos]=='('){
		for(;s[pos];++pos){
			if(s[pos]==')'){
				++pos;
				return;
			}
			if(s[pos]=='(')continue;
			str[2]+=s[pos];
		}
	}
	if(s[pos]=='['){
		for(;s[pos];++pos){
			if(s[pos]==']'){
				++pos;
				return;
			}
			if(s[pos]=='[')continue;
			str[3]+=s[pos];
		}
	}
}

bool read2(){
	for(;s[pos];++pos){
		if(s[pos]=='('||s[pos]=='['||s[pos]=='{')return 1;
		str[4]+=s[pos];
	}
	return 0;
}

int main(){
	init();
	gets(s);
	read1();
	read1();
	read1();
	if(str[1][0]>='a'&&str[1][0]<='z'){
		str[1][0]=str[1][0]-'a'+'A';
	}
	if(str[2][0]>='A'&&str[2][0]<='Z'){
		str[2][0]=str[2][0]-'A'+'a';
	}
	if(str[3][0]>='A'&&str[3][0]<='Z'){
		str[3][0]=str[3][0]-'A'+'a';
	}
	cout<<str[1]<<' '<<str[2]<<' '<<str[3];
	bool f=read2();
	cout<<str[4];
	if(f){
		for(int i=0;i<10;++i)str[i].clear();
		read1();
		read1();
		read1();
		if(str[1][0]>='A'&&str[1][0]<='Z'){
			str[1][0]=str[1][0]-'A'+'a';
		}
		if(str[2][0]>='A'&&str[2][0]<='Z'){
			str[2][0]=str[2][0]-'A'+'a';
		}
		if(str[3][0]>='A'&&str[3][0]<='Z'){
			str[3][0]=str[3][0]-'A'+'a';
		}
		cout<<str[1]<<' '<<str[2]<<' '<<str[3]<<endl;

	}
	else cout<<endl;

}
