#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

string model[15];
string tmp;
char s[10005];
char change[500];
int l,vis[500];
ll k,nine[20];

void init(){
	model[1]="a";
	for(int i=2;i<=13;++i){
		model[i]=model[i-1]+(char)('a'-1+i)+model[i-1];
	}
	nine[0]=1;
	for(int i=1;i<=15;++i)nine[i]=nine[i-1]*9;
}

bool Pre1(){
	memset(change,0,sizeof(change));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<l;++i){
		if(s[i]!='?')change[tmp[i]]=s[i];
	}
	for(int i=0;i<l;++i){
		if(change[tmp[i]]!=0)tmp[i]=change[tmp[i]];
	}
	if(tmp[0]=='0')return 1;
	for(int i=0;i<l;++i){
		if(s[i]!='?'&&s[i]!=tmp[i])return 1;
	}
	for(int i=0;i<l;++i){
		s[i]=tmp[i];
		if(s[i]>='0'&&s[i]<='9')vis[s[i]]=1;
	}
	return 0;
}

bool solve(){
	vector<int>v;
	int tmp=0;
	while(1){
		int len=(1<<tmp)-1;
		if(len>l-1)break;
		if(s[len]>='a'&&s[len]<='z')v.push_back(len);
		tmp++;
	}
	if(v.size()==0){
		if(k!=1)return 1;
	}
	bool f=1;
	for(int i=0;i<v.size();++i){
		if(!f)return 1;
		f=0;
		if(v[i]==0){
			for(char j='1';j<='9';++j){
				if(vis[j])continue;
				if(k>nine[v.size()-1])k-=nine[v.size()-1];
				else{
					f=1;
					change[s[0]]=j;
					break;
				}
			}
		}
		else{
			for(char j='0';j<='9';++j){
				if(j==change[s[0]]||j==s[0])continue;
				if(k>nine[v.size()-i-1])k-=nine[v.size()-i-1];
				else{
					f=1;
					change[s[v[i]]]=j;
					break;
				}
			}
		}
	}
	for(int i=0;i<l;++i){
		if(s[i]>='a'&&s[i]<='z'){
			if(change[s[i]]==0)return 1;
			s[i]=change[s[i]];
		}
	}
	if(s[0]>='a'&&s[0]<='z')return 1;
	if(s[0]=='0')return 1;
	for(int i=1;i<l;++i){
		if(s[i]==s[i-1]||(s[i]>='a'&&s[i]<='z'))return 1;
	}
	return 0;
}

int main(){
	init();
	while(scanf("%lld",&k)!=EOF&&k){
		scanf("%s",s);
		l=strlen(s);
		bool f=0;
		for(int i=1;i<=13;++i){
			if(l==model[i].length()){
				tmp=model[i];
				f=1;
				break;
			}
		}
		if(!f){				//判长度是否能符合
			printf("-1\n");
			continue;
		}

		if(Pre1()){
			printf("-1\n");
			continue;
		}

		if(solve()){
			printf("-1\n");
			continue;
		}

		printf("%s\n",s);
	}
	return 0;
}
