#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[3][10] = {"I love ","I hate "};
char t[3][10] = {"it\n","that "};

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i){
        printf("%s",s[i%2]);
        if(i == n)printf("%s",t[0]);
        else printf("%s",t[1]);
    }
    return 0;
}
