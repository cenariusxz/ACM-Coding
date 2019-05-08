#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

int main(){
    int x1,x2,y1,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1 == x2){
        printf("%d %d %d %d\n",x1+y1-y2,y1,x1+y1-y2,y2);
    }
    else if(y1 == y2){
        printf("%d %d %d %d\n",x1,y1+x1-x2,x2,y1+x1-x2);
    }
    else{
        if(abs(x1-x2) != abs(y1-y2))printf("-1\n");
        else printf("%d %d %d %d\n",x1,y2,x2,y1);
    }
    return 0;
}
