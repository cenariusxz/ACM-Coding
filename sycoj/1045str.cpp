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

string s[maxn],t;
char ss[maxn];
int n;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s",ss);
		s[i] = string(ss);
	}
	scanf("%s",ss);
	t = string(ss);
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(s[i].find(t) == 0)s[++cnt] = s[i];	
	}
	sort(s + 1 , s + 1 + cnt);
	for(int i = 1 ; i <= cnt ; ++ i)printf("%s\n",s[i].c_str());
	return 0;
}


