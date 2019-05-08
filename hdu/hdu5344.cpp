#include<stdio.h>
#include<string.h>
typedef long long ll;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	int T=read();
	while(T--){
		int n=read();
		int m=read();
		int z=read();
		int l=read();
		ll a=0;
		ll sum=0;
		for(int i=2;i<=n;i++){
			a=(a*m+z)%l;
			sum^=(a+a);
		}
		printf("%lld\n",sum);
	}
	return 0;
}
