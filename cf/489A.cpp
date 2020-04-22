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

int n, a[maxn], b[maxn];

void solve(){
	for(int i = 0 ; i < n ; ++ i)scanf("%d", &a[i]);
	for(int i = 0 ; i < n ; ++ i)b[i] = a[i];
	sort(b, b + n);
	printf("%d\n", n);
	for(int i = 0 ; i < n ; ++ i){
		if(a[i] == b[i])printf("%d %d\n", i, i);
		else{
			for(int j = i + 1 ; j < n ; ++ j){
				if(a[j] == b[i]){
					printf("%d %d\n", i ,j);
					swap(a[i], a[j]);
					break; 
				}
			}
		}
	}
}

int main(){
	scanf("%d", &n);
	solve();
	return 0;
}


