//char move
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +5;

char s[maxn],t[maxn];
int n;

void solve(){
    int len1 = strlen(s), len2 = strlen(t);
    if(len1<len2){
        for(int i = len1, j = len2 ; j >= 0 ; -- i, -- j){
            if(i >= 0)s[j] = s[i];
            else s[j] = 'a';
        }
        s[len2] = 0;
    }
    if(len2<len1){
        for(int i = len2, j = len1 ; j >= 0 ; -- i, -- j){
            if(i >= 0)t[j] = t[i];
            else t[j] = 'a';
        }
        t[len1] = 0;
    }
    for(int i = 0 ; s[i] ; ++ i)s[i] = abs(s[i]-t[i]) + 'a';
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T1-") + ID[T] + "-cm.out").c_str() ,"w",stdout);

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
