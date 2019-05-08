#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int vis[1005][1005];
int r[1005],c[1005];

void init(){
	memset(vis,0,sizeof(vis));
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	vis[1][1]=1;
	r[1]=1;c[1]=1;
	for(int i=2;i<=1000;++i){
		int px=1,py=i;
		for(;px<=1000&&py<=1000;++px,++py){
			if(r[px]==1||c[py]==1)continue;
			vis[px][py]=1;
			r[px]=1;c[py]=1;
			vis[py][px]=1;
			r[py]=1;c[px]=1;
			break;
		}
	}
/*	for(int i=1;i<=25;++i){
		for(int j=1;j<=25;++j){
			printf("%d ",vis[i][j]);
		}
		printf("\n");
	}
*/	
}


int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int a,n,m;
		scanf("%d%d%d",&a,&n,&m);
		if(a==1){
			if(n%2==1&&m%2==1){
				printf("G\n");
			}
			else printf("B\n");
		}
		if(a==2){
			if(n==m)printf("G\n");
			else printf("B\n");
		}
		if(a==3){
			if(n>m)swap(n,m);
			int k1=(n-2)/3;
			int k2=(m-3)/3;
			if(k1==k2&&3*k1+2==n&&3*k1+3==m){
				printf("B\n");
				continue;
			}
			if(n==m&&(n-1)%3==0){
				printf("G\n");
				continue;
			}
			printf("D\n");
		}
		if(a==4){
			if(vis[n][m])printf("G\n");
			else printf("B\n");
		}
	}
	return 0;
}
