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
int a[maxn]; 

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	int sum = 0;
	for(int i = 1 ; i <= n ; ++ i)sum += a[i];
	int ave = sum / n;
	for(int i = 1 ; i <= n ; ++ i)a[i] -= ave;
	int ans = 0;
	for(int i = 1 ; i < n ; ++ i){
		if(a[i]){
			a[i+1] += a[i];
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}


