#include<stdio.h>
long long sum;
 void dfs(int x,int y){
 	int i;
 	if(x==0){
 		sum+=y;
 		return;
 	}
 	dfs(x-2,y*3);
 	for(i=4;i<=x;i+=2)
 		dfs(x-i,y*2);
 }

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
	//for(n=0;n<=30;n++){
		if(n==-1) break;
		sum=0;
		if(n%2==0) dfs(n,1);
		printf("%I64d\n",sum);
	}
 return 0;
}
/*
#include<stdio.h>

int main()
{
	int a[31]={1,0,3};
	int n,i;
	for(i=4;i<=30;i+=2) a[i]=4*a[i-2]-a[i-4];
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",a[n]);
	}
 return 0;
}
*/
