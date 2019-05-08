#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[200005],b[200005];

int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		b[i]=a[i]-i;
	}
	bool f=1;
	for(i=1;i<n;i++){
		if(b[i]>b[i+1])f=0;
	}
	if(!f)printf(":(\n");
	else{
		for(i=1;i<=n;i++)printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}
