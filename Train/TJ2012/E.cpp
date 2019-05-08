#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxn=200;
const int maxm=200*200*2;

int xx[maxn],yy[maxn];
int M[maxn][maxn];
int n,d;
int ans[maxn],vis[maxn];
int head[maxn],point[maxm],nxt[maxm],size;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

bool check(int pos){
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			if(ans[j]&&!vis[j]){
				q.push(j);
				vis[j]=1;
			}
		}
	}
	for(int i=n;i>=pos;--i){
		if(ans[i])continue;
		for(int j=1;j<=n;++j){
			if(i!=j&&ans[j]&&M[i][j]*2<=d)vis[i]=1;
		}
	}
	for(int i=1;i<=n;++i)if(!vis[i])return 0;
	return 1;
}

int main(){
	while(scanf("%d%d",&n,&d)!=EOF){
		init();
		for(int i=1;i<=n;++i)scanf("%d%d",&xx[i],&yy[i]);
		for(int i=1;i<=n;++i){
			M[i][i]=0;
			for(int j=1;j<i;++j){
				M[i][j]=M[j][i]=(int)ceil(sqrt( (xx[i]-xx[j])*(xx[i]-xx[j]) + (yy[i]-yy[j])*(yy[i]-yy[j]) ));
				if(M[i][j]<=d){
					add(i,j);
					add(j,i);
				}
			}
		}
		for(int i=1;i<=n;++i)ans[i]=1;
		if(!check(n+1)){
			printf("-1\n");
			continue;
		}
		for(int i=n;i>=2;--i){
			ans[i]=0;
			if(!check(i))ans[i]=1;
		}
		int pos=n;
		for(int i=n;i>=1;--i)if(ans[i]){
			pos=i;
			break;
		}
		for(int i=pos;i>=1;--i)printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}
