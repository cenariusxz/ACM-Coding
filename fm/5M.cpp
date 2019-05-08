#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

inline ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

int pnum[50],num;

int check(int n){
	ll ans=0;
	for(int i=1;i<(1<<num);++i){
		int bit=0;
		int mul=1;
		for(int j=1;j<=num;++j){
			if(i&(1<<(j-1))){
				bit++;
				mul*=pnum[j];
			}
		}
		if(bit%2)ans+=n/mul;
		else ans-=n/mul;
	}
	return n-ans;
}

int main(){
	int m,k;
	while(scanf("%d%d",&m,&k)!=EOF){
		num=0;
		int tmp=m;
		for(int i=2;i*i<=tmp;++i){
			if(!(tmp%i)){
				pnum[++num]=i;
				tmp/=i;
				while(!(tmp%i))tmp/=i;
			}
		}
		if(tmp-1)pnum[++num]=tmp;
		int l=1,r=1000000000,mid;
		while(l<=r){
			mid=l+((r-l)>>1);
			int x=check(mid);
			if(x>k)r=mid-1;
			else if(x<k)l=mid+1;
			else if(gcd(m,mid)-1)r=mid-1;
			else break;
		}
		printf("%d\n",mid);
	}
	return 0;
}
