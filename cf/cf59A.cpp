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

int main(){
    scanf("%s",s);
    int lc = 0, uc =0 ;
    for(int i = 0 ; s[i] ; ++ i){
        if(s[i] >='a' && s[i] <= 'z')lc++;
        else uc++;
    }
    if(uc >  lc){
        for(int i = 0 ; s[i] ; ++i){
            if(s[i] >='a' && s[i] <= 'z')printf("%c",s[i]-'a'+'A');
            else printf("%c",s[i]);
        }
    }
    else{
        for(int i = 0 ; s[i] ; ++i){
            if(s[i] >='A' && s[i] <= 'Z')printf("%c",s[i]-'A'+'a');
            else printf("%c",s[i]);
        }
    }
    printf("\n");
    return 0;
}
