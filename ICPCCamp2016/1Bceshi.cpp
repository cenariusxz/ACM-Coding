#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;

int vis[maxn];

int main(){
	for(int n=1;n<=1000;++n){
		memset(vis,0,sizeof(vis));
		int ans=0;
		for(int i=1;i<=n;++i){
			if(vis[i])continue;
			int pre=i;
			int cnt=1;
			vis[pre]=1;
			while(pre*2+2<=n){
				pre=pre*2+2;
				vis[pre]=1;
				cnt++;
			}
			ans+=(cnt+1)/2;
		}
		int ans2=n*2/3;
		if(n%3)ans2++;
		if(ans!=ans2)printf("%d: %d %d\n",n,ans,ans2);
	}
	return 0;
}
