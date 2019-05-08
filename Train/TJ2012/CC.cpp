#include <bits/stdc++.h>
using namespace std;
char s1[1010],s2[1010];
int dp[1010][1010],n;

void f(int &x,int y)
{
	x=min(x,y);
}

void fuck()
{
	int i,j,k,l,t,step[5],a1,b1,c1,num,a2,b2,c2;
	n=strlen(s1+1);
	s1[n+1]=s2[n+1]=s1[n+2]=s2[n+2]=s1[n+3]=s2[n+3]='0';
	memset(dp,0x3f,sizeof(dp));
	a1=s1[1]-'0';
	b1=s1[2]-'0';
	c1=s1[3]-'0';
	dp[1][a1*100+b1*10+c1]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<1000;j++){
			if(dp[i][j]>1000000) continue;
			a1=j/100;b1=(j/10)%10;c1=j%10;
			step[0]=s2[i]-'0'-a1;
			step[2]=abs(step[0]);
			if(step[0]<0) step[0]+=10;
			step[1]=10-step[0];
			step[3]=10-step[2];
			
			c2=s1[i+3]-'0';
			a2=b1;b2=c1;
			f(dp[i+1][a2*100+b2*10+c2],dp[i][j]+step[2]);
			a2=(b1+step[0])%10;b2=c1;
			f(dp[i+1][a2*100+b2*10+c2],dp[i][j]+step[2]);
			a2=(b1+step[0])%10;b2=(c1+step[0])%10;
			f(dp[i+1][a2*100+b2*10+c2],dp[i][j]+step[2]);

			a2=b1;b2=c1;
			f(dp[i+1][a2*100+b2*10+c2],dp[i][j]+step[3]);
			a2=(b1-step[1]+10)%10;b2=c1;
			f(dp[i+1][a2*100+b2*10+c2],dp[i][j]+step[3]);
			a2=(b1-step[1]+10)%10;b2=(c1-step[1]+10)%10;
			f(dp[i+1][a2*100+b2*10+c2],dp[i][j]+step[3]);
		}
	}
	printf("%d\n",dp[n+1][0]);
}

int main()
{
	while(~scanf("%s%s",s1+1,s2+1)) fuck();
 return 0;
}
