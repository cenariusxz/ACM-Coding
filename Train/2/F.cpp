#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

int px[100],py[100];
int cnt;
char s[15][15];
int xx[4]={1,1,-1,-1};
int yy[4]={1,-1,1,-1};
int dep;

void dfs(int x,int y,int t){
	if(t>dep)dep=t;
	for(int i=0;i<4;++i){
		int dx=x+xx[i],dy=y+yy[i];
		int ddx=dx+xx[i],ddy=dy+yy[i];
		if(dx>=1&&dx<=10&&dy>=1&&dy<=10&&ddx>=1&&ddx<=10&&ddy>=1&&ddy<=10){
			if(s[dx][dy]=='B'&&s[ddx][ddy]=='#'){
				s[dx][dy]='#';
				s[x][y]='#';
				s[ddx][ddy]='W';
				dfs(ddx,ddy,t+1);
				s[x][y]='W';
				s[dx][dy]='B';
				s[ddx][ddy]='#';
			}
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		cnt=0;
		for(int i=1;i<=10;++i)scanf("%s",s[i]+1);
		for(int i=1;i<=10;++i){
			for(int j=1;j<=10;++j){
				if(s[i][j]=='W'){
					cnt++;
					px[cnt]=i;
					py[cnt]=j;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=cnt;++i){
			dep=0;
			dfs(px[i],py[i],0);
			ans=max(ans,dep);
		}
		printf("%d\n",ans);
	}
	return 0;
}
