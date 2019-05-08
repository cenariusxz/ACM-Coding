#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[maxn];
char t[maxn];

int main(){
    scanf("%s%s",s,t);
    for(int i = 0 ; s[i] ; ++ i){
        if(s[i] == t[i])printf("0");
        else printf("1");
    }
    printf("\n");
    return 0;
}
