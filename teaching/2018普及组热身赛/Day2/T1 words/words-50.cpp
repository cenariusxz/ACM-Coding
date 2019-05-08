//char brute force move
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +5;

char s[maxn],t[maxn];
int n;

void solve(){
    int len1 = strlen(s), len2 = strlen(t);
    if(len1<len2){
        int lim = len2 - len1;
        for(int k = 1 ; k <= lim ; ++ k){
            char tmp = 'a';
            for(int i = 0 ; i <= len1 ; ++ i)swap(s[i],tmp);
            len1++;
        }
        s[len2] = 0;
    }
    if(len2<len1){
        int lim = len1 - len2;
        for(int k = 1 ; k <= lim ; ++ k){
            char tmp = 'a';
            for(int i = 0 ; i <= len2 ; ++ i)swap(t[i],tmp);
            len2++;
        }
        t[len1] = 0;
    }
    for(int i = 0 ; s[i] ; ++ i)s[i] = abs(s[i]-t[i]) + 'a';
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T1-") + ID[T] + "-cbm.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    scanf("%s",s);
    for(int i = 1 ; i < n ; ++ i){
        scanf("%s",t);
        solve();
    }
    printf("%s\n",s);

    }

    return 0;

}
