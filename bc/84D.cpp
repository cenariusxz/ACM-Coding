#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int prime[maxn],primesize,phi[maxn];
int isprime[maxn];
void init(){
	primesize=0;
	int listsize=100000;
	for(int i=0;i<=100000;++i)isprime[i]=1;
	isprime[1]=0;
	for(int i=2;i<=listsize;i++){
		if(isprime[i])prime[++primesize]=i;
		for(int j=1;j<=primesize&&i*prime[j]<=listsize;j++){
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)break;
		}
	}
	phi[0]=0;
	for(int i=1;i<=100000;++i){
		phi[i]=phi[i-1]+isprime[i];
	}
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int n,d;
		scanf("%d%d",&n,&d);
		int a1=d,a2=n/d;
		if(n%d==0)a2--;
		int res=0;
		if(d<a2&&isprime[d]==1){
			res=d;
		}
		else{
			res=a2;
			for(int i=1;i<=primesize&&prime[i]<a2;++i){
				if(d%prime[i]==0){
					res=min(prime[i],res);
					break;
				}
			}
		}
		printf("%d\n",phi[res]);
	}
	return 0;
}
