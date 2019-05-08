#include <stdio.h>
#include <math.h>
using namespace std;

void fuck()
{
	int x,y;
	double p,q;
	scanf("%d%d%lf%lf",&x,&y,&p,&q);
	double t=q*p*(x+y)+x*(1-q);
	double w=q*y+p*(1-q)*(x+y);
	if(t>w) printf("tiger %.4f\n",t);
	else printf("wolf %.4f\n",w);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) fuck();
 return 0;
}
