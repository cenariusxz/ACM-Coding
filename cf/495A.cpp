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

int num[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main(){
	int a, b;
	scanf("%1d%1d", &a, &b);
	printf("%d\n", num[a] * num[b]);
	return 0;
}


