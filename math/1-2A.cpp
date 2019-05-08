#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

const int maxn=1e2+5;
const int maxm=1e3+5;

int head[maxn],point[maxm],nxt[maxm],size;
double val[maxm];
int match[maxn],vis[maxn];
int ans[25][2];
double D[maxn][maxn];
int p1[25],p2[25];

void read(){
	int n=92;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%lf",&D[i][j]);
		}
	}
	for(int i=0;i<20;++i)scanf("%d",&p1[i]);
	for(int i=0;i<13;++i)scanf("%d",&p2[i]);
}

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b,double v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

int dfs(int s,double lim){
	for(int i=head[s];~i;i=nxt[i]){
		if(val[i]>lim)continue;
		int j=point[i];
		if(!vis[j]){
			vis[j]=1;
			if(match[j]==-1||dfs(match[j],lim)){
				match[j]=s;
				return 1;
			}
		}
	}
	return 0;
}

bool check(int n,double lim){
	memset(match,-1,sizeof(match));
	int res=0;
	for(int i=1;i<=20;++i){
		memset(vis,0,sizeof(vis));
		if(dfs(i,lim)==1)res++;
	}
	if(res==13)return 1;
	return 0;
}

void solve(){
	map<int,int>M1,M2;
	int n=0,i;
	for(i=0;i<20;++i){
		M1[++n]=p1[i];
		M2[p1[i]]=n;
	}
	for(i=0;i<13;++i){
		M1[++n]=p2[i];
		M2[p2[i]]=n;
	}
	init();
	double left=0,right=-1;
	for(i=1;i<=20;++i){
		for(int j=21;j<=33;++j){
			int from=M1[i]-1,to=M1[j]-1;
			double v=D[from][to];
			if(v<0)continue;
			if(v>right)right=v;
			add(i,j,v);
			add(j,i,v);
		}
	}
	double res=10000000;
	for(i=1;i<=100;++i){
		double mid=(left+right)/2;
		if(check(n,mid)){
			if(mid<res){
				for(int j=0;j<13;++j){
					ans[j][0]=M1[21+j];
					ans[j][1]=M1[match[21+j]];
				}
				res=mid;
			}
			right=mid;
		}
		else left=mid;
	}
	for(int i=0;i<13;++i){
		printf("%d:%d\n",ans[i][0],ans[i][1]);
	}
	printf("%lf\n",res);
}

int main(){
	read();
	solve();
	return 0;
}
