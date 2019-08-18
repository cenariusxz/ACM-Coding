#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define esp 1e-6
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n,m;
int a[maxn];
double b[maxn],sum[maxn],Min[maxn];

bool check(double mid){
	for(int i = 1 ; i <= n ; ++ i)b[i] = a[i] - mid;
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + b[i];
	double res = -INF;
	for(int i = 1 ; i <= n ; ++ i){
		Min[i] = min(Min[i-1], sum[i]);
		if(i >= m)res = max(res, sum[i] - Min[i-m]);
	}
	return res >= 0;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i] < 0)while(1){}
	}
    double l=0,r=2000,mid,ans;
    for(int i = 1 ; i <= 40 ; ++ i){
        mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else r=mid;
    }
    printf("%d\n",int(r*1000));
}
