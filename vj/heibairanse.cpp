#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;
const int maxm=1e5+5;

int head[maxn],point[maxm<<1],nxt[maxm<<1],size;
int c[maxn];			//color，每个点的黑白属性，-1表示还没有标记，0/1表示黑白
int num[2];				//在一次DFS中的黑白点个数
bool f=0;				//判断是否出现奇环

void init(){
	memset(head,-1,sizeof(head));
	size=0;
	memset(c,-1,sizeof(c));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void dfs(int s,int x){
	if(f)return;
	c[s]=x;
	num[x]++;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(c[j]==-1)dfs(j,!x);
		else if(c[j]==x){
			f=1;
			return;
		}
	}
}
//下面是主函数内的调用过程

for(i=1;i<=n&&(!f);i++){
	if(c[i]==-1){
		num[0]=num[1]=0;
		dfs(i,1);
	}
}
