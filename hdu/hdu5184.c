#include<stdio.h>
#include<string.h>
#define ll long long
const ll mod=1000000007;
char s[1000005];
ll A[1000005];

void fun(){
	A[0]=A[1]=1;
	for(int i=2;i<=1000000;i++){
		A[i]=(A[i-1]*i)%mod;
	}
}
/*
ll C(ll a,ll b){
	ll i,ans=1;
	for(i=1;i<=b;i++){
		ans*=a-i+1;
		ans/=i;
	}
	return ans;
}
*/
ll QuickPow(ll a,ll n){
	ll tmp=a,ans=1;
	tmp %= mod;
	while(n){
		if(n&1) ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

int main(){
	int n;
	fun();
	while(scanf("%d%s",&n,s)!=EOF){
		if(n%2)printf("0\n");
		else{
			int p=0,q=0,i,l=strlen(s);
			for(i=0;i<l;i++){
				if(s[i]=='(')p++;
				else q++;
				if(p<q){
					printf("0\n");
					break;
				}
			}
			if(p<q) continue;
			{
				p=n/2-p;
				q=n/2-q;
				if(p<0||q<0){
					printf("0\n");
					continue;
				}
				ll r1=QuickPow(A[p],mod-2),r2=QuickPow(A[q+1],mod-2);
				ll ans=A[p+q];
			//	printf("%lld %lld %lld\n",ans,r1,r2);
				ans=(ans*((q-p+1)%mod))%mod;
				ans=(ans*r1)%mod;
				ans=(ans*r2)%mod;
				printf("%lld\n",ans);
			
			}
		}
	}
	return 0;
}
