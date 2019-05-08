#include<stdio.h>
#include<string.h>

int head[55],nxt[2550],point[2550],size;
int num[55];
double a[2][55][55],ans[55];
//int ma[55][55]

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	num[a]++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
	num[b]++;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m,d;
		scanf("%d%d%d",&n,&m,&d);
		memset(head,-1,sizeof(head));
		size=0;
		memset(num,0,sizeof(num));
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
		//	ma[u][v]=ma[v][u]=1;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i!=j)a[0][i][j]=1.0/n;
				else a[0][i][j]=0;
			}
		}
		int o=0;
	//	if(d>1000)d=1000;
		for(int i=1;i<=d;++i){
			memset(a[o^1],0,sizeof(a[o^1]));
			for(int j=1;j<=n;++j){
				for(int u=head[j];~u;u=nxt[u]){
					int v=point[u];
					for(int k=1;k<=n;++k){
						if(j!=k)a[o^1][j][k]+=a[o][v][k]/num[v];
					}
				}
			}
			o^=1;
		}
		for(int i=1;i<=n;++i){
			ans[i]=0;
			for(int j=1;j<=n;++j)ans[i]+=a[o][j][i];
		}
		for(int i=1;i<=n;++i)printf("%.10lf\n",ans[i]);
	}
	return 0;
}
