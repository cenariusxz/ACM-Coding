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

char s[505];

int main(){
	gets(s);
	int n = strlen(s);
	for(int i = n-1 ; i >= 0 ; -- i){
		printf("%c",s[i]);	
	}
	printf("\n");
	return 0;
}

