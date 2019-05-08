#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[maxn],t[maxn];

int main(){
    scanf("%s%s",s,t);
    int ls = strlen(s),lt = strlen(t);
    if(ls!=lt){
        printf("NO\n");
        return 0;
    }
    int p1 = 0, p2 = lt-1;
    for(int i = 0; s[i]; ++i){
        if(s[p1] != t[p2]){
            printf("NO\n");
            return 0;
        }
        p1++;p2--;
    }
    printf("YES\n");
	return 0;
}
