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

int n;

int main(){
	int cntp = 0, cntn = 0;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		if(a > 0)cntp++;
		if(a < 0)cntn++;
	}
	if(2 * cntp >= n)printf("1\n");
	else if(2 * cntn >= n)printf("-1\n");
	else printf("0\n");

	return 0;
}

