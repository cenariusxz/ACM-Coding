#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct col{
	int num,a;
	bool operator<(const col x)const{
		return a>x.a;
	}
}c[27];

int ma[6][6];
int n,m,k;
int xx[2]={0,-1};
int yy[2]={-1,0};

bool f=0;

void dfs(int num){
	if(f)return;
	if(num==n*m+1){
		f=1;
		return;
	}
	int x=num/m;
	int y=num%m;
	if(y)x++;
	else y=m;
	for(int i=1;i<=k;++i){
		if(c[i].a>(n*m-num+2)/2)return;
	}
	int vis[27]={0};
	for(int i=0;i<2;++i){
		int dx=x+xx[i],dy=y+yy[i];
		if(dx>=1&&dy>=1)vis[ma[dx][dy]]=1;
	}
	for(int i=1;i<=k;++i){
		if(c[i].a&&!vis[c[i].num]){
			ma[x][y]=c[i].num;
			c[i].a--;
			dfs(num+1);
			c[i].a++;
			if(f)return;
		}
	}
}

int main(){
	int T,cnt=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		memset(c,0,sizeof(c));
		memset(ma,0,sizeof(ma));
		f=0;
		for(int i=1;i<=k;++i){
			scanf("%d",&c[i].a);
			c[i].num=i;
		}
		sort(c+1,c+k+1);
		dfs(1);
		printf("Case #%d:\n",++cnt);
		if(f){
			printf("YES\n");
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					printf("%d",ma[i][j]);
					if(j==m)printf("\n");
					else printf(" ");
				}
			}
		}
		else printf("NO\n");
	}
	return 0;
}
