#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
int A,B,C,D;
double dp[15][15][15][15][4][4][4][4];
double p[16][16][16][16];
double res;

double f(int a,int b,int c,int d,int aa,int bb,int cc,int dd)
{
	int sum1=a+b+c+d,sum2=aa+bb+cc+dd;
	int sum=sum1+sum2;
	double p=0,tmp=100;
	if(a+aa>=A&&b+bb>=B&&c+cc>=C&&d+dd>=D){
		return 0;
	}
	if(dp[a][b][c][d][aa][bb][cc][dd]>eps)
		return dp[a][b][c][d][aa][bb][cc][dd];
	if(a<13) p+=f(a+1,b,c,d,aa,bb,cc,dd)*(13-a)/(54-sum);
	if(b<13) p+=f(a,b+1,c,d,aa,bb,cc,dd)*(13-b)/(54-sum);
	if(c<13) p+=f(a,b,c+1,d,aa,bb,cc,dd)*(13-c)/(54-sum);
	if(d<13) p+=f(a,b,c,d+1,aa,bb,cc,dd)*(13-d)/(54-sum);
	if(sum2<2){
		if(aa<2) tmp=min(tmp,f(a,b,c,d,aa+1,bb,cc,dd));
		if(bb<2) tmp=min(tmp,f(a,b,c,d,aa,bb+1,cc,dd));
		if(cc<2) tmp=min(tmp,f(a,b,c,d,aa,bb,cc+1,dd));
		if(dd<2) tmp=min(tmp,f(a,b,c,d,aa,bb,cc,dd+1));
		if(tmp>99) tmp=0;
		p+=tmp*(2-sum2)/(54-sum);
	}
	dp[a][b][c][d][aa][bb][cc][dd]=p+1;
	return p+1;
}

void fuck()
{
	int ff=0;
	scanf("%d%d%d%d",&A,&B,&C,&D);
	memset(dp,0,sizeof(dp));
	if(A>15||B>15||C>15||D>15){
		printf("-1.000\n");
		return;
	}
	if(A>13) ff+=A-13;
	if(B>13) ff+=B-13;
	if(C>13) ff+=C-13;
	if(D>13) ff+=D-13;
	if(ff>2){
		printf("-1.000\n");
		return;
	}
	/*memset(dp,0,sizeof(dp));
	memset(p,0,sizeof(p));
	dp[0][0][0][0][0][0][0][0]=1;
	for(a=0;a<=15;a++)
		for(b=0;b<=15;b++)
			for(c=0;c<=15;c++)
				for(d=0;d<=15;d++)
					p[a][b][c][d]=2;
	for(a=0;a<=13;a++)
	for(b=0;b<=13;b++)
	for(c=0;c<=13;c++)
	for(d=0;d<=13;d++){
		for(aa=0;aa<=2;aa++)
		for(bb=0;bb<=2;bb++)
		for(cc=0;cc<=2;cc++)
		for(dd=0;dd<=2;dd++){
			sum1=a+b+c+d;
			sum2=aa+bb+cc+dd;
			if(sum1+sum2>54) continue;
			if(sum2>2) continue;
			if(dp[a][b][c][d][aa][bb][cc][dd]<eps) continue;
			double tmp=dp[a][b][c][d][aa][bb][cc][dd];
			if(a+aa>=A&&b+bb>=B&&c+cc>=C&&d+dd>=D){
				if(p[a+aa][b+bb][c+cc][d+dd]<1.5)
					ans-=(sum1+sum2)*p[a+aa][b+bb][c+cc][d+dd];
				p[a+aa][b+bb][c+cc][d+dd]=min(p[a+aa][b+bb][c+cc][d+dd],tmp);
				ans+=(sum1+sum2)*p[a+aa][b+bb][c+cc][d+dd];
				continue;
			}
			p[a+aa][b+bb][c+cc][d+dd]=max(tmp,p[a+aa][b+bb][c+cc][d+dd]);
			if(a<13) dp[a+1][b][c][d][aa][bb][cc][dd]+=tmp*(13-a)/(54-sum1-sum2);
			if(b<13) dp[a][b+1][c][d][aa][bb][cc][dd]+=tmp*(13-b)/(54-sum1-sum2);
			if(c<13) dp[a][b][c+1][d][aa][bb][cc][dd]+=tmp*(13-c)/(54-sum1-sum2);
			if(d<13) dp[a][b][c][d+1][aa][bb][cc][dd]+=tmp*(13-d)/(54-sum1-sum2);
			if(sum2==2) continue;
			if(aa<2) dp[a][b][c][d][aa+1][bb][cc][dd]+=tmp*(2-sum2)/(54-sum1-sum2);
			if(bb<2) dp[a][b][c][d][aa][bb+1][cc][dd]+=tmp*(2-sum2)/(54-sum1-sum2);
			if(cc<2) dp[a][b][c][d][aa][bb][cc+1][dd]+=tmp*(2-sum2)/(54-sum1-sum2);
			if(dd<2) dp[a][b][c][d][aa][bb][cc][dd+1]+=tmp*(2-sum2)/(54-sum1-sum2);
		}
	}*/
	printf("%.3f\n",f(0,0,0,0,0,0,0,0));
}

int main()
{
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case %d: ",i);
		fuck();
	}
 return 0;
}
