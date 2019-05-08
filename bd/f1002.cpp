#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int pre[4][2],pos[4][2];
int dp0[4][4][4][4];
int dp1[4][4][4][4];

int aabs(int x){return x<0?-x:x;}

int cost(int i,int j){
	return aabs(pre[i][0]-pos[j][0])+aabs(pre[i][1]-pos[j][1]);
}

void judge(int w,int x,int y,int z,int a,int b,int c,int d){
	if(pos[a][1]>pos[b][1]||pos[b][1]>pos[c][1]||pos[c][1]>pos[d][1])return;
//	printf("aaa\n");
//	printf("%d %d %d %d\n",a,b,c,d);
//	printf("%d %d %d %d\n",cost(w,a),cost(x,b),cost(y,c),cost(z,d));
	int co=dp0[w][x][y][z]+cost(w,a)+cost(x,b)+cost(y,c)+cost(z,d);
	if(dp1[a][b][c][d]==-1||dp1[a][b][c][d]>co)dp1[a][b][c][d]=co;
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n;
		scanf("%d",&n);
		int i,j,k,p,m,a,b,c,d;
		pre[0][0]=pre[1][0]=pre[2][0]=pre[3][0]=0;
		pre[0][1]=1;
		pre[1][1]=2;
		pre[2][1]=3;
		pre[3][1]=4;
		memset(dp0,-1,sizeof(dp0));
		memset(dp1,-1,sizeof(dp1));
		dp0[0][1][2][3]=0;
		for(i=1;i<=n;i++){
			for(j=0;j<4;j++)scanf("%d%d",&pos[j][0],&pos[j][1]);
			for(j=0;j<4;j++){
				for(k=0;k<4;k++){
					if(k==j)continue;
					for(p=0;p<4;p++){
						if(p==j||p==k)continue;
						for(m=0;m<4;m++){
							if(m==j||m==k||m==p)continue;
							if(dp0[j][k][p][m]==-1)continue;
							for(a=0;a<4;a++){
								for(b=0;b<4;b++){
									if(b==a)continue;
									for(c=0;c<4;c++){
										if(c==a||c==b)continue;
										for(d=0;d<4;d++){
											if(d==a||d==b||d==c)continue;
											judge(j,k,p,m,a,b,c,d);
										}
									}
								}
							}
						}
					}
				}
			}
			memcpy(pre,pos,sizeof(pre));
			memcpy(dp0,dp1,sizeof(dp0));
			memset(dp1,-1,sizeof(dp1));
		}
		int ans=0x7fffffff;
		for(a=0;a<4;a++){
			for(b=0;b<4;b++){
				if(b==a)continue;
				for(c=0;c<4;c++){
					if(c==a||a==b)continue;
					for(d=0;d<4;d++){
						if(d==a||d==b||d==c)continue;
						if(dp0[a][b][c][d]==-1)continue;
						if(dp0[a][b][c][d]<ans)ans=dp0[a][b][c][d];
					}
				}
			}
		}
		printf("Case #%d:\n%d\n",q,ans);
	}
	return 0;
}
