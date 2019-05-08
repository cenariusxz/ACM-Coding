#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;

const int maxn=2e6+5;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll dis[maxn];
vector<vector<ll> >M;
int n,m;
int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};

struct cmp{                        //将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

inline int getid(int x,int y){
	return x*m+y;
}

void dij(){            //传入出发点和到达点
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	memset(dis,0x3f,sizeof(dis));
	ll s=0;
	for(int i=2;i<m;++i){
		s+=M[0][i];
		int id=m*n+getid(0,i);
		dis[id]=s;
		q.push(make_pair(dis[id],id));
	}
	for(int i=1;i<n;++i){
		s+=M[i][m-1];
		int id=m*n+getid(i,m-1);
		dis[id]=s;
		q.push(make_pair(dis[id],id));
	}
	for(int i=m-2;i>=0;--i){
		s+=M[n-1][i];
		int id=m*n+getid(n-1,i);
		dis[id]=s;
		q.push(make_pair(dis[id],id));
	}
	for(int i=n-2;i>=2;--i){
		s+=M[i][0];
		int id=m*n+getid(i,0);
		dis[id]=s;
		q.push(make_pair(dis[id],id));
	}
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>dis[u.second])continue;
		int id1=u.second;
		if(id1>=m*n)id1-=m*n;
		int x=id1/m;
		int y=id1%m;
		if((x==0||x==n-1||y==0||y==m-1)&&(u.second<m*n))continue;
		for(int i=0;i<4;++i){
			int dx=x+xx[i],dy=y+yy[i];
			if(dx<=1&&dy<=1)continue;
			if(dx<0||dx>=n||dy<0||dy>=m)continue;
			int j=getid(dx,dy);
			if(dis[j]>u.first+M[dx][dy]){
				dis[j]=u.first+M[dx][dy];
				q.push(make_pair(dis[j],j));
			}
		}
	}
	ll ans=s+M[0][0]+M[0][1]+M[1][0];
	s=M[0][0]+M[0][1]+M[1][0];
	for(int i=2;i<n;++i){
		int id=getid(i,0);
		if(s+dis[id]<ans)ans=s+dis[id];
		s+=M[i][0];
	}
	for(int i=1;i<m;++i){
		int id=getid(n-1,i);
		if(s+dis[id]<ans)ans=s+dis[id];
		s+=M[n-1][i];
	}
	for(int i=n-2;i>=0;--i){
		int id=getid(i,m-1);
		if(s+dis[id]<ans)ans=s+dis[id];
		s+=M[i][m-1];
	}
	for(int i=m-2;i>=2;--i){
		int id=getid(0,i);
		if(s+dis[id]<ans)ans=s+dis[id];
		s+=M[0][i];
	}
	printf("%lld\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)break;
		vector<ll>tmp;
		M.clear();
		for(int i=0;i<m;++i)tmp.push_back(0);
		for(int i=0;i<n;++i)M.push_back(tmp);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				int a;
				scanf("%d",&a);
				M[i][j]=a;
			}
		}
		dij();
	}
	return 0;
}
