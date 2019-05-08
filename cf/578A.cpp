#include<stdio.h>
#include<string.h>

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	if(a<b)printf("-1\n");
	else{
		int c1=a+b;
		int c2=a-b;
		int k=c1/(2.0*b);
		double x1=c1/(2.0*k);
		k=c2/(2.0*b);
		double x2=c2/(2.0*k);
		if(x1>x2)printf("%.10lf\n",x2);
		else printf("%.10lf\n",x1);
	}
	return 0;
}
