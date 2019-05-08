//char  reverse
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +5;

char s[maxn],t[maxn];
int n;

void re(char s[]){
    int len = strlen(s);
    for(int i = 0, j = len - 1; i < j ; ++ i, --j)swap(s[i],s[j]);
}

void solve(){
    int len1 = strlen(s), len2 = strlen(t);
    while(len1 < len2)s[len1++] = 'a';
    s[len1] = 0;
    while(len2 < len1)t[len2++] = 'a';
    t[len2] = 0;
    for(int i = 0 ; s[i] ; ++ i)s[i] = abs(s[i]-t[i]) + 'a';
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
//    for(int T = 1 ; T <= 10 ; ++ T){
 //   freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
 //   freopen( (string("T1-") + ID[T] + ".out").c_str() ,"w",stdout);

    scanf("%d",&n);
    scanf("%s",s);
    re(s);
    for(int i = 1 ; i < n ; ++ i){
        scanf("%s",t);
        re(t);
        solve();
    }
    re(s);
    printf("%s\n",s);

 //   }

    return 0;
}
