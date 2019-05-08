#include<stdio.h>
#include<string.h>

const int maxn=105;
const int maxm=1e4+5;
int head[maxn],nxt[maxm],point[maxm],size;
int ma[maxn][maxn];
int c[maxn];
bool f=0;

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void dfs(int a,int x){
	if(f)return;
	c[a]=x;
	for(int i=head[a];~i;i=nxt[i]){
		int b=point[i];
		if(c[b]==-1)dfs(b,!x);
		else if(c[b]==x){
			f=1;
			return;
		}
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(ma,0,sizeof(ma));
		memset(head,-1,sizeof(head));
		size=0;
		for(int i=1;i<=n;++i){
			int a;
			while(scanf("%d",&a)&&a)ma[i][a]=1;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<i;++j){
				if((!ma[i][j])||(!ma[j][i]))add(i,j);
			}
		}
		memset(c,-1,sizeof(c));
		f=0;
		for(int i=1;i<=n&&(!f);++i){
			if(c[i]==-1){
				dfs(i,1);
			}
		}
		if(f)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
