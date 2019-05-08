#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;

const int maxn=1e4+5;

struct ss{
	string str;
	int num;
	bool operator < (const ss a)const{
		if(num==a.num)return str<a.str;
		return num>a.num;
	}
}s[maxn];

char w[1005];

void read(){
	char c=getchar();
	while((c<'a'||c>'z')&&(c<'A'||c>'Z')&&c!='<')c=getchar();
	if(c=='<'){
		w[0]=c;
		scanf("%s",w+1);
	}
	else{
		int cnt=0;
		if(c>='A'&&c<='Z')c=c-'A'+'a';
		
		w[cnt++]=c;
		c=getchar();
		while((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
			if(c>='A'&&c<='Z')c=c-'A'+'a';
			w[cnt++]=c;
			c=getchar();
		}
		w[cnt++]=0;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int cnt=0;
		map<string,int>m1;
		scanf("%s",w);
		while(scanf("%s",w)){
			if(w[0]=='<')break;
			int l=strlen(w);
			for(int i=0;i<l;++i){
				if(w[i]>='A'&&w[i]<='Z')w[i]=w[i]-'A'+'a';
			}
			string tmp=string(w);
			m1[tmp]++;
		}
		map<string,int>m2;
		read();
		while(1){
			read();
			if(w[0]=='<')break;
			string tmp=string(w);
			if(m1[tmp])continue;
			else m2[tmp]++;
		}
		map<string,int>::iterator it;
		for(it=m2.begin();it!=m2.end();++it){
			++cnt;
			s[cnt].str=it->first;
			s[cnt].num=it->second;
		}
		sort(s+1,s+cnt+1);
		for(int i=1;i<=min(10,cnt);++i){
			cout<<s[i].str<<endl;
		}
		printf("\n");
	}
	return 0;
}
