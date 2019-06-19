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

int n,b;
int h[maxn];

int main(){
	scanf("%d%d",&n,&b);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&h[i]);
	sort(h + 1 , h + 1 + n);
	int sum = 0;
	for(int i = n ; i >= 1 ; -- i){
		sum += h[i];
		if(sum >= b){
			printf("%d\n", n - i + 1);
			break;
		}
	}
	return 0;
}


