#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define ll long long

ll a[100005],b[100005],v[100005];

int main(){
	int n,m,i;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i++){
		scanf("%I64d",&v[i]);
		a[i]=a[i-1]+v[i];
	}
	sort(v+1,v+n+1);
	for(i=1;i<=n;i++){
		b[i]=b[i-1]+v[i];
	}
	int t,b1,b2;/*
	for(i=1;i<=n;i++){
		printf("%I64d",b[i]);
	}
	printf("\n");*/
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&t,&b1,&b2);
		if(t==1){
			printf("%I64d\n",a[b2]-a[b1-1]);
		}
		else if(t==2){
			
			printf("%I64d\n",b[b2]-b[b1-1]);
		}
	}
	return 0;
}
