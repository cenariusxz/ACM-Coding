#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[10005],b[10005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		double sum=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		for(int i=1;i<=n;++i)sum+=b[i]*(double)b[i]*a[i]/3.0;
		double l=0,r=1000,mid;
		int m=18;
		while(m--){
			mid=(l+r)/2.0;
			double ss=0;
			for(int i=1;i<=n;++i){
				if(mid<a[i]){
					double bb=(a[i]-mid)*1.0*b[i]/(a[i]*1.0);
					ss+=bb*(double)bb*(a[i]-mid)/3.0;
				}
			}
			if(ss<sum/2)r=mid;
			else l=mid;
		}
		printf("%d\n",(int)mid);
	}
	return 0;
}
