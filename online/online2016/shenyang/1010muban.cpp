#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 5000005;

ll n;
bool isp[MAXN];		//i is prime?
int pcnt[MAXN];		//primes <= i
int pri[MAXN];		//prime list
int cnt;

void pre(){//处理1e7内的素数以及素数个数
	cnt=0;
	for(int i=2;i<MAXN;++i)isp[i]=1;
	for(int i=2;i<MAXN;++i){
		if(isp[i])pri[cnt++]=i;
		for(int j=0;j<cnt&&i*pri[j]<MAXN;++j)isp[i*pri[j]]=0;
	}
	pcnt[0]=0;
	for(int i=1;i<MAXN;++i)pcnt[i]=pcnt[i-1]+isp[i];
}

ll pri_cnt(ll lim);

ll phi(ll m, int n){	//phi函数
	if(m<=0)return 0;
	if(n==0)return m;
	if(pri[n-1]*pri[n-1]>=m)return pri_cnt(m)-n+1;
	return phi(m,n-1)-phi(m/pri[n-1],n-1);
}

ll pri_cnt(ll lim){
	if(lim<MAXN)return pcnt[lim];	//特判1e7内
	ll m3=1,m2=1;	//m3^3<=lim的最大值，m2^2<=lim的最大值
	while(m3*m3*m3<=lim)m3++;
	while(m2*m2<=lim)m2++;
	m3--;m2--;

	ll y=m3;
	ll n=pri_cnt(y);	//递归求 三次根号下lim 内的素数个数
	ll p2=0;
	for(ll p=y+1;p<=m2;p++){
		if(isp[p])p2+=pri_cnt(lim/p)-pri_cnt(p)+1;
	}
	ll ph=phi(lim,n);
	ll res=ph+n-1-p2;
	return res;
}

int main(){
	pre();
	while(scanf("%lld",&n)!=EOF){
		printf("%lld\n",pri_cnt(n));
	}
	return 0;
}
