#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

int n,m,cnt;
int h,a,ans=-1;
char Map[7][7];
int vis[30];

struct Monster{
	int x,y,h,a,f;
	Monster(int _x,int _y,int _h,int _a,int _f):
		x(_x),y(_y),h(_h),a(_a),f(_f){}
	Monster(){}
}mo[30];

inline int dis(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

void dfs(int x,int y,int t,int h,int c){
	if( c == cnt ){
		ans = max( ans , h );
	}
	for( int i = 1 ; i <= cnt ; ++ i ){
		if( !vis[i] ){
			int D = dis(x,y,mo[i].x,mo[i].y);
			int bnum = t - D;
			int hh=mo[i].h;
			if(bnum <= 0 )bnum=0;
			else{
				if( bnum * a >= mo[i].h ){
					int tt = mo[i].h/a;
					if(tt*a<mo[i].h)tt++;
					bnum-=tt;
					hh=0;
				}
				else{
					hh-=bnum*a;
					bnum=0;
				}
			}
			int tt= hh/a;
			if(tt*a<hh)tt++;
	//		if(cnt==1&&i==1){
//				printf("%d %d %d %d %d\n",mo[i].x,mo[i].y,bnum,hh,c+1);
//			}
			if(tt*mo[i].a>=h)continue;
			hh = h - tt*mo[i].a;
			if(mo[i].f)bnum=5;
			if(c==2&&vis[2]&&vis[1]&&i==3){
				printf("%d %d %d %d %d\n",mo[i].x,mo[i].y,bnum,hh,c+1);
			}
			vis[i] = 1;
			dfs(mo[i].x,mo[i].y,bnum,hh,c+1);
			vis[i] = 0;
		}
	}
}

int main(){
	cnt = 0;
	scanf("%d%d",&n,&m);
	int x,y;
	memset(vis,0,sizeof(vis));
	for( int i = 1 ; i <= n ; ++ i ){
		scanf("%s",Map[i]+1);
		for( int j = 1 ; j <= m ; ++ j ){
			if( Map[i][j] == 'M' ){
				++cnt;
				mo[cnt] = Monster(i,j,0,0,0);
			}
			if( Map[i][j] == 'S' ){
				++cnt;
				mo[cnt] = Monster(i,j,0,0,1);
			}
			if( Map[i][j] == 'D' ){
				x=i,y=j;
			}
		}
	}
	for( int i = 1 ; i <= cnt ; ++ i ){
		scanf("%d%d",&mo[i].h,&mo[i].a);
	}
	scanf("%d%d",&h,&a);
	dfs(x,y,5,h,0);
	if(ans==-1)printf("DEAD\n");
	else printf("%d\n",ans);
	return 0;
}
