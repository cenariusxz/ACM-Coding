#include <bits/stdc++.h>
using namespace std;
double p[160][160],e[160][160];
int n,m;

double P(int a,int b)
{
	if(p[a][b]>=0) return p[a][b];
	int c=min(a,b);
	return p[a][b]=0.5*p[a-c][b]+0.5*p[a][b-c];
}

double E(int a,int b)
{
	if(e[a][b]>=0) return e[a][b];
	int c=min(a,b);
	return e[a][b]=0.5*e[a-c][b]+0.5*e[a][b-c]+1;
}

void fuck()
{
	int i;
	scanf("%d%d",&n,&m);
	printf("%.6f %.6f\n",E(n,m),P(n,m));
}

int main()
{
	int t,i,j;
	for(i=0;i<=150;i++)
		for(j=0;j<=150;j++)
			p[i][j]=e[i][j]=-1;
	for(i=0;i<=150;i++){
		p[i][0]=1;
		e[i][0]=0;
	}
	for(i=0;i<=150;i++){
		p[0][i]=0;
		e[0][i]=0;
	}
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}
