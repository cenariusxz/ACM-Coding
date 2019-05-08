#include<bits/stdc++.h>
using namespace std;
long long int n,a,b,c,d,e,j;
int main()
{
	d=100000000000000;
	scanf("%lld",&n);
	e=1000000;
	long long i=2;
	while(i*i<=n){
		c=i;
		j=1;
		while(c*i <= n){
			c*=i;
			j++;
			if(d > n-c ||( d == n-c && e>j)){
				d=n-c;
				e=j;
				a=i;
			}
		}
		i++;
	}
	printf("%lld %lld",a,e);
	return 0;
}
