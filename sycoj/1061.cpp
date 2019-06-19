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

int m,s,c;
int a[maxn],d[maxn];

int main(){
	scanf("%d%d%d",&m,&s,&c);
	for(int i = 1 ; i <= c ; ++ i)scanf("%d",&a[i]);
	sort(a + 1 , a + 1 + c);
	for(int i = 1 ; i < c ; ++ i)d[i] = a[i+1] - a[i] - 1;
	sort(d + 1 , d + c);
	int ans = a[c] - a[1] + 1;
	for(int i = 1 ; i < min(m, c) ; ++ i)ans -= d[c-i];
	printf("%d\n", ans);
	return 0;
}


