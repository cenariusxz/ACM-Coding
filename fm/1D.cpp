#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

inline double aabs(double a){
	return a>=0?a:-a;
}

int main(){
	int n,m,i;
	while(scanf("%d%d",&n,&m)!=EOF){
		double ans=0;
		for(i=1;i<n;i++){
			double pos=(i*1.0/n*(n+m));
			ans+=aabs(pos-floor(pos+0.5))/(n+m);
		}
		printf("%lf\n",ans*10000);
	}
	return 0;
}
