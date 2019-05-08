#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-8;

int main(){
	int x = 0x100100;
	printf("%x\n",x);
	char *p = (char*)&x;
	*p = 'A';
	printf("%x\n",x);
	p = p + 2;
	*p = 50;
	printf("%x\n",x);
	 
	return 0;
}

