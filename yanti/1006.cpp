#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<iostream>
using namespace std;

const int maxn=1e4+5;

int prime[maxn];
int vis[maxn];
int v[15];
int cnt=0;
string res[1000];

void Pre(){
	cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=10000;++i){
		if(!vis[i])prime[cnt++]=i;
		for(int j=0;j<cnt&&i*prime[j]<=10000;++j){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}

int main(){
	Pre();
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int ans=0x3f3f3f3f,c=0;
		for(int i=0;i<cnt&&prime[i]<=n/2;++i){
			int tmp1=prime[i];
			int tmp2=n-prime[i];
			if(tmp2<=1)continue;
			if(!vis[tmp2]){
				memset(v,0,sizeof(v));
				while(tmp1){
					int b=tmp1%10;
					tmp1/=10;
					v[b]=1;
				}
				while(tmp2){
					int b=tmp2%10;
					tmp2/=10;
					v[b]=1;
				}
				int tmp=0;
				for(int i=0;i<=9;++i)if(v[i])tmp++;
				if(tmp<ans){
					c=0;
					string t;
					for(int i=0;i<=9;++i)if(v[i])t+=i+'0';
					res[++c]=t;
					ans=tmp;
				}
				else if(tmp==ans){
					string t;
					for(int i=0;i<=9;++i)if(v[i])t+=i+'0';
					res[++c]=t;
				}
			}
		}
		sort(res+1,res+c+1);
		cout<<res[1]<<endl;
	}
	return 0;
}
