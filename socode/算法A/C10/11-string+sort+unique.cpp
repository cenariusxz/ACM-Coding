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
char s[10];
string str[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s",s);
		str[i] = string(s);
	}
	sort(str+1, str+1+n);
	int cnt = unique(str+1,str+1+n) - (str+1);
	printf("%d\n",cnt);
	return 0;
}

