#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
char s[1000005];
int next[1000005],flag,len;

void getnext(){
	int k=1,j=0;
	next[k]=0;
	while(k<=len+1){
		if(j==0||s[k]==s[j]){
			++j,++k;
			next[k]=j;
		}
		else j=next[j];
	}
}

string text1(){
	int t=0,i;
	vector<int>v;
	len=strlen(&s[1]);
	getnext();
	int tem=len;
	v.clear();
	while(next[tem+1]>1){
		v.push_back(len+1-next[tem+1]);
		tem=next[tem+1]-1;
	}
	v.push_back(len);
	string ans="Case #";
	ans+=(char)(++t+'0');
	ans+=": ";
	ans+=(char)(v.size()+'0');
	ans+='\n';
	for(i=0;i<v.size();i++)
		if(i==0)ans+=(char)(v[i]+'0');
		else{
			ans+=" ";
			ans+=(char)(v[i]+'0');
		}
	ans+='\n';
	return ans;
}

const int maxm=1e6+5;

int p[maxm];    //自匹配数组
int ans[maxm];
char T[maxm];

string text2(){
	int c=0;
	int i,j;
	strcpy(T,s+1);
	int m=strlen(T);
	p[0]=p[1]=0;    //初始化自匹配数组
	for(i=1;i<m;i++){    //自匹配
		j=p[i];
		while(j&&T[i]!=T[j])j=p[j];
		p[i+1]=T[i]==T[j]?j+1:0;
	}
	int per=m-p[m];
	int cnt=0;
	for(int i=1;i*per<=m;++i)ans[++cnt]=i*per;
	if(ans[cnt]<m)ans[++cnt]=m;
	string aa="Case #";
	aa+=(char)(++c+'0');
	aa+=": ";
	aa+=(char)(cnt+'0');
	aa+='\n';
	for(int i=1;i<=cnt;++i){
		aa+=(char)(ans[i]+'0');
		if(i==cnt)aa+='\n';
		else aa+=' ';
	}
	return aa;
}

int main(){
	int c=50;
	srand(time(NULL));
	while(scanf("%s",s+1)!=EOF){
		string a1=text1();
		string a2=text2();
		if(a1==a2)printf("AC\n");
		else{
			printf("WA\n");
			printf("%s\n",s+1);
			cout<<a1<<a2;
			break;
		}
	}/*
	while(c--){
		for(int i=1;i<=30;++i){
			s[i]=rand()%26+'a';
		}
		s[6]=0;
		string a1=text1();
		string a2=text2();
		if(a1==a2)printf("AC\n");
		else{
			printf("WA\n");
			printf("%s\n",s+1);
			cout<<a1<<a2;
			break;
		}
	}*/
	return 0;
}
