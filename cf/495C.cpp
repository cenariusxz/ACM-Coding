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

char s[maxn];
int num[maxn];

bool solve(){
	int last = 0, sum = 0;
	for(int i = 1 ; s[i] ; ++ i){
		num[i] = (s[i] == '(') ? 1 : -1;
		sum += num[i];
		if(s[i] == '#')last = i;
	}
	if(sum >= 0)num[last] -= sum;
	
	sum = 0;
	for(int i = 1 ; s[i] ; ++ i){
		sum += num[i];
		if(sum < 0)return 0;
	}
	return 1;
}

int main(){
	scanf("%s", s+1);
	if(solve()){
		for(int i = 1 ; s[i] ; ++ i){
			if(s[i] == '#')printf("%d\n", -num[i]);
		}
	}
	else printf("-1\n");
	return 0;
}


