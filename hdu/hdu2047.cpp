#include<stdio.h>
#include<math.h>
long long c(int a,int b){
	long long i,sum=1,j;
	for(i=a,j=1;i>=a-b+1,j<=b;i--,j++)sum=sum*i/j;
	return sum;
}

int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		int i,imax;
		long long sum=0;
		imax=(n%2)?((n+1)/2):(n/2);
		for(i=0;i<=imax;i++)sum+=(c(n-i+1,i)*(long long)(pow(2.0,n-i)));
		printf("%lld\n",sum);
	}
	return 0;
}
