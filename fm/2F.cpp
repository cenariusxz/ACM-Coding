#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int maxn=1e4+5;
const int maxm=2e4+5;

int fa[maxn],num,n;
int a[maxm],b[maxm];
char c[maxm][10];
int head[maxn],point[maxm],nxt[maxm],size;
int id[maxn];

void init(){for(int i=0;i<n;++i)fa[i]=i;}

int find(int x){
	int r=x,t;
	while(r!=fa[r])r=fa[r];
	while(x!=r){
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
}

int topo(){
	queue<int>q;
	bool f=1;
	for(int i=0;i<n;++i)if(fa[i]==i&&!id[i])q.push(i);
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cnt++;
		if(!q.empty())f=0;
		for(int i=head[u];~i;i=nxt[i]){
			int j=point[i];
			id[j]--;
			if(!id[j])q.push(j);
		}
	}
	if(cnt!=num)return 0;
	if(f)return 1;
	return -1;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
}

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(id,0,sizeof(id));
		memset(head,-1,sizeof(head));
		size=0;
		init();
		num=n;
		for(int i=1;i<=m;++i){
			scanf("%d%s%d",&a[i],c[i],&b[i]);
			if(c[i][0]=='='){
				int x=find(a[i]),y=find(b[i]);
				if(x!=y){
					fa[x]=y;
					num--;
				}
			}
		}
		for(int i=1;i<=m;++i){
			if(c[i][0]=='>'){
				add(find(a[i]),find(b[i]));
			}
			else if(c[i][0]=='<'){
				add(find(b[i]),find(a[i]));
			}
		}
		int tmp=topo();
		if(tmp==1)printf("OK\n");
		else if(tmp==0)printf("CONFLICT\n");
		else if(tmp==-1)printf("UNCERTAIN\n");
	}
}
