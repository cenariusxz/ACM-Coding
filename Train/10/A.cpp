#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int m,a[1010];

void fuck()
{
	int i,mn=0x7fffffff,sum=0;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&a[i]);
		//mn=min(mn,a[i]);
		sum+=a[i];
	}
	printf("%.6f\n",(double)a[1]/sum);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case %d: ",i);
		fuck();
	}
 return 0;
}
