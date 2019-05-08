#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long ll;

ll n,k;

ll B[100];

void init(){
	B[0]=1;
	int pos = 1 ;
	while(1){
		B[pos] = B[pos-1] * 2 ;
		if(B[pos] - 1 > 1e18)break;
		pos++;
	}
	
}

int main(){
	int T;
	init();
	scanf("%d",&T);
	for( int q = 1 ; q <= T ; ++ q ){
		scanf("%lld%lld",&n,&k);
		int pos=0;
		while( k > B[pos] - 1 )++pos;
//		printf("%lld\n", B[ pos - 1 ] - 1);
		ll N = n - ( B[pos-1] - 1 );
		ll ce = N / B[pos-1];
		ll tmp = N - ce * B[pos-1];
		ll id = k - ( B[pos-1] - 1 );
		printf("Case #%d: ",q);
		ll ans1,ans2;
		if(id <= tmp){
			ans1 = ce / 2;
			ans2 = ce - ans1;
		}
		else{
			ans1 = ( ce - 1 ) / 2;
			ans2 = ( ce - 1 ) - ans1;
		}
		if(ans1 < ans2)swap(ans1,ans2);
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}
