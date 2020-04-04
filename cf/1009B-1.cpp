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

int main(){
	scanf("%s", s);
	int cnt = 0;
	for(int i = 0 ; s[i] ; ++ i)if(s[i] == '1')cnt++;
	bool f2 = 0;
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == '1')continue;
		if(s[i] == '2'){
			if(f2 == 0)while(cnt --)putchar('1');
			f2 = 1;
			putchar('2');
		}
		if(s[i] == '0')putchar('0');
	}
	if(f2 == 0)while(cnt --)putchar('1');
	putchar('\n');
	return 0;
}

