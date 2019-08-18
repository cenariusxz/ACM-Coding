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

set<string>S;
char q[15],s[205];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s%s",q,s);
		if(q[0] == 'a')S.insert(string(s));
		else{
			if(S.find(string(s)) != S.end())printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}

