#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 1000000000
int prime[4000],count,a[4000],ex;
bool num[100000]={0};

 void spilit(int n)
 {
 	int i;
 	for(i=1;i<=count&&n>=prime[i];i++)
 		if(n%prime[i]==0){
 			n/=prime[i];
 			//printf(" %d\n",prime[i]);
 			a[i]++;
 			i--;
 		}
 	ex=n;
 }

int main()
{
	int i,j,ans,n;
	count=0;
	for(i=2;i<=sqrt(MAX);i++)
		if(num[i]==0){
			prime[++count]=i;
			for(j=i<<1;j<=sqrt(MAX);j+=i)
				num[j]=1;
		}
		//printf("%d\n",prime[count]);
		//printf("%d\n",count);
	while(scanf("%d",&n)!=EOF&&n){
		ans=1;
		memset(a,0,sizeof(a));
		spilit(n);
		//getchar();
		if(ex>1) ans=ex-1;
		for(i=1;i<=count;i++)
			if(a[i]) ans*=pow(prime[i],a[i])-pow(prime[i],a[i]-1);
		printf("%d\n",ans);
	}
 return 0;
}

