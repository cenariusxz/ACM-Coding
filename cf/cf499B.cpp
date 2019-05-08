#include <bits/stdc++.h>
using namespace std;
map<string,string> M;
char s[15],t[15];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%s%s",s,t);
        string ss(s),tt(t),tmp;
        if(ss.length() > tt.length())tmp = tt;
        else tmp = ss;
        M[ss] = M[tt] = tmp;
    }
    while(n--){
        scanf("%s",s);
        printf("%s ",M[s].c_str());
    }
    printf("\n");
    return 0;
}
