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
int a[105],vis[105],suf[105];

bool check(int have, int pre, int need, int num){
	if(have == need)return check(0, 0, need, num - 1);
	if(num == 0)return 1;
	if(pre == n || need - have < a[n] || need - have > suf[pre+1])return 0;
	for(int i = pre + 1 ; i <= n ; ++ i){
		if(vis[i] || have + a[i] > need)continue;
		vis[i] = 1;
		if(check(have + a[i], i, need, num))return 1;
		vis[i] = 0;
		if(have + a[i] == need || have == 0)return 0;
		while(i < n && a[i+1] == a[i])++i;	
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	int sum = 0;
	for(int i = 1 ; i <= n ; ++ i)sum += a[i];
	sort(a + 1 , a + 1 + n , greater<int>());
	for(int i = n ; i >= 1 ; -- i)suf[i] = suf[i+1] + a[i];
	if(a[1] > sum/2){
		printf("%d\n",sum);
		return 0;	
	}
	for(int i = a[1] ; i <= sum/2 ; ++ i){
		if(sum % i)continue;
		if(check(0, 0, i, sum/i)){
			printf("%d\n",i);
			return 0;	
		}
	}
	printf("%d\n",sum);
	return 0;
}


