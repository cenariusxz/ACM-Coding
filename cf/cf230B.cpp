#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

bool notp[maxn];
map<ll,int>M;

void init(){
    int n = 1000000;
    for(int i = 2 ; i <= n ; ++ i){
        if(!notp[i]){
            M[i*(ll)i] = 1;
            for(int j = i + i ; j <= n ; j += i){
                notp[j] = 1;
            }
        }
    }
}

int main(){
    init();
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i){
        ll a;
        scanf("%lld",&a);
        if(M[a])printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
