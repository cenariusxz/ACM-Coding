#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=999983;
const int maxn=1e5+5;
const int maxm=2e5+5;

int hate[maxn],love[maxn];
int head[maxn],point[maxm],nxt[maxm],val[maxm],size;

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(hate,0,sizeof(hate));
	memset(lov3,0,sizeof(love));
}

void add(int a,int b,int v){
	point[size]=b;
	val[size]=v;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	val[size]=v;
	nxt[size]=head[b];
	head[b]=size++;
	if(v){
		love[a]++;
		love[b]++;
	}
	else{
		hate[a]++;
		hate[b]++;
	}
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		while(m--){
			int a,b,v;
			scanf("%d%d%d",&a,&b,&v);
			add(a,b,v);
		}
		
	}
	return 0;
}
