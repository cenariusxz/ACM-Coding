#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,fa[55],g[55][55];

struct seg{
	int x,y,v;
}s[2505];

bool cmp(seg a,seg b){
	return a.v<b.v;
}

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

void unio(int x,int y){
	int dx=find(x),dy=find(y);
	if(dx!=dy){
		fa[dx]=dy;
	}
}

int main(){
	while(scanf("%d",&n)!=EOF&&n!=0){
		int m;
		scanf("%d",&m);
		int ans=0;
		if(n==1)printf("0\n");
		else{
			init();
			memset(g,-1,sizeof(g));
			int i,c=0;
			for(i=1;i<=m;i++){
				int a,b,v;
				scanf("%d%d%d",&a,&b,&v);
				if(g[a][b]==-1){
					g[a][b]=g[b][a]=++c;
					s[c].x=a;
					s[c].y=b;
					s[c].v=v;
				}
				else{
					int t=g[a][b];
					if(s[t].v>v){
						s[t].v=v;
					}
				}
			}
			sort(s+1,s+c+1,cmp);
			int ans=0,t=0;
			for(i=1;i<=c;i++){
				if(find(s[i].x)!=find(s[i].y)){
					unio(s[i].x,s[i].y);
					ans+=s[i].v;
					t++;
				}
				if(t==n-1)break;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
