#include<stdio.h>
#include<string.h>
#include<math.h>

double dp[1005][1005];
double p[1000];

int main(){
	int w,b;
	while(scanf("%d%d",&w,&b)!=EOF){
		memset(dp,0,sizeof(dp));
		dp[w][b]=w*1.0/(w+b);
		int cnt=0;
		p[++cnt]=dp[w][b];
		double ans=dp[w][b];
		int i,j,k;
		for(k=w+b-3;k>=1;k-=3){
			for(i=w;i>=1;i++){
				j=k-i;
				dp[i][j]=
			}
		}
		/*
		for(i=w;i>=1;i--){
			for(j=b;j>=0;j--){
				int f=w+b-i-j;
				if((f+3)%3==0&&(i!=w||j!=b)){
					double p1=0,p2=0;
					if(i+1<=w)p1=(1-dp[i+1][j+2][0])*(j+1)*(i+1)*i*1.0/((i+j+2)*(i+j+1)*(i+j));
					if(j+3<=b)p2=(1-dp[i][j+3][0])*(j+2)*(j+1)*i*1.0/((i+j+2)*(i+j+1)*(i+j));
					printf("%d %d %.10lf %.10lf\n",i,j,p1,p2);
					ans+=(p1+p2);
				}
			}
		}*/
		printf("%.10lf\n",ans);
	}
	return 0;
}
