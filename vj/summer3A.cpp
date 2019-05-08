#include<stdio.h>
#include<string.h>

int num[1005][1005];

int gcd(int a,int b){
	for(;a>0&&b>0;a>b?a%=b:b%=a);
	return a+b;
}

int main(){
	freopen("avangard.in","r",stdin);
	freopen("avangard.out","w",stdout);
	int n,i,j;
	scanf("%d",&n);
	if(n==1){
		printf("Yes\n1\n");
		return 0;
	}
	if(n<=4||!(n%2)||!(n%3)){
		printf("No\n");
		return 0;
	}
	int cnt1=1;
	int p=2;/*
	while(p<n){
		if(gcd(n,p)==1&&gcd(n,p+1)==1)break;
		p++;
	}
	if(p>=n){
		printf("No\n");
		return 0;
	}

	printf("%d\n",p);*/
	for(i=1;i<=2*n;i+=2){
		int a=(i%n)?(i%n):n;
		int cnt=cnt1;
		for(j=1;j<=n;j++){
			num[a][j]=(cnt%n)?(cnt%n):n;
			cnt++;
		}
		cnt1++;
	}

	printf("Yes\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%2d",num[i][j]);
			if(j==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
