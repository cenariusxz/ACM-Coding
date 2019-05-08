#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e3+5;

int vis[25];
int vis2[25];
int onl[25][maxn];
int stx[25];
int num[25];
int val[25][25];

void init(){
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	memset(stx,0x3f,sizeof(stx));
	memset(onl,0,sizeof(onl));
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		int n,t;
		scanf("%d%d",&n,&t);
		int k,s;
		scanf("%d%d",&k,&s);
		for(int i=1;i<=k;++i){
			int x;
			scanf("%d",&x);
			vis[x]=1;
			num[x]=s;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				scanf("%d",&val[i][j]);
			}
		}
		for(int i=1;i<=n;++i){
			int c;
			scanf("%d",&c);
			while(c--){
				int l,r;
				scanf("%d%d",&l,&r);
				for(int j=l;j<r;++j)onl[i][j]=1;
			}
		}
		int m;
		scanf("%d",&m);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a<stx[b])stx[b]=a;
		}

		for(int i=1;i<=t;++i){
			memset(vis2,0,sizeof(vis2));
			for(int j=1;j<=n;++j){
				if(vis[j])continue;
				if(i<stx[j]||onl[j][i]==0)continue;
				int sum=0;
				for(int k=1;k<=n;++k){
					if(vis[k]&&onl[k][i]==1)sum+=val[k][j];
				}
				if(sum>=s-num[j]){
					num[j]=s;
					vis2[j]=1;
				}
				else num[j]+=sum;
			}
			for(int j=1;j<=n;++j){
				if(vis2[j]==1)vis[j]=1;
			}
		}
		for(int i=1;i<=n;++i){
			printf("%.0f%%\n",floor(num[i]*100.0/s));
		}
	}
	return 0;
}
