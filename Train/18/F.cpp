#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
using namespace std;
int n,k,p;
long long a[100010];

void fuck()
{
	int num1=0,num2=0,curr;
	int i;
	for(i=1;i<=n-k;i++) a[i]=1;
	num1=n-k;curr=2;
	for(i;i<=n;i++){
		//printf(" %lf %lf\n",(double)num1/(i-1.0),(double)p/100.0);
		if(num1*100ll>=(long long)p*(i-1)){
			num2++;
			a[i]=curr;
		}
		else{
			num1+=num2;
			num2=1;
			a[i]=++curr;
		}
	}
	cout << accumulate(a+1,a+n+1,0ll) << endl;
	for(i=1;i<n;i++){
		printf("%d ",(int)a[i]);
	}
	printf("%d\n",(int)a[i]);
//	printf("%d %d\n",num1,num2);
}

int main()
{
	while(~scanf("%d%d%d",&n,&k,&p))
		fuck();
 return 0;
}
