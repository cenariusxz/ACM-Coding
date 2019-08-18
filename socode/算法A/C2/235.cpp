#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 5e6 + 5;
const int maxm = 1e6 + 5;

bool notprime[maxn];
int sum[maxn];

int init(){
	notprime[1] = 1;
	for(int i = 2 ; i < maxn ; ++ i){
		if(!notprime[i]){
			for(int j = i + i ; j < maxn ; j += i){
				notprime[j] = 1;
			}
		}
	}
	for(int i = 1 ; i < maxn ; ++ i){
		sum[i] = sum[i-1] + (!notprime[i]);	
	}
}

int main(){
	init();
	int n;
	scanf("%d",&n);
	while(n--){
		int L,R;
		scanf("%d%d",&L,&R);
		printf("%d\n", sum[R] - sum[L-1]);	
	}
	return 0;
}

