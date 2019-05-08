#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

const int maxn=5e4+5;
const int maxm=5e5+5;

struct job{
	int p,d,id,num;
	bool operator < (const job a)const{
		return d<a.d;
	}
}w[maxn];

int head[maxn],point[maxm],nxt[maxm],size;
int n;

void init(){
	memset(w,0,sizeof(w));
	memset(head,-1,sizeof(head));
	size=0;
	for(int i=1;i<=n;++i)w[i].num=i;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	w[b].id++;
}

void topo(){
	priority_queue<job>q;
	for(int i=1;i<=n;++i)if(!w[i].id)q.push(w[i]);
	while(!q.empty()){
		job u=q.top();
		q.pop();
		int s=u.num;
		printf("%d\n",s);
		for(int i=head[s];~i;i=nxt[i]){
			int j=point[i];
			w[j].id--;
			if(!w[j].id)q.push(w[j]);
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			scanf("%d%d",&w[i].p,&w[i].d);
		}
		int m;
		scanf("%d",&m);
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		topo();
	}
	return 0;
}
