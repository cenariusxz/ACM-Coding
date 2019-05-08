#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

char s[maxn];

int main(){
    int n;
    scanf("%d%s",&n,s);
    int ans = 0;
    int a = 0 , b = 0;
    for(int i = 0 ; s[i] ; ++ i){
        if(s[i] == '0')++a;
        else ++b;
    }
    printf("%d\n",max(a,b) - min(a,b));
	return 0;
}
