#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=105;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

int n,m,k;

int vis[maxn];
int fa[maxn];
int mcnt[maxn];
int M[maxn][maxn];
int Map[maxn][maxn];
int a[maxn];

void update( int l ){
//	if(l==8)printf("aaaa\n");
	int f = fa[l];
	for(int i = 1 ; i <= n ; ++ i ){
		if( Map[l][i] != -1){
//			if(l==8&&i==3)printf("bbbb\n");
			Map[f][i] = Map[i][f] = Map[l][i] - 1;
		}
	}
}

int main(){
	memset(fa,-1,sizeof(fa));
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1 ; i <= m ; ++ i){
		scanf("%d",&mcnt[i]);
	}
	for(int i = 1 ; i <= m ; ++ i){
		for(int j = 1 ; j <= mcnt[i] ; ++ j){
			scanf("%d",&M[i][j]);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int  i = 1 ; i <= k ; ++ i){
		scanf("%d",&a[i]);
		vis[a[i]] = 1;
	}
	memset(Map,-1,sizeof(Map));
	for(int i = 1 ; i <= k ; ++ i ){
		for(int j = 1 ; j <= k ; ++ j ){
			scanf("%d",&Map[a[i]][a[j]]);
		}
	}
/*	for(int i = 1 ; i <= n ; ++ i ){
		for(int j = 1 ; j <= n ; ++ j ){
			printf("%d ",Map[i][j]);
		}
		printf("\n");
	}*/

	for(int l = m ; l > 1 ; -- l ){
//		printf("i: %d\n",l);
		int S = l,F = l - 1;
		int pos1 = 1,pos2 = 1;
		while( pos2 <= mcnt[F] && vis[ M[F][pos2] ] )pos2++;
		fa[ M[S][pos1] ] = M[F][pos2];
		while( pos1 <= mcnt[S] ){
			int l1 = M[S][pos1];
			if(pos1 == mcnt[S] ){
	//	printf("p1:%d p2:%d\n",pos1,pos2);
				update( l1 );
				break;
			}
			else{
				int l2 = M[S][pos1+1];
				if( Map[l1][l2] != 2 ){
					update( l1 );
					pos2++;
					while( pos2 <= mcnt[F] && vis[ M[F][pos2] ] )pos2++;
				}
				fa[l2] = M[F][pos2];
				pos1++;
			}
		}
	}
/*	for(int i = 1 ; i <= n ; ++ i ){
		for(int j = 1 ; j <= n ; ++ j ){
			printf("%d ",Map[i][j]);
		}
		printf("\n");
	}*/
	for(int i = 1 ; i <= n ; ++ i ){
		if(fa[i] == -1 )printf("0");
		else printf("%d",fa[i]);
		if(i==n)printf("\n");
		else printf(" ");
	}
	return 0;
}
