#include<bits/stdc++.h>
using namespace std;
int n,m;

void fuck()
{
	int i,j,t,tt=n*60+m;
	int a=n,b=m,nine=0;
	double error=10,er;
	for(i=0;i<=99;i++)
		for(j=0;j<=99;j++){
			int cnt=0;
			t=60*i+j;
			er=fabs(t-tt*1.0)/tt;
			if(er>=0.1) continue;
			if(i%10==9) cnt++;
			if(i/10==9) cnt++;
			if(j%10==9) cnt++;
			if(j/10==9) cnt++;
			if(cnt>nine){
				nine=cnt;
				error=er;
				a=i;b=j;
			}
			else if(cnt==nine&&er<error){
				nine=cnt;
				error=er;
				a=i;b=j;
			}
		}
	printf("%02d:%02d\n",a,b);
}

int main()
{
	while(~scanf("%d:%d",&n,&m)&&(n||m))
		fuck();
 return 0;
}
