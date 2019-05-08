#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

double p[25];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i)scanf("%lf",&p[i]);
		double ans=0;
		for(int i=1;i<(1<<n);++i){
			int bit=0;
			double tmp=0;
			for(int j=1;j<=n;++j){
				if(i&(1<<(j-1))){
					bit++;
					tmp+=p[j];
				}
			}
			if(bit%2)ans+=1.0/tmp;
			else ans-=1.0/tmp;
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}
