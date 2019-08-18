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

int main(){
	int x;
	scanf("%d",&x);
	for(int i = 2 ; i*i <= x ; ++ i){
		if(x % i == 0){
			int cnt = 0;
			while(x % i == 0){
				x /= i;
				cnt++;
			}
			printf("%d %d\n",i,cnt);
		}
	}
	if(x != 1)printf("%d 1\n",x);
	return 0;
}

