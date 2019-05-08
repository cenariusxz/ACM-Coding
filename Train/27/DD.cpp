#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int mod=1e6+3;
//typedef pair<int,int> pii;

struct point{
	int x,y,num,f;
	bool operator < (const point a)const{
		if(x<a.x)return y<a.y;
		return x<a.x;
	}
	point(){}
	point(int _x,int _y,int _num=0,int _f=0):x(_x),y(_y),num(_num),f(_f){}
}p[205];

int xx[8]={1,-1,0,0,1,1,-1,-1};
int yy[8]={0,0,1,-1,1,-1,1,-1};
int vis[205];
ll ans[500];

map<ll,int>M,id;
int r,c,num,n,lim,flag;

inline ll getid(int x,int y){
	return (x-1)*(ll)(c)+y-1;
}

inline void getxy(ll t,int &x,int &y){
	x=t/c+1;
	y=t%c+1;
}

void bfs(int x,int y,int cnt){
	queue<ll>q,q2;
	q.push(getid(x,y));
	M[getid(x,y)]=cnt;
	q2.push(getid(x,y));
	num++;
	bool f=1;
	while(!q.empty()&&f){
		ll u=q.front();q.pop();
		int x,y;
		getxy(u,x,y);
		for(int i=0;i<4;++i){
			int dx=x+xx[i],dy=y+yy[i];
			if(dx>=1&&dx<=r&&dy>=1&&dy<=c){
				int m=M[getid(dx,dy)];
				if(m!=1&&m!=0&&m!=cnt){f=0;break;}
				if(m==0){
					ll t=getid(dx,dy);
					q.push(t);
					M[t]=cnt;
					q2.push(t);
					num++;
					if(num>lim){f=0;break;}
				}
			}
		}
	}
	if(!f){
		num=-1;
		while(!q2.empty()){
			ll u=q2.front();q2.pop();
			M[u]=0;
		}
	}
}

void dfs(int x,int y){
	vis[id[getid(x,y)]]=1;
	num++;
	bool f=0;
	for(int i=0;i<8;++i){
		int dx=x+xx[i],dy=y+yy[i];
		if(dx>=1&&dx<=r&&dy>=1&&dy<=c){
			f=0;
			if(M[getid(dx,dy)]==1&&vis[id[getid(dx,dy)]]==0)dfs(dx,dy);
		}
		else f=1;
	}
	if(f)flag++;
}

void Pre(){
	scanf("%d%d%d",&r,&c,&n);
	M.clear();
	for(int i=1;i<=n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		M[getid(a,b)]=1;
		id[getid(a,b)]=i;
		p[i].x=a;
		p[i].y=b;
		p[i].num=p[i].f=0;
	}
	for(int i=1;i<=n;++i){
		num=0;
		flag=0;
		memset(vis,0,sizeof(vis));
		dfs(p[i].x,p[i].y);
		p[i].num=num;
		if(flag>=2)p[i].f=1;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		Pre();	

		int cnt=10;
		int k=0;
		int sum=0;
		for(int i=1;i<=n;++i){
			int x=p[i].x,y=p[i].y;
			for(int j=0;j<4;++j){
				int dx=x+xx[j],dy=y+yy[j];
				if(dx>=1&&dx<=r&&dy>=1&&dy<=c){
					if(M[getid(dx,dy)]==0){
						num=0;
						lim=p[i].num*(p[i].num+1)/2;
						if(!p[i].f) lim=min(3300,lim);
						else lim=min(18000,lim);
						bfs(dx,dy,++cnt);
						if(num!=-1){
							ans[++k]=num;
							sum+=num;
						}
					}
				}
			}
		}
		ll tmp=(ll)r*(ll)c-sum-n;
		if(tmp)ans[++k]=tmp;
		sort(ans+1,ans+k+1);
		printf("Case #%d:\n",q);
		printf("%d\n",k);
		for(int i=1;i<=k;++i){
			printf("%lld",ans[i]);
			if(i==k)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
