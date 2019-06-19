#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int n,m;
int a[maxn]; 

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	int sum = m, ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(sum + a[i] > m)ans ++, sum = a[i];
		else sum += a[i];	
	}
	printf("%d\n",ans);
	return 0;
}


