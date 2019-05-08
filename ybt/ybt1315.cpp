#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int n,int k){
	if(n < k)return 0;
	if(n == k)return 1;
	if(k == 1)return 1;
	return solve(n-1,k-1) + k*solve(n-1,k);
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%lld\n",solve(n,k));
	return 0;
}
