#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

const int maxn=1e6+5;

int head[maxn],nxt[maxn],point[maxn],size;
char S[maxn],val[maxn];
int dp[2][maxn],Dp[2][maxn];
int dp2[2][maxn],Dp2[2][maxn];
int n,m;
int ansl=-1,ansr=-1,ff=0;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(dp[0],0,sizeof(dp[0]));
	for(int i=1;i<=n;++i){
		dp[1][i]=m+1;
		Dp[0][i]=Dp[1][i]=i;
	}
}

void add(int a,int b,char c){
	point[size]=b;
	val[size]=c;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	val[size]=c;
	nxt[size]=head[b];
	head[b]=size++;
}

void dfs(int s,int fa){
	if(ff)return;
	int cnt=0;
	int pre=0;
	int maxx=0;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(j==fa)continue;
		dfs(j,s);
		if(ff)return;
		if(dp[0][j]+1<=m&&S[dp[0][j]+1]==val[i]){
			dp2[0][i]=dp[0][j]+1;
			Dp2[0][i]=Dp[0][j];
			if(dp[0][j]+1>dp[0][s]){
				dp[0][s]=dp[0][j]+1;
				Dp[0][s]=Dp[0][j];
				if(dp[0][s]==m){
					ansl=Dp[0][s];
					ansr=s;
					ff=1;
					return;
				}
			}
		}
		else{
			dp2[0][i]=dp[0][j];
			Dp2[0][i]=Dp[0][j];
			if(dp[0][j]>dp[0][s]){
				dp[0][s]=dp[0][j];
				Dp[0][s]=Dp[0][j];
			}
		}
		if(dp2[0][i]>maxx){
			pre=maxx;
			maxx=dp2[0][i];
			cnt=1;
		}
		else if(dp2[0][i]==maxx)cnt++;
		else if(dp2[0][i]>pre)pre=dp2[0][i];

		if(dp[1][j]-1>=1&&S[dp[1][j]-1]==val[i]){
			dp2[1][i]=dp[1][j]-1;
			Dp2[1][i]=Dp[1][j];
			if(dp[1][j]-1<dp[1][s]){
				dp[1][s]=dp[1][j]-1;
				Dp[1][s]=Dp[1][j];
				if(dp[1][s]==1){
					ansl=s;
					ansr=Dp[1][s];
					ff=1;
					return;
				}
			}
		}
		else{
			dp2[1][i]=dp[1][j];
			Dp2[1][i]=Dp[1][j];
			if(dp[1][j]<dp[1][s]){
				dp[1][s]=dp[1][j];
				Dp[1][s]=Dp[1][j];
			}
		}
	}
	vector<int>v;
	if(cnt>1){
		for(int i=head[s];~i;i=nxt[i]){
			int j=point[i];
			if(j==fa)continue;
			if(dp2[0][i]==maxx){
				v.push_back(i);
				if(v.size()==2)break;
			}
		}
	}
	else if(cnt==1){
		bool f=1;
		for(int i=head[s];~i;i=nxt[i]){
			int j=point[i];
			if(j==fa)continue;
			if(dp2[0][i]==maxx){
				v.push_back(i);
				if(v.size()==2)break;
			}
			if(f&&dp2[0][i]==pre){
				v.push_back(i);
				f=0;
				if(v.size()==2)break;
			}
		}
	}
	for(int j=0;j<v.size();++j){
		for(int i=head[s];~i;i=nxt[i]){
			if(i==v[j]||point[i]==fa)continue;
			else if(dp2[1][i]<=dp2[0][v[j]]+1){
				ansl=Dp2[0][v[j]];
				ansr=Dp2[1][i];
				ff=1;
				return;
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<n;++i){
		int a,b;
		char ss[2];
		scanf("%d%d%s",&a,&b,ss);
		add(a,b,ss[0]);
	}
	scanf("%s",S+1);
	dfs(1,-1);
	//for(int i=1;i<=n;++i)printf("%d %d\n",dp[0][i],dp[1][i]);
	printf("%d %d\n",ansl,ansr);
	return 0;	
}
