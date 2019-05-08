#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

inline double get(int a,int x){
	return (a-1)*1.0*(x-a+1)+x+(x-a)*1.0*a;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int x,y,z,K;
		scanf("%d%d%d%d",&x,&y,&z,&K);
		double ans=0;
		for(int i=1;i<=x;++i){
			for(int j=1;j<=y;++j){
				for(int k=1;k<=z;++k){
					double p=get(i,x)*get(j,y)*get(k,z)/x/x/y/y/z/z;
					ans+=(1-pow(1-2*p,K))/2;
				}
			}
		}
		printf("Case %d: %.10lf\n",q,ans);
	}
	return 0;
}
