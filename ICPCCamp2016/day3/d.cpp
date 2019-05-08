#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const ll mod = 1e9 + 7;

int n,d;
int w[2010];

map<int,int> mp1,mp2;
map<int,int>::iterator it;

ll Q_pow(ll x,ll y){
	ll res = 1;
	while(y){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&d);
	for(int i = 1; i <= n; ++i){
		scanf("%d",w + i);
	}
	if(n == 1){
		printf("0 2\n");
		return 0;
	}
	sort(w + 1,w + n + 1);
	ll ans = 0;
	for(int i = 1; i < n; ++i){
		// [1,i] , [i+1,n]
		int p1 = 1,p2 = n;
		ll res = 0;
		while(p1 <= i && p2 > i){
			if(w[p2] + w[p1] >= d){
				// [p1,i]
				res += i - p1 + 1;
				p2--;
			}
			else{
				p1++;
			}
		}
		if(res > ans) ans = res;
	}
	ll num = 1;
	for(int i = 1; i < n; ++i){
		int p1 = 1,p2 = n;
		ll res = 0;
		while(p1 <= i && p2 > i){
			if(w[p2] + w[p1] >= d){
				res += i - p1 + 1;
				p2--;
			}
			else{
				p1++;
			}
		}
		if(res == ans){
			// max
			int k;
			for(k = 1; k <= i; ++k){
				if(w[n] + w[k] >= d){
					k--;
					break;
				}
			}
			// [1,k] none
			num = num * Q_pow(2,k) % mod;
			for(int j = 1; j <= i; ++j) mp1[w[j]]++;
			for(int j = i + 1; j <= n; ++j) mp2[w[j]]++;
			
		}
	}

	return 0;
}
