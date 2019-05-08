#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int xx[1005],yy[1005];
int fa[1005],n;
bool vis[1005];
int head[1005],point[1005*1005],nxt[1005*1005],size;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

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

int main(){
	int d;
	scanf("%d%d",&n,&d);
	int i,j;
	memset(head,-1,sizeof(head));
	size=0;
	for(i=1;i<=n;i++){
		scanf("%d%d",&xx[i],&yy[i]);
		for(j=1;j<i;j++){
			if((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j])<=d*d){
				add(i,j);
				add(j,i);
			}
		}
	}
	init();
	char s[10];
	while(scanf("%s",s)!=EOF){
		if(s[0]=='O'){
			int a;
			scanf("%d",&a);
			vis[a]=1;
			for(i=head[a];~i;i=nxt[i]){
				int j=point[i];
				if(vis[j]){
					int x=find(a),y=find(j);
					if(x!=y)fa[x]=y;
				}
			}
		}
		else if(s[0]=='S'){
			int a,b;
			scanf("%d%d",&a,&b);
			int x=find(a),y=find(b);
			if(x==y)printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
}
