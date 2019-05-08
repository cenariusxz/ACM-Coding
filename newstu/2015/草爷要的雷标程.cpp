#include<stdio.h>

int gcd(int a,int b){return b?gcd(b,a%b):a;}

char s[15][15];
int xx[8]={-1,0,1,-1,1,-1,0,1};
int yy[8]={-1,-1,-1,0,0,1,1,1};

int main(){
	int n,m,i,j,px,py,num1,num2,dx,dy;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=1;i<=n;++i)scanf("%s",s[i]+1);
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				if(s[i][j]>='1'&&s[i][j]<='9'){px=i;py=j;}
			}
		}
		num1=s[px][py]-'0';num2=0;
		for(i=0;i<8;++i){
			dx=px+xx[i];dy=py+yy[i];
			if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&s[dx][dy]=='*')num2++;
		}
		printf("%d/%d\n",num1/gcd(num1,num2),num2/gcd(num1,num2));
	}
	return 0;
}
