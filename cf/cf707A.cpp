#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

char s[10];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int ans = 0;
    n*=m;
    while(n--){
        scanf("%s",s);
        if(s[0]=='C'||s[0] == 'M' || s[0] == 'Y')ans++;
    }
    if(ans)printf("#Color\n");
    else printf("#Black&White\n");
	return 0;
}
