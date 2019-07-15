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

char s[105];

int main(){
	gets(s);
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = s[i] - 'a' + 'A';
		}
	}
	printf("%s",s);
	return 0;
}

