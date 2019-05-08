#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[maxn][10];

int main(){
    int n;
    scanf("%d",&n);
    bool f = 0;
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%s",s[i]);
        if(!f && s[i][0] == 'O' && s[i][1] == 'O')s[i][0]=s[i][1]='+',f=1;
        if(!f && s[i][3] == 'O' && s[i][4] == 'O')s[i][3]=s[i][4]='+',f=1;
    }
    if(!f)printf("NO\n");
    else{
        printf("YES\n");
        for(int i = 1 ; i <= n ; ++ i){
            printf("%s\n",s[i]);
        }
    }
    return 0;
}
