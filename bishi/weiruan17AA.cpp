#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
double ans=0;
double num[105] = {0};
int n,p,q;

int main(){
	scanf("%d%d%d",&p,&q,&n);
	for(int pre = 0 ; pre <= 100 ; ++ pre ){
		int cnt = 0;
		double p1 = 1;
		while(1){
			double xq = ( pre + cnt * q) / 100.0;
			if( pre + cnt * q >= 100 ){
				num[pre] += ( cnt + 1 ) * p1 ;
				break;
			}
			num[pre] += p1 * xq * ( cnt + 1 );
			p1 *= ( 1 - xq );
			cnt++;
		}
	}

	int pre = p;
	for(int i = 1 ; i <= n ; ++ i ){
		if( pre == 0 ){
			ans += ( n - i + 1 ) * num[0];
			break;
		}
		ans += num[pre];
		pre >>= 1;
	}
	
	printf("%.2lf\n",ans);
	return 0;
}
