#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

const int maxn=1005;
const int maxm=2e6+5;

int head[2][maxn],nxt[2][maxm],val[2][maxm],point[2][maxm],size[2];
int dis[4][maxn];
int n,m,s0,t0,s1,t1,cnt;
vector<int>v[maxn],id[maxn],l[10005],mc[2][10005];
int res[2][maxn],lc[10005];

void init(){
	memset(head,-1,sizeof(head));
	memset(res,0x3f,sizeof(res));
	size[0]=size[1]=0;
	cnt=0;
	for(int i=1;i<=n;++i)v[i].clear();
	for(int i=1;i<=n;++i)id[i].clear();
	for(int i=1;i<=m;++i)l[i].clear();
	for(int i=1;i<=m;++i)mc[0][i].clear();
	for(int i=1;i<=m;++i)mc[1][i].clear();
}

void add(int a,int b,int v,int x){
	point[x][size[x]]=b;
	val[x][size[x]]=v;
	nxt[x][size[x]]=head[x][a];
	head[x][a]=size[x]++;
}

struct cmp{
	bool operator () (pii a,pii b){
		return a.first>b.first;
	}
};

void dij(int s,int c,int x){
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(dis[x],0x3f,sizeof(dis[x]));
	dis[x][s]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dis[x][u.second])continue;
		for(int i=head[c][u.second];~i;i=nxt[c][i]){
			int j=point[c][i];
			if(dis[x][j]>u.first+val[c][i]){
				dis[x][j]=u.first+val[c][i];
				q.push(make_pair(dis[x][j],j));
			}
		}
	}
}

void read(){
	for(int i=1;i<=m;++i){
		int p,s,pre;
		scanf("%d%d",&p,&s);
		if(s==1){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b,p,0);
			add(b,a,p,1);
			continue;
		}
		++cnt;
		lc[cnt]=p;
		for(int j=0;j<=s;++j){
			int d;
			scanf("%d",&d);
			v[d].push_back(cnt);
			id[d].push_back(j);
			l[cnt].push_back(d);
			mc[0][cnt].push_back(INF);
			mc[1][cnt].push_back(INF);
			if(j==0)pre=d;
			else{
				add(pre,d,p,0);
				add(d,pre,p,1);
			}
		}
	}
}

//dis[0] s0->   dis[1] s1->   dis[2] ->t0   dis[3] ->t1

void Pre1(){
	dij(s0,0,0);
	dij(s1,0,1);
	dij(t0,1,2);
	dij(t1,1,3);
}

void Pre2(){
	for(int i=1;i<=cnt;++i){
		for(int j=l[i].size()-1;j>=0;--j){
			int p=l[i][j];
			if(j==l[i].size()-1)mc[0][i][j]=dis[2][p];
			else{
				mc[0][i][j]=min(dis[2][p],mc[0][i][j+1]);
			}
			if(j==l[i].size()-1)mc[1][i][j]=dis[3][p];
			else{
				mc[1][i][j]=min(dis[3][p],mc[1][i][j+1]);
			}
		}
	}
}

void Pre3(){		//s0->t1 res[0]
	for(int i=1;i<=n;++i){
		if(dis[0][i]!=INF&&dis[3][i]!=INF)res[0][i]=dis[0][i]+dis[3][i];
		for(int j=0;j<v[i].size();++j){
			int line=v[i][j];
			int pre=l[line][0];
			int num=id[i][j];
			if(dis[0][pre]!=INF&&mc[1][line][num]!=INF){
				int tmp=dis[0][pre]+lc[line]+mc[1][line][num];
				if(tmp<res[0][i])res[0][i]=tmp;
			}
		}
	}
}

void Pre4(){		//s1->t0 res[1]
	for(int i=1;i<=n;++i){
		if(dis[1][i]!=INF&&dis[2][i]!=INF)res[1][i]=dis[1][i]+dis[2][i];
		for(int j=0;j<v[i].size();++j){
			int line=v[i][j];
			int pre=l[line][0];
			int num=id[i][j];
			if(dis[1][pre]!=INF&&mc[0][line][num]!=INF){
				int tmp=dis[1][pre]+lc[line]+mc[0][line][num];
				if(tmp<res[1][i])res[1][i]=tmp;
			}
		}
	}
}

void solve(){
	int ans=INF;
	if(dis[0][t0]!=INF&&dis[1][t1]!=INF)ans=dis[0][t0]+dis[1][t1];
	for(int i=1;i<=n;++i){
		if(res[0][i]!=INF&&res[1][i]!=INF){
			int tmp=res[0][i]+res[1][i];
			if(tmp<ans)ans=tmp;
		}
	}
	if(ans==INF)printf("Impossible!\n");
	else printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d%d%d%d%d",&n,&m,&s0,&t0,&s1,&t1)!=EOF){
		if(n==0&&m==0&&s0==0&&t0==0&&s1==0&&t1==0)break;
		init();
		read();
		Pre1();
		Pre2();
		Pre3();
		Pre4();
		solve();
	}
	return 0;
}
