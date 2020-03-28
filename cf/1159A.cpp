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

int n;
char s[maxn];

int main(){
	scanf("%d%s", &n, s);
	int num = 0;
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == '+')num ++;
		else num --;
		if(num < 0)num = 0;
	}
	printf("%d\n", num);
	return 0;
}

