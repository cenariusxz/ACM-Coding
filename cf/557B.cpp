#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

double x[200005];

int main(){
	int n;
	double w;
	int i;
	scanf("%d%lf",&n,&w);
	for(i=1;i<=2*n;i++)scanf("%lf",&x[i]);
	sort(x+1,x+2*n+1);
	double p1=x[1],p2=x[n+1];
	if(p2<2*p1){
		p1=p2/2;	
	}
	else{
		p2=2*p1;
	}
	if(3*p1*n<=w)printf("%.10lf\n",3*p1*n);
	else printf("%.10lf\n",w);
	return 0;
}
