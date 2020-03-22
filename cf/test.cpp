#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 5e5 + 5;
const int maxm = 1e6 + 5;

int n;
char s[maxn];
int cnt1[maxn],cnt2[maxn];


int main(){
	scanf("%d",&n);
	int cnt0 = 0;
	while(n--){
		scanf("%s",s+1);
		int sum = 0, pmin = 0;
		for(int i = 1 ; s[i] ; ++ i){
			if(s[i] == '(')sum++;
			else sum--;
			pmin = min(pmin, sum);
		}
		if(sum == 0 && pmin == 0)cnt0++;
		if(sum > 0 && pmin == 0)cnt1[sum]++;
		if(sum < 0 && pmin == sum)cnt2[-sum]++;
	}
	int ans = cnt0 / 2;
	for(int i = 1 ; i <= 500000 ; ++ i)ans += min(cnt1[i], cnt2[i]);
	printf("%d\n",ans);
	return 0;
}

