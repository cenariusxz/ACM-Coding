#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

char s[15][15];

int xx[8]={-1,0,1,-1,1,-1,0,1};
int yy[8]={-1,-1,-1,0,0,1,1,1};

int main(){
	srand(time(NULL));
	for(int q=1;q<=1000-2;++q){
		memset(s,0,sizeof(s));
		int n,m;
		n=rand()%9+2;
		m=rand()%9+2;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j)s[i][j]='*';
		}
		int px,py;
		px=rand()%n+1;
		py=rand()%m+1;
		int nnum=0;
		for(int i=0;i<8;++i){
			int dx=px+xx[i],dy=py+yy[i];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m)nnum++;
		}
		int num1=rand()%nnum+1;
		s[px][py]='0'+num1;
		if(nnum!=num1){
			int mnum=rand()%(nnum-num1);
			while(mnum){
				for(int i=0;i<8&&mnum;++i){
					int dx=px+xx[i],dy=py+yy[i];
					if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&s[dx][dy]=='*'){
						if(rand()%2){
							s[dx][dy]='.';
							mnum--;
						}
					}
				}
			}
		}
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;++i)printf("%s\n",s[i]+1);
	}
	return 0;
}
