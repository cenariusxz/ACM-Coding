#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

double num[20];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lf",&num[i]);
		double s,l=0,r=5000;
		double m;
		for(int i=1;i<=100;++i){
			m=(l+r)/2.0;
			double sum=0;
			for(int j=1;j<=n;++j)sum+=pow(num[j],m);
			if(sum>1)l=m;
			if(sum<1)r=m;
		}
		int cnt=(1<<n)-n-1;
		int len=0;
		while(1){
			if(cnt>(1<<len))len++;
			else break;
		}
		if(cnt<(1<<len))len--;
		printf("%.6lf\n",m*pow(0.5,len*1.0));
	}
	return 0;
}
