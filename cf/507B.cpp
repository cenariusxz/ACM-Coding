#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const double esp=1e-16;
/*
double aabs(double a){
	return a<0?-a:a;
}*/

int main(){
	ll r,x1,y1,x2,y2;
	scanf("%I64d%I64d%I64d%I64d%I64d",&r,&x1,&y1,&x2,&y2);
	double d=sqrt((x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0);
	double num=d/(2*r);
	ll num2=(ll)num;
	ll ans=num2;
	if(fabs(num-num2)>esp)ans++;
	printf("%I64d\n",ans);
	return 0;
}
