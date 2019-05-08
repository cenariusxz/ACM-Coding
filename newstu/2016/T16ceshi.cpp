#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=1000033;

int ans[1200055],T;
int vis[1200055];
ll k;

int main(){
	ll mul=10000,sub=33;
	memset(ans,0,sizeof(ans));
	ll res=9967;
	for(int i=1;i<=1000050;++i){
		if(ans[res]){
			printf("%d %d %lld\n",ans[res],i,res);
			break;
		}
		ans[res]=i;
		res=((res-sub)*mul%mod+mod)%mod;
	}
	for(int i=1;i<=1000000;++i){
		if(ans[i]){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
