#include<stdio.h>
#include<string.h>

int head[505],next[6000],point[6000],val[6000],size=0;
int a,b,v,dis[505],n;

void add(int a,int b,int v){
	int i;
	for(i=head[a];~i;i=next[i]){
		if(point[i]==b){
			if(val[i]>v)val[i]=v;
			return;
		}
	}
	point[size]=b;
	val[size]=v;
	next[size]=head[a];
	head[a]=size++;
}

void bf(int s){
	int i,j,k;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	for(i=1;i<=n-1;i++){
		for(j=1;j<=n;j++){
			for(k=head[j];~k;k=next[k]){
				int p=point[k];
				if(dis[p]>dis[j]+val[k]){
					dis[p]=dis[j]+val[k];
				}
			}
		}
	}
	bool f=0;
	for(i=1;i<=n;i++){
		for(j=head[i];~j;j=next[j]){
			int p=point[j];
			if(dis[p]>dis[i]+val[j]){
				f=1;
			}
		}
	}
	if(f)printf("YES\n");
	else printf("NO\n");
}

int main(){
	int f;
	while(scanf("%d",&f)!=EOF){
		for(int q=1;q<=f;q++){
			int m,w;
			scanf("%d%d%d",&n,&m,&w);
			size=0;
			memset(head,-1,sizeof(head));
			int i;
			for(i=1;i<=m;i++){
				scanf("%d%d%d",&a,&b,&v);
				add(a,b,v);
				add(b,a,v);
			}
			for(i=1;i<=w;i++){
				scanf("%d%d%d",&a,&b,&v);
				add(a,b,-v);
			}
			bf(1);
		}
	}
	return 0;
}
