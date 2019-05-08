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
    int d1,d2,d3;
    scanf("%d%d%d",&d1,&d2,&d3);
    if(d1 > d2)swap(d1,d2);
    if(d1 > d3)swap(d1,d3);
    if(d2 > d3)swap(d2,d3);
    printf("%d\n",min(2*(d1+d2),d1+d2+d3));
	return 0;
}
