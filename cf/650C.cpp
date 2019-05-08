#include<stdio.h>        //基本需要的头文件
#include<string.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

const int maxn=1e6+5;
const int maxm=4e6;

vector<vector<int> >v;
int head[maxn],nxt[maxm],point[maxm],size;

struct num{
	int id,n;
	bool operator<(const num a)const{
		if(n==a.n)return id<a.id;
		return n<a.n;
	}
	num(int a=0,int b=0):id(a),n(b){}
}p[maxn];

void init(){
	memset(head,-1,sizeof(head));
	size=0;
}

void add(int a,int b){    //若有向图则只需要前一半
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

struct cmp{                        //将优先队列改为小根堆
	bool operator()(pii a,pii b){
		return a.first>b.first;
	}
};
int n,m;

int dij(){            //传入出发点和到达点
	int i;
	int s=0;
	priority_queue<pii,vector<pii>,cmp>q;
	q.push(make_pair(0,s));
	memset(p,0x3f,sizeof(p));
	p[s].n=0;
	while(!q.empty()){
		int a1,b1,a2,b2;
		pii u=q.top();
		q.pop();
		a1=u.second/m;
		b1=u.second%m;
		if(b1==0)b1=m;
		else a1++;
		if(u.first>p[u.second].n)continue;
		for(i=head[u.second];~i;i=nxt[i]){
			int j=point[i];
			a2=j/m;
			b2=j%m;
			if(b2==0)b2=m;
			else a2++;
			int val=0;
			if(v[a1][b1]!=v[a2][b2])val=-1;
			if(p[j].n>u.first+val){
				p[j].n=u.first+val;
				q.push(make_pair(p[j].n,j));
			}
		}
	}
	int cnt=0;
	int res=0;
	for(i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			++cnt;
			if(p[cnt].n<res)res=p[cnt].n;
	//		printf("%d ",dis[cnt]);
		}
	//	printf("\n");
	}
	return 1-res;
}

int main(){
	scanf("%d%d",&n,&m);
	vector<int>tmp;
	init();
	for(int i=0;i<=m;++i)tmp.push_back(0);
	for(int i=0;i<=n;++i){
		v.push_back(tmp);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&v[i][j]);
			add(0,m*(i-1)+j);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			p[j].n=v[i][j];
			p[j].id=m*(i-1)+j;
		}
		sort(p+1,p+m+1);
		for(int j=2;j<=m;++j){
			if(p[j].n==p[j-1].n){
				add(p[j].id,p[j-1].id);
				add(p[j-1].id,p[j].id);
			}
			else add(p[j].id,p[j-1].id);
		}
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			p[i].n=v[i][j];
			p[i].id=m*(i-1)+j;
		}
		sort(p+1,p+n+1);
		for(int i=2;i<=n;++i){
			if(p[i].n==p[i-1].n){
				add(p[i].id,p[i-1].id);
				add(p[i-1].id,p[i].id);
			}
			else add(p[i].id,p[i-1].id);
		}
	}
	int k=dij();
	int cnt=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cnt++;
			printf("%d ",p[cnt].n+k);
		}
		printf("\n");
	}
	return 0;
}
