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

int cnt[maxn];
int n,k,a;

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d",&a);
		cnt[a]++;
	}
	int t = 0;
	for(int i = 0 ; i <= 30000 ; ++ i){
		if(cnt[i]){
			++ t;
			if(t == k)printf("%d\n",i);
		}	
	}
	if(t < k)printf("NO RESULT\n");
	return 0;
}

