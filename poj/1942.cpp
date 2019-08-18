#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

ll getC(ll n,ll m){
	ll ans = 1;
	ll j = 2;
	for(ll i = n ; i >= n-m+1 ; -- i){
		ans *= i;
		while(ans % j == 0 && j <= m){
			ans /= j;
			j ++;	
		}
	}
	return ans;
}

int main(){
	ll n,m;
	while(cin>>n>>m){
		if(!n && !m)break;
		if(n>m)swap(n,m);
		cout<<getC(n+m,n)<<endl;	
	}
	return 0;
}

