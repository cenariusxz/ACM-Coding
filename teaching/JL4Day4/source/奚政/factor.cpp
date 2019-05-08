#include<cstdio>
#include<iostream>
using namespace std;

int a[5000];
int main()
{
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout);
	int n,i,j,k,m;
	a[1]=1;
	int len=1,x=0;
	cin>>n;
	for(i=2;i<=n;i++){
		x=0;
		for(j=1;j<=len;j++){
			a[j]=a[j]*i+x;
			x=a[j]/10;
			a[j]=a[j]%10;
		}
		while(x){
			a[j]=x%10;
			x/=10;
			j++;
		}
		len=j-1;
	}
	int sum=0;
	for (i=len;i>=1;i--)
		sum+=a[i];
	cout<<sum<<endl;
	return 0;
}
