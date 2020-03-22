#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

char s[maxn];
int n,k;
int vis[maxn];
stack<int>stk;

int main(){
	scanf("%d%d%s",&n,&k,s+1);
	for(int i = 1 ; s[i] && k ; ++ i){
		if(s[i] == '(')stk.push(i);
		else{
			int idx = stk.top(); stk.pop();
			vis[i] = 1; vis[idx] = 1;
			k -= 2;
		}
	}
	for(int i = 1 ; s[i] ; ++ i){
		if(vis[i])putchar(s[i]);
	}
	printf("\n");
	return 0;
}

