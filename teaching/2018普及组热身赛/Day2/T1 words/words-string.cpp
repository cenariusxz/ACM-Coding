//string move
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +5;

char ss[maxn];
string s,t;
int n;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T1-") + ID[T] + "-sbm.out").c_str() ,"w",stdout);

    scanf("%d",&n);
    scanf("%s",ss);
    s = string(ss);
    for(int i = 1 ; i < n ; ++ i){
        scanf("%s",ss);
        t = string(ss);
        int len1 = s.length(), len2 = t.length();
        while(len1 < len2)s = "a" + s , len1 ++;
        while(len2 < len1)t = "a" + t , len2 ++;
        for(int i = 0 ; i < len1 ; ++ i)s[i] = abs(s[i]-t[i]) + 'a';
    }
    printf("%s\n",s.c_str());

    }

    return 0;
}
