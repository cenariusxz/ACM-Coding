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

int n;
int num[105];

int main(){
	scanf("%d",&n);
	int cnt = 0;
	while(n){
		num[++cnt] = n&1;
		n >>= 1;	
	}
	cnt++;
	int st = 0;
	for(int i = 1 ; i <= cnt ; ++ i){
		if(num[i] == 1 && !st)st = i;
		if(num[i] == 0 && st){
			num[i] = 1;
			int t = i - st - 1;
			for(int j = 1 ; j < i ; ++ j){
				num[j] = j <= t;
			}
			break;
		}
	}
	n = 0;
	for(int i = cnt ; i >= 1 ; -- i)n = n*2 + num[i];
	printf("%d\n",n);
	return 0;
}


