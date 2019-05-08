#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

const int mod=1e9;
const ll num=1000000000000000000ll;

__int128 gcd(__int128 a,__int128 b){
	return b?gcd(b,a%b):a;
}

int main(){
	int x,y,z;
	ll a,b;
	srand(time(NULL));
	for(int i=1;i<=1000-14;++i){
		while(1){
			x=rand()%mod+1;
			y=rand()%mod+1;
			z=rand()%mod+1;
			__int128 tmp=x/gcd(x,y)*y;
			tmp=tmp/gcd(tmp,z)*z;
			if(tmp<=num)break;
		}
		a=((ll)rand()<<32)+((ll)rand()<<1)+rand()%2;
		b=((ll)rand()<<32)+((ll)rand()<<1)+rand()%2;
		if(a>b){
			ll tmp=a;
			a=b;
			b=tmp;
		}
		printf("%d %d %d %lld %lld\n",x,y,z,a,b);
	}
}
