#include<stdio.h>
long long arr[21];
long long c(int a,int b)
{
    long long i,sum=1,j;
    for (i=a,j=1;i>=a-b+1,j<=b;i--,j++) sum=sum*i/j;
    return sum;
}
void func()
{
	int i;
	arr[1]=0;arr[2]=1;
	for(i=3;i<=26;i++)
		arr[i]=(i-1)*(arr[i-1]+arr[i-2]);
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        int h=n/2,i;
        long long ans=0;
        func();
        for(i=2;i<=h;i++){
            ans+=c(n,i)*arr[i];
            //printf("%I64d %I64d\n",c(n,i),arr[i]);
        }

        ans++;
        printf("%I64d\n",ans);
    }
    return 0;
}
