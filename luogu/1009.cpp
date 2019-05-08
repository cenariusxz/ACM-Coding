#include <bits/stdc++.h>
using namespace std;

struct Num{
    int d[505];
    int len;
    Num(){
        memset(d,0,sizeof(d));
        len = 0;
    }
};

Num addNum(Num a, Num b){
    Num ans;
    int len = max(a.len, b.len);
    for(int i = 0 ; i < len ; ++ i){
        ans.d[i] += a.d[i] + b.d[i];
        ans.d[i+1] += ans.d[i] / 10;
        ans.d[i] %= 10;
    }
    ans.len = len;
    if(ans.d[len])ans.len++;
    return ans;
}

Num mulNum(Num a,int x){
    Num ans;
    int len = a.len;
    for(int i = 0 ; i < len ; ++ i)ans.d[i] = a.d[i]*x;
    for(int i = 0 ; i < len ; ++ i){
        ans.d[i+1] += ans.d[i] / 10;
        ans.d[i] %= 10;
    }
    if(ans.d[len])len++;
    while(ans.d[len-1] >= 10){
        ans.d[len] = ans.d[len-1] / 10;
        ans.d[len-1] %= 10;
        len++;
    }
    ans.len = len;
    return ans;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        Num ans;
        ans.len = 1;
        ans.d[0] = 0;

        Num tmp;
        tmp.len = 1;
        tmp.d[0] = 1;

        for(int i = 1 ; i <= n ; ++ i){
            tmp = mulNum(tmp,i);
            ans = addNum(ans,tmp);
        }

        for(int i = ans.len-1 ; i >= 0 ; -- i)printf("%d",ans.d[i]);
        printf("\n");
    }
    return 0;
}
