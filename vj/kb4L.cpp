#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
typedef pair<double,int> pii;
const double INF=1e9;

struct point{
	int x,y;
	bool operator < (const point a)const{
		if(x==a.x)return y<a.y;
		return x<a.x;
	}
	point(int a,int b):x(a),y(b){}
};

int cnt;
double ma[205][205];
int vis[205][205];
double d[205];
int line[205],x[205],y[205];
int cl;

struct cmp{
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};

double cal(int a,int b){
	return sqrt(1.0*(x[a]-x[b])*(x[a]-x[b])+1.0*(y[a]-y[b])*(y[a]-y[b]));
}

void dij(){
	int i;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,1));
	for(i=1;i<=cnt;++i)d[i]=INF;
	d[1]=0;
	while(!q.empty()){
		pii u=q.top();
		q.pop();
		if(u.first>d[u.second])continue;
		if(u.second==2){printf("%d\n",(int)(d[2]/60.0+0.5));break;}
		for(int j=2;j<=cnt;++j){
			if(j==u.second)continue;
			double v=ma[u.second][j];
			if(d[j]>u.first+v){
				d[j]=u.first+v;
				q.push(make_pair(d[j],j));
			}
		}
	}
}

int main(){
	cnt=0;
	scanf("%d%d",&x[1],&y[1]);
	scanf("%d%d",&x[2],&y[2]);
	map<point,int>m;
	m[point(x[1],y[1])]=++cnt;
	m[point(x[2],y[2])]=++cnt;
	int x1,y1;
	cl=0;
	while(scanf("%d%d",&x1,&y1)!=EOF){
		if(x1==-1&&y1==-1){
			for(int i=2;i<=cl;++i){
				int j=i-1;
				ma[line[j]][line[i]]=ma[line[i]][line[j]]=cal(line[i],line[j])/40.0*3.6;
				vis[line[i]][line[j]]=vis[line[j]][line[i]]=1;
			}
			cl=0;
		}
		else{
			point tmp(x1,y1);
			if(m[tmp])line[++cl]=m[tmp];
			else{
				line[++cl]=m[tmp]=++cnt;
				x[cnt]=x1;y[cnt]=y1;
			}
		}
	}
	for(int i=1;i<=cnt;++i){
		for(int j=i+1;j<=cnt;++j){
			if(!vis[i][j])ma[i][j]=ma[j][i]=cal(i,j)/10.0*3.6;
		}
	}
	dij();
	return 0;
}
