#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int i;
	int ans=4+2*(n-1)*4;
	for(i=1;i<n;i++){
		double y=sqrt(1.0*n*n-1.0*i*i);
		int t=y;
		double x=sqrt(1.0*n*n-1.0*t*t);
		if(x-i<1)ans-=4;
	}
	if(n==0)ans=1;
	printf("%d\n",ans);
	return 0;
}
