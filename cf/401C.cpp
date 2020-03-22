#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int num[maxm];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(m < n-1 || m > (n+1) * 2)printf("-1\n");
	else{
		for(int i = 1 ; i <= n-1 ; ++ i)num[i] = 1;
		m -= n-1;
		for(int i = 0 ; i <= n && m ; ++ i){
			int d = min(m, 2 - num[i]);
			m -= d;
			num[i] += d;
		}
		for(int i = 0 ; i <= n ; ++ i){
			if(i)putchar('0');
			while(num[i] --)putchar('1');
		}
		putchar('\n');
	}
	return 0;
}

