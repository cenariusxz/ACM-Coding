#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
map < ll , int > M;

int num[2][maxn];
int Max[3][maxn];
int dp[maxn];

int main(){
	int n;
	scanf("%d", &n);
	for( int i = 1 ; i <= n ; ++ i ){
		scanf( "%d" , &num[0][i]);
	}

	for( int i = 1 ; i <= n ; ++ i ){
		scanf( "%d" , &num[1][i]);
	}

	memset( Max , 0 , sizeof( Max));
	M[0] = 1;
	ll sum = 0 ;
	for( int i = 1 ; i <= n ; ++ i ){
		sum += num[0][i];
		if( M[sum] != 0 ) Max[0][i] = M[sum];
		M[sum] = i + 1 ;
	}
	M.clear();
	M[0] = 1;
	sum = 0 ;
	for( int i = 1 ; i <= n ; ++ i ){
		sum += num[1][i];
		if( M[sum] != 0 ) Max[1][i] = M[sum];
		M[sum] = i + 1 ;
	}
	M.clear();
	M[0] = 1 ;
	sum = 0 ;	
	for( int i = 1 ; i <= n ; ++ i ) {
		sum += num[0][i] + num[1][i];
		if( M[sum] != 0 ) Max[2][i] = M[sum];
		M[sum] = i + 1;
	}
	for( int i = 1 ; i <= n ; ++ i ){
		for( int j = 0 ; j <= 2 ; ++ j ){
			Max[j][i] = max( Max[j][i-1] , Max[j][i] );
		}
	}

	memset( dp , 0 , sizeof ( dp ));
	
	for( int i = 1 ; i <= n ; ++ i ){
		dp[i] = dp[i-1] ;
		if( Max[2][i] != 0 ){
			dp[i] = max( dp[i] , dp[Max[2][i]-1] + 1 );
		}
		if( Max[0][i] != 0 ){
			dp[i] = max( dp[i] , dp[Max[0][i]-1] + 1 );
		}
		if( Max[1][i] != 0 ){
			dp[i] = max( dp[i] , dp[Max[1][i]-1] + 1 );
		}
		if( Max[0][i] != 0 && Max[1][i] != 0 ){
			int pre = min( Max[0][i] , Max[1][i] );
			dp[i] = max( dp[i] , dp[pre - 1 ] + 2);
		}
	}
	printf("%d\n", dp[n] );

	return 0;
}
