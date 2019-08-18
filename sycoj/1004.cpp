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
stack<int>s;
int a[maxn];

int main(){
	scanf("%d",&n);
	int now = 0;
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i){
		if(a[i] > now){
			for(int j = now + 1 ; j <= a[i] ; ++ j)s.push(j);
			now = a[i];
		}
		if(s.top() != a[i]){
			printf("NO\n");
			return 0;	
		}
		s.pop();
	}
	printf("YES\n");
	return 0;
}

