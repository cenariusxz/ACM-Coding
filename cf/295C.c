#include<stdio.h>
#include<string.h>
#define ll long long
#define max(a,b) a>b?a:b
const ll mod=1000000007;
int a[4],m=-1;

int read(){
	char c=getchar();
	while(c!='A'&&c!='C'&&c!='G'&&c!='T'){
		c=getchar();
	}
	while(c=='A'||c=='C'||c=='G'||c=='T'){
		if(c=='A')a[0]++;
		if(c=='C')a[1]++;
		if(c=='G')a[2]++;
		if(c=='T')a[3]++;
		c=getchar();
	}
	m=max(m,a[0]);
	m=max(m,a[1]);
	m=max(m,a[2]);
	m=max(m,a[3]);
	int ans=0;
	for(int i=0;i<=3;i++){
		if(a[i]==m)ans++;
	}
	return ans;
}

ll Pow(ll a,ll n){
	ll ans=1,tmp=a;
	while(n){
		if(n&1)ans=ans*tmp%mod;
		tmp=tmp*tmp%mod;
		n>>=1;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	int num=read();
	ll ans=Pow(num,n);
	printf("%I64d\n",ans);
}
