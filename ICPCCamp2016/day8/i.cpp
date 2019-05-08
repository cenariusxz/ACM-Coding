#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int maxm=5e6+5;

int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};

struct node{
	ll x,y;
	int f,id;
}p[maxn];

struct Point{
	ll t;
	int id;
	bool operator < (const Point a)const{
		return t>a.t;
	}
	Point(int c,ll d):id(c),t(d){}
	Point(){}
};

int head[maxn],point[maxm],nxt[maxm],size;
ll val[maxm];
ll x[maxn],y[maxn];
int f[maxn];
int vis[maxn];
ll tim[maxn];

bool cmp1(node a,node b){
	if(a.y==b.y)return a.x<b.x;
	return a.y<b.y;
}

bool cmp2(node a,node b){
	if(a.y==b.y)return a.x>b.x;
	return a.y<b.y;
}

bool cmp3(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}

bool cmp4(node a,node b){
	if(a.x==b.x)return a.y>b.y;
	return a.x<b.x;
}

void init(){
	size=0;
	memset(head,-1,sizeof(head));
}

void add(int a,int b,ll v){
//	printf("add:%d %d %d\n",a,b,v);

	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
}

int main(){
	int n;
	ll t;
	scanf("%d%lld",&n,&t);
	init();
	for(int i=1;i<=n;++i){
		char s[2];
		int a,b;
		scanf("%d%d%s",&a,&b,s);
		x[i]=a;y[i]=b;
		p[i].x=a;p[i].y=b;p[i].id=i;
		if(s[0]=='U')f[i]=p[i].f=0;
		if(s[0]=='D')f[i]=p[i].f=1;
		if(s[0]=='R')f[i]=p[i].f=2;
		if(s[0]=='L')f[i]=p[i].f=3;
	}
	int pre;

	sort(p+1,p+n+1,cmp1);
	pre=0;
	for(int i=1;i<=n;++i){
		if(pre&&p[pre].y==p[i].y)add(p[pre].id,p[i].id,p[i].x-p[pre].x);
		if(p[i].f==2)pre=i;
	}

//	sort(p+1,p+n+1,cmp2);
	pre=0;
	for(int i=n;i>=1;--i){
		if(pre&&p[pre].y==p[i].y)add(p[pre].id,p[i].id,p[pre].x-p[i].x);
		if(p[i].f==3)pre=i;
	}

	sort(p+1,p+n+1,cmp3);
	pre=0;
	for(int i=1;i<=n;++i){
		if(pre&&p[pre].x==p[i].x)add(p[pre].id,p[i].id,p[i].y-p[pre].y);
		if(p[i].f==0)pre=i;
	}

//	sort(p+1,p+n+1,cmp4);
	pre=0;
	for(int i=n;i>=1;--i){
		if(pre&&p[pre].x==p[i].x)add(p[pre].id,p[i].id,p[pre].y-p[i].y);
		if(p[i].f==1)pre=i;
	}

	priority_queue<Point>q;

	q.push(Point(1,0));
	memset(tim,-1,sizeof(tim));
	while(!q.empty()){
		Point u=q.top();
		q.pop();
		if(tim[u.id]!=-1)continue;
		if(u.t>t)break;
		tim[u.id]=u.t;
		for(int i=head[u.id];~i;i=nxt[i]){
			int j=point[i];
			if(tim[j]==-1){
				q.push(Point(j,u.t+val[i]));
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		printf("%d %d\n",i,tim[i]);
//	}
	for(int i=1;i<=n;++i){
		if(tim[i]==-1||tim[i]>t)printf("%lld %lld\n",x[i],y[i]);
		else{
			printf("%lld %lld\n",x[i]+(t-tim[i])*xx[f[i]],y[i]+(t-tim[i])*yy[f[i]]);
		}
	}
	return 0;
}
