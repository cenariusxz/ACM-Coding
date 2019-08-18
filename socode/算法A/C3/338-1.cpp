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

int yinzi[maxn],geshu[maxn],cnt = 0;

int main(){
	int x;
	scanf("%d",&x);
	for(int i = 2 ; i*i <= x ; ++ i){
		if(x % i == 0){
			yinzi[++cnt] = i;
			while(x % i == 0){
				x /= i;
				geshu[cnt] ++;
			}
		}
	}
	if(x != 1){
		yinzi[++cnt] = x;
		geshu[cnt] = 1;	
	}
	for(int i = 1 ; i <= cnt ; ++ i){
		printf("%d %d\n",yinzi[i],geshu[i]);	
	}
	return 0;
}

