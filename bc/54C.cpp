#include<stdio.h>
#include<string.h>
const int maxn=1e6+20;
/*线性筛O(n)时间复杂度内筛出maxn内欧拉函数值*/
int m[maxn],phi[maxn],p[maxn],pt;//m[i]是i的最小素因数，p是素数，pt是素数个数

void make()
{
	int N=1000005;
	int k;
	phi[1]=1;
	for(int i=2;i<=N;i++)
	{
		if(!m[i])//i是素数
			p[pt++]=m[i]=i,phi[i]=i-1;
		for(int j=0;j<pt&&(k=p[j]*i)<N;j++)
		{
			m[k]=p[j];
			if(m[i]==p[j])//为了保证以后的数不被再筛，要break
			{
				phi[k]=phi[i]*p[j];
				break;    
			}
			else
				phi[k]=phi[i]*(p[j]-1);//积性函数性质，f(i*k)=f(i)*f(k)
		}
	}
}
int main(){
	int T;
	make();
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d\n",phi[n+1]);
	}
	return 0;
}
