#include<stdio.h>
#include<string.h>

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int c[8][8];
int vis[8];
int f[1000005];
int v[8][1000005];

void init(){
	c[1][1]=c[1][2]=c[1][3]=c[1][4]=c[1][5]=c[1][6]=c[1][7]=1;
	c[2][1]=c[2][3]=c[2][5]=c[2][7]=1;
	c[2][2]=c[2][4]=c[2][6]=2;
	c[3][1]=c[3][2]=c[3][4]=c[3][5]=c[3][7]=1;
	c[3][3]=c[3][6]=3;
	c[4][1]=c[4][3]=c[4][5]=c[4][7]=1;
	c[4][2]=c[4][6]=2;
	c[4][4]=4;
	c[5][1]=c[5][2]=c[5][3]=c[5][4]=c[5][6]=c[5][7]=1;
	c[5][5]=5;
	c[6][1]=c[6][5]=c[6][7]=1;
	c[6][2]=c[6][4]=2;
	c[6][3]=3;
	c[6][6]=6;
	c[7][1]=c[7][2]=c[7][3]=c[7][4]=c[7][5]=c[7][6]=1;
	c[7][7]=7;
	for(int i=2;i<=1000000;i++){
		if(f[i])continue;
		for(int j=1;i*j<=1000000;j++){
			f[i*j]++;
		}
	}
	for(int i=1;i<=1000000;i++){
		for(int j=1;j<=7;j++){
			if(f[i]==j){
				v[j][i]=v[j][i-1]+1;
			}
			else v[j][i]=v[j][i-1];
		}
	}
}

int main(){
	init();
	int T=read();
	while(T--){
		int l=read();
		int r=read();
		int a[8];
		int i,j,maxx=0;
		for(i=1;i<=7;i++){
			a[i]=v[i][r]-v[i][l-1];
		}
		for(i=1;i<=7;i++){
			for(j=i;j<=7;j++){
				if(a[i]&&a[j]){
					if(i==j){
						if(a[i]>=2&&c[i][i]>maxx)maxx=c[i][i];
					}
					else{
						if(c[i][j]>maxx)maxx=c[i][j];
					}
				}
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}
