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

int num[105];

int main(){
	int n,b;
	scanf("%d%d",&n,&b);
	int cnt = 0;
	while(n){
		num[++cnt] = n % b;
		n /= b;	
	}
	for(int i = cnt ; i >= 1 ; -- i){
		printf("%d",num[i]);	
	}
	printf("\n");
	return 0;
}

