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

int n,m;
char s[105];
string str[1005];
map<string,int>cnt;

int main(){
	scanf("%d",&m);
	for(int i = 1 ; i <= m ; ++ i){
		scanf("%s",s);
		str[i] = string(s);
	}
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int num;
		scanf("%d",&num);
		for(int j = 1 ; j <= num ; ++ j){
			scanf("%s",s);
			string tmp = string(s);
			cnt[tmp] ++;
		}
	}
	int pos = 1;
	for(int i = 2 ; i <= m ; ++ i){
		if(cnt[str[i]] < cnt[str[pos]])pos = i;
		else if(cnt[str[i]] == cnt[str[pos]] && str[i] < str[pos])pos = i;
	}
	printf("%s\n", str[pos].c_str());
	return 0;
}

