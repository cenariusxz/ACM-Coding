#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
typedef long long ll;

ll p,q,n;
ll *bb;
int num[10002];
char vis[21600000];
int ph[1365520];

ll solve(ll n,int len){
	int now=len-1;
	bool f=0;
	while(now){
		if(ph[now]<n){
			f=1;
			now++;
			break;
		}
		now--;
	}
	if(f)return now;
	return 0;
}

ll phi(ll x,ll a,ll m){
	if(a==m)return (x/q)*p+bb[x%q];
	if(x<ph[a-1])return 1;
	return phi(x,a-1,m)-phi(x/ph[a-1],a-1,m);
}

ll get(){
	int len=(int)exp(2.0*log(n)/3)+1;
	ll ans=0;
	for(int i=0;i<len;++i)if(!vis[i])ans++;
	int cnt=0;
	ll len1=solve((ll)exp(1.0/3*log(n)),ans);
	ll len2=solve((ll)sqrt(n),ans);
	ll len3=solve(len,ans);
	ll sum=0,s=0;
	int jj=len-2;
	for(ll i=(int)exp(1.0/3*log(n));i*i<=n;++i){
		if(!vis[i]){
			while(i*jj>n){
				if(!vis[jj])s++;
				jj--;
			}
			sum+=s;
		}
	}
	sum=(len2-len1)*len3-sum;
	sum+=(len1*(len1-1)-len2*(len2-1))/2;
	ll m=7;
	if(m>len1)m=len1;
	for(int i=0;i<m;++i){

		q*=ph[i];
		p*=ph[i]-1;
	}
	bb=(ll*)malloc(sizeof(ll)*q);
	for(int i=0;i<q;++i)bb[i]=i;
	for(int i=0;i<m;++i){
		for(int j=q-1;j>=0;--j)bb[j]-=bb[j/ph[i]];
	}
	sum=phi(n,len1,m)-sum+len1-1;
	free(bb);
	return sum;
}

void get_prime(){
	int cnt=0;
	memset(vis,0,sizeof(vis));
	memset(num,0,sizeof(num));
	for(int i=2;i<21544400;i++){
		if(!vis[i])ph[cnt++]=i;
		for (int j=0;j<cnt&&ph[j]*i<21544400;j++){
			vis[i*ph[j]]=1;
			if(i%ph[j]==0)break;
		}
	}
	vis[0]=vis[1]=1;
	for(int i=1;i<=10000;++i)num[i]=num[i-1]+1-vis[i];
}

int main(){
	get_prime();
	while(scanf("%lld",&n)!=EOF){
		if(n<=10000){
			printf("%d\n",num[n]);
			continue;
		}
		p=q=1;
		printf("%lld\n",get());
	}
	return 0;
}
