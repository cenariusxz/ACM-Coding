#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int t[20];
int w[20];
int n,ans=0x3f3f3f3f,m;
struct point{
	int x,y;
	point(int _x,int _y):x(_x),y(_y){}
	point(){}
}P[20][25];
struct seg{
	int x1,y1,x2,y2;
	seg(int _x1,int _y1,int _x2,int _y2):x1(_x1),y1(_y1),x2(_x2),y2(_y2){}
	seg(){}
}s[10000];

bool isP(point a,point b,point c){
	return (a.y-b.y)*(b.x-c.x)==(a.x-b.x)*(b.y-c.y);
}
bool isI(point a,point b,point c){
	return isP(a,b,c)&&((c.x>=a.x&&c.x<=b.x)||(c.x<=a.x&&c.x>=b.x));
}

int vis[20];

bool solve(seg a){
	for(int i=1;i<=n;++i){
		if(!vis[i])continue;
		for(int j=1;j<t[i];++j){
			if(isI(P[i][j],P[i][j+1],point(a.x1,a.y1))&&isI(P[i][j],P[i][j+1],point(a.x2,a.y2)))return 1;
			if(isI(P[i][j],P[i][j+1],point(a.x1,a.y1))&&isP(P[i][j],P[i][j+1],point(a.x2,a.y2))){
				int xmin=min(a.x1,a.x2);
				int xmax=max(a.x1,a.x2);
				if(P[i][j])
			}
		}
	}
}

bool check(){
	for(int i=1;i<=m;++i){
		bool f=solve(s[i]);
	}
}

void dfs(int q,int sum){
	if(q==n+1){
		if(check())ans=min(ans,sum);
		return;
	}
	dfs(q+1);
	if(sum+w[q]<ans){
		vis[q]=1;
		dfs(q+1,sum+w[q]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&t,&w);
		for(int j=1;j<=t;++j){
			scanf("%d%d",&P[i][j].x,&P[i][j].y);
		}
		for(int j=1;j+2<=t;++j){
			if(isP(P[i][j],P[i][j+1],P[i][j+2])){
				for(k=j+1;k<=t-1;++k){
					P[i][k]=P[i][k+1];
				}
				t--;j--;
			}
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
	}
	memset(vis,0,sizeof(vis));
	dfs(1,0);
	return 0;
}
