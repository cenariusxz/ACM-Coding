#include<stdio.h>
#include<string.h>

int fa[105][105];
int n,m;

void init(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			fa[i][j]=j;
		}
	}
}

int find(int c,int x){
	return fa[c][x]==x?x:fa[c][x]=find(c,fa[c][x]);
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	int i;
	for(i=1;i<=m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int x=find(c,a),y=find(c,b);
		if(x!=y)fa[c][x]=y;
	}
	int q;
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		int a,b,ans=0;
		scanf("%d%d",&a,&b);
		for(int j=1;j<=m;j++){
			if(find(j,a)==find(j,b))ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
