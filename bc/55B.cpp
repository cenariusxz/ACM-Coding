#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;

struct point{
	int x,y,k;
	double t;
	point(int a,int b,int c,double d):x(a),y(b),k(c),t(d){}
};

char s[55][55];
double dp[55][55][55];
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				for(int p=0;p<=k;++p)dp[i][j][p]=1e15;
			}
		}
		double ans=1e15;
		bool f=0;
		queue<point>q;
		q.push(point(x1,y1,k,0));
		while(!q.empty()){
			point u=q.front();
			q.pop();
			if(!u.k||u.t>=dp[u.x][u.y][u.k]){
				continue;
			}
			if(u.x==x2&&u.y==y2){
				if(u.t<ans){
					ans=u.t;
					f=1;
					continue;
				}
			}
			for(int i=u.k;i>0;--i)dp[u.x][u.y][i]=u.t;
			for(int i=0;i<4;++i){
				int x=u.x+xx[i],y=u.y+yy[i];
				if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]!='#'){
					q.push(point(x,y,u.k-1,u.t+abs(s[u.x][u.y]-s[x][y])*1.0/u.k));
				}
			}
		}
		if(f)printf("%.2lf\n",ans);
		else printf("No Answer\n");
	}
	return 0;
}
