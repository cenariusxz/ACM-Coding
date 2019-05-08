#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;

const int maxn=100+5;
const int maxm=20+5;

double D[maxn][maxn];
double val[maxn],del;
double sum[maxm],left,right,S,ave;
int d[maxm][maxn],vis[maxn];
int ans[maxn],ans2[maxn];
int n,m,N,M,begin;
int p1[maxm],p2[maxn];
bool flag=0,flag2=0;

vector<int>V[maxm];

void read(){
	n=92,m=20;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%lf",&D[i][j]);
		}
	}
	for(int i=1;i<=n;++i)scanf("%lf",&val[i]);
	scanf("%lf",&del);
}

void pre(){
	N=0,M=0;
	memset(sum,0,sizeof(sum));
	memset(d,0,sizeof(d));
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=m;++i)V[i].clear();
	for(int i=1;i<=n;++i){
		bool f=0;
		int num=1;
		for(int j=1;j<=m;++j){
			if(D[j][i]<=3000){
				f=1;
				d[j][i]=1;
			}
			if(D[j][i]<D[num][i])num=j;
		}
		if(!f){
			ans[i]=num;
			sum[num]+=val[i];
		}
	}
	for(int i=1;i<=n;++i){
		int cnt=0;
		for(int j=1;j<=m;++j){
			if(d[j][i])cnt++;
		}
		if(cnt==1){
			for(int j=1;j<=m;++j){
				if(d[j][i]){
					ans[i]=j;
					sum[j]+=val[i];
				}
			}
		}
	}
	for(int i=1;i<=m;++i){
		if(ans[i])continue;
		else{
			ans[i]=i;
			sum[i]+=val[i];
		}
	}

	for(int i=1;i<=n;++i){
		if(ans[i])continue;
		p2[++N]=i;
		for(int j=1;j<=m;++j){
			if(d[j][i]){
				V[j].push_back(i);
			}
		}
	}
	
	for(int i=1;i<=m;++i){
		if(V[i].size()>0){
			p1[++M]=i;
		}
	}
}

void check(){
	double Sum1[maxm],Sum2[maxn];
	memset(Sum1,0,sizeof(Sum1));
	memset(Sum2,0,sizeof(Sum2));
	for(int i=1;i<=n;++i){
		if(ans2[i])Sum2[ans2[i]]+=val[i];
	}
	for(int i=1;i<=N;++i){
		int p=p2[i];
		if(ans2[p])continue;
		int tmp=0;
		for(int j=1;j<=m;++j){
			if(d[j][p]){
				if(tmp==0)tmp=j;
				else if(Sum2[tmp]>Sum2[j])tmp=j;
			}
		}
		ans2[p]=tmp;
		Sum2[tmp]+=val[p];
	}
	if(flag2){
		for(int i=1;i<=n;++i){
			Sum1[ans[i]]+=val[i];
		}
		double S1=0,S2=0;
		for(int i=1;i<=m;++i){
			S1+=(Sum1[i]-ave)*(Sum1[i]-ave);
			S2+=(Sum2[i]-ave)*(Sum2[i]-ave);
		}
		if(S1>S2)memcpy(ans,ans2,sizeof(ans));
	}
	else{
		flag2=1;
		memcpy(ans,ans2,sizeof(ans));
	}
}

void dfs(int now){
	if(now==M+1){
		check();
		return;
	}
	if(clock()-begin>2*1000000)flag=1;
	if(flag)return;
	int id=p1[now];
	double Sum=sum[id];
	if(Sum>=left)dfs(now+1);
	if(flag)return;
	if(Sum>right)return;
	int que[maxn],cnt=0;
	for(int i=0;i<V[id].size()&&Sum<=right;++i){
		int p=V[id][i];
		if(ans2[p])continue;
		ans2[p]=id;
		Sum+=val[p];
		que[++cnt]=p;
		dfs(now+1);
		if(flag)return;
	}
	if(Sum<left)dfs(now+1);
	if(flag)return;
	for(int i=1;i<=cnt;++i)ans2[que[i]]=0;
}

void solve(){
	S=0;
	for(int i=1;i<=n;++i)S+=val[i];
	ave=S/m;
	left=ave;
	right=ave+2*del;
	flag2=0;
	memcpy(ans2,ans,sizeof(ans2));
	for(int t=1;t<=6000;++t){
		for(int i=1;i<=M;++i){
			int id=p1[i];
			random_shuffle(V[id].begin(),V[id].end());
		}
		for(int i=1;i<=N;++i){
			int id=p2[i];
			ans2[id]=0;
		}
		begin=clock();
		flag=0;
		dfs(1);
	}
	double Sum[maxm];
	memset(Sum,0,sizeof(Sum));
	for(int i=1;i<=n;++i){
		Sum[ans[i]]+=val[i];
	}
	double S1=0;
	for(int i=1;i<=m;++i){
		S1+=(Sum[i]-ave)*(Sum[i]-ave);
		V[i].clear();
	}
	S1/=m;
	for(int i=1;i<=n;++i){
		V[ans[i]].push_back(i);
	}
	for(int i=1;i<=m;++i){
		printf("%d: ",i);
		for(int j=0;j<V[i].size();++j)printf("%d ",V[i][j]);
		printf("\n");
		printf("%.5lf\n",Sum[i]);
	}
	printf("%lf\n",S1);
}

int main(){
	read();
	pre();
	solve();
	return 0;
}
