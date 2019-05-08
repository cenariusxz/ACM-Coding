#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=10;

int vis1[maxn],vis2[maxn],a[maxn],d[maxn][maxn];
int n,m,A,B;
int ans;

void dfs1(int now,int sum){
	int add=0,f;
	for(int i=2;i<=n;++i){
		if(!vis1[i]){
			f=1;
			for(int j=now;j<=n;++j){
				if(d[i][a[j]]==0&&d[i][a[j%n+1]]==0) {f=0;break;}
			}
			if(f)add++;
		}
	}
	if(sum+add>=ans)return;
	if(now>n){
		ans=sum;
		return;
	}
	for(int i=2;i<=n;++i){
		if(!vis1[i]){
			vis1[i]=1;
			int tmp=(d[i][a[now]]||d[i][a[now%n+1]])?1:0;
			dfs1(now+1,sum+tmp);
			vis1[i]=0;
		}
	}
}

void dfs2(int now){
	if(now>n){
		if(d[1][a[1]]||d[1][a[2]])dfs1(2,1);
		else dfs1(2,0);
		return;
	}
	for(int i=1;i<=n;++i){
		if(!vis2[i]){
			vis2[i]=1;
			a[now]=i;
			dfs2(now+1);
			vis2[i]=0;
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(d,0,sizeof(d));
		while(m--){
			scanf("%d%d",&A,&B);
			d[A][B]=1;
		}
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		ans=n;
		vis1[1]=1;
		dfs2(1);
		printf("%d\n",ans);
	}
	return 0;
}
