#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

double c[55];
int a[55];

bool cmp(int a,int b){return a>b;}

int main(){
	c[1]=1;
	for(int i=2;i<=50;++i)c[i]=c[i-1]*0.95;
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		double sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;++i){
			sum+=a[i]*c[i];
		}
		printf("%.10lf\n",sum);
	}
	return 0;
}
