#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;

struct point{
	int x,y,vis,num;
	bool operator < (const point a)const{
		if(x<a.x)return y<a.y;
		return x<a.x;
	}
	point(){}
	point(int _x,int _y):x(_x),y(_y){}
}p[205];

int xx[8]={1,-1,0,0,1,1,-1,-1};
int yy[8]={0,0,1,-1,1,-1,1,-1};
ll ans[100];
int que[256],Q,f,flag,lim;

map<pair<int,int>,int>M,M1;
int r,c,num;

void dfs1(int x,int y,int px,int py){
	num++;
	p[M1[make_pair(x,y)]].vis=3;
	que[++Q]=M1[make_pair(x,y)];
	bool ff=0;
	for(int i=0;i<8;++i){
		int dx=x+xx[i],dy=y+yy[i];
		if(dx==px&&dy==py)continue;
		if(dx>=1&&dx<=r&&dy>=1&&dy<=c){
			if(M[make_pair(dx,dy)]==1){
				int id=M1[make_pair(dx,dy)];
				if(p[id].vis==3)f=1;
				else dfs1(dx,dy,x,y);
			}
		}
		else ff=1;
	}
	if(ff)flag++;
}

void dfs(int x,int y,int cnt){
	queue<pair<int,int> >q,q2;
	q.push(make_pair(x,y));
	q2.push(make_pair(x,y));
	num++;
	
	while(!q.empty()){
		pair<int,int>u=q.front();q.pop();
		for(int i=0;i<4;++i){
			int dx=u.first+xx[i],dy=u.second+yy[i];
			if(dx>=1&&dx<=r&&dy>=1&&dy<=c){
				int m=M[make_pair(dx,dy)];
				if(m!=1&&m!=0){num=-1;return;}
				else if(m==0){
					q.push(make_pair(dx,dy));num++;
					q2.push(make_pair(dx,dy));
					if(num>lim){num=-1;return;}
				}
			}
		}
	}

	while(!q2.empty()){
		pair<int,int>u=q2.front();q2.pop();
		int dx=u.first,dy=u.second;
		M[make_pair(dx,dy)]=cnt;
	}

	

}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d%d",&r,&c);
		M.clear();M1.clear();
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			M[make_pair(a,b)]=1;
			M1[make_pair(a,b)]=i;
			p[i].x=a;
			p[i].y=b;
			p[i].vis=0;
			p[i].num=0;
		}
		int cnt=10;
		int k=0;
		int sum=0;
		for(int i=1;i<=n;++i){
			int x=p[i].x,y=p[i].y;
			if(!p[i].vis){f=0;num=flag=Q=0;dfs1(x,y,-1,-1);}
			if(f||flag>=2){
				for(int j=1;j<=Q;++j){
					p[que[j]].vis=2;
					p[que[j]].num=num;
				}
			}
			else{
				for(int j=1;j<=Q;++j){
					p[que[j]].vis=1; 
				}
			}

			if(p[i].vis==2){
				for(int j=0;j<4;++j){
					int dx=x+xx[j],dy=y+yy[j];
					if(dx>=1&&dx<=r&&dy>=1&&dy<=c){
						if(M[make_pair(dx,dy)]==0){
							num=0;
							lim=p[i].num*(p[i].num-1)/2;
							dfs(dx,dy,++cnt);
							if(num!=-1){
								ans[++k]=num;
								sum+=num;
							}
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
