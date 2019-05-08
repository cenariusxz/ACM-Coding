#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int num[15] = {0,1,2,6,20,70,252,924,3432,12870,48620};

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",num[n]);
	return 0;
}
