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

char s[maxn], t[maxn];

int main(){
	scanf("%s", s+1);
	int n = strlen(s+1);
	t[n+1] = 0;
	int n0 = 0, n1 = 0, n2 = 0, cnt = n;
	for(int i = n ; i >= 1 ; -- i){
		if(s[i] == '0'){
			for(int j = 1 ; j <= n2 ; ++ j)t[cnt--] = '2';
			n2 = 0;
			n0++;
		}
		if(s[i] == '1')n1++;
		if(s[i] == '2'){
			for(int j = 1 ; j <= n0 ; ++ j)t[cnt--] = '0';
			n0 = 0;
			n2++;
		}
	}
	while(n2--)t[cnt--] = '2';
	while(n1--)t[cnt--] = '1';
	while(n0--)t[cnt--] = '0';
	printf("%s\n",t+1);
	return 0;
}

