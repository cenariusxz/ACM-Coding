#include<stdio.h>
#include<string.h>

char vis[15][15][15];	//0为已经删除的格子，#为还没有删除和判定的格子，字母为已经被判定的格子
char m[7][15][15];

int main(){
	int n,i,j,k;
	while(scanf("%d",&n)!=EOF&&n){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				for(k=1;k<=n;k++)vis[i][j][k]='#';
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=6;j++){
				scanf("%s",m[j][i]+1);
			}
		}
		int ans=n*n*n;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(m[1][i][j]=='.'){
					for(k=1;k<=n;k++){
						if(vis[k][j][i]=='#'){
							ans--;
							vis[k][j][i]='.';
						}
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(m[2][i][j]=='.'){
					for(k=1;k<=n;k++){
						if(vis[n-j+1][k][i]=='#'){
							ans--;
							vis[n-j+1][k][i]='.';
						}
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(m[5][i][j]=='.'){
					for(k=1;k<=n;k++){
						if(vis[n-i+1][j][k]=='#'){
							ans--;
							vis[n-i+1][j][k]='.';
						}
					}
				}
			}
		}
		bool f=1;
		while(f){
			f=0;
			for(i=1;i<=6;i++){
				for(j=1;j<=n;j++){
					for(k=1;k<=n;k++){
						if(vis[i][j][k]=='.')continue;
						for(int p=1;p<=n;p++){
							int x,y,z;
							if(i==1){
								x=p;y=k;z=j;
							}
							else if(i==2){
								x=n-k+1;y=p;z=j;
							}
							else if(i==3){
								x=n-p+1;y=n-k+1;z=j;
							}
							else if(i==4){
								x=k;y=n-p+1;z=j;
							}
							else if(i==5){
								x=n-j+1;y=k;z=p;
							}
							else if(i==6){
								x=j;y=k;z=n-p+1;
							}
							if(vis[x][y][z]=='.')continue;
							if(vis[x][y][z]=='#'){
								vis[x][y][z]=m[i][j][k];
								break;
							}
							if(vis[x][y][z]==m[i][j][k])break;
							vis[x][y][z]='.';
							ans--;
							f=1;
						}
					}
				}
			}
		}
		printf("Maximum weight: %d gram(s)\n",ans);
	}
	return 0;
}
