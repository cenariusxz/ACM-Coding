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

int l,r;
int num[10];

int solve(){
	for(int i = l; i <= r ; ++ i){
		memset(num, 0, sizeof(num));
		int x = i;
		while(x){
			num[x%10] ++;
			x /= 10;
		}
		bool flag = 1;
		for(int j = 0 ; j <= 9 ; ++ j){
			if(num[j] > 1)flag = 0;	
		}
		if(flag)return i;
	}
	return -1;
}

int main(){
	scanf("%d%d",&l,&r);
	printf("%d\n",solve());
	return 0;
}

