#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
double dp[maxn];
double ans=0;
double num = 0;
int n,p,q;

void dfs( int sum , double p1 , int pp ,int k ){
//	printf("pp:%d\n",pp);
	if( sum == n ){
		ans += p1 * k;
		return;
	}
	if( pp == 0 ){
		ans += p1 * ( k + ( n - sum ) * num );
		return;
	}
	if( pp < 100)dfs( sum , p1*(100-pp)/100 , min(100,pp+q) , k+1 );
	dfs( sum+1 , p1*pp/100 , p/(1<<(sum+1)) , k+1 );
}

int main(){
	scanf("%d%d%d",&p,&q,&n);
	int cnt = 0;
	double p1 = 1;
	while(1){
//		printf("%f\n",p1);

		double xq = cnt * q / 100.0;
//		printf("xq : %f\n",xq);
		if( cnt * q >= 100 ){
			num += ( cnt + 1 ) * p1 ;
			break;
		}
		num += p1 * xq * ( cnt + 1 );
		p1 *= ( 1 - xq );
		cnt++;
	}
	printf("inum :%.10lf\n",num);
	ans = 0;
	dfs(0,1,p,0);
	
	printf("%.2lf\n",ans);
	return 0;
}
