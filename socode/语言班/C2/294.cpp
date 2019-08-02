#include <bits/stdc++.h>
using namespace std;

int main(){
	double a,b,x,y;
	scanf("%lf%lf%lf%lf",&x,&a,&y,&b);
	double ans = (x*a-y*b)/(a-b);
	printf("%.2lf\n",ans);
	return 0;
}
