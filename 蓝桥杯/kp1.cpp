#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

//shang xia zuo you
const int maxn=105;

int xx[4]={-1,1,0,0};
int yy[4]={0,0,-1,1};

char s[maxn][maxn];

int main(){
	int T,n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
		bool f=0;
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(s[i][j]!='.'){
					int d=0;
					if(s[i][j]=='^')d=0;
					if(s[i][j]=='v')d=1;
					if(s[i][j]=='<')d=2;
					if(s[i][j]=='>')d=3;
					int x=i+xx[d],y=j+yy[d];
					bool ff=0;
					while(x>=1&&x<=n&&y>=1&&y<=m&&!ff){
						if(s[x][y]!='.')ff=1;
						x+=xx[d];
						y+=yy[d];
					}
					if(ff)continue;
					ff=0;
					for(int k=0;k<4;++k){
						if(k==d)continue;
						x=i+xx[k],y=j+yy[k];
						while(x>=1&&x<=n&&y>=1&&y<=m&&!ff){
							if(s[x][y]!='.')ff=1;
							x+=xx[k];
							y+=yy[k];
						}
						if(ff){
							ans++;
							break;
						}
					}
					if(!ff)f=1;
				}
			}
		}
		if(f)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
