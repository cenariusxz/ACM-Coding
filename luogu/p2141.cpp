#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

int a[maxn],n;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	int ans = 0;
	for(int i = 1 ; i <= n ; ++ i){
		bool f = 0;
		for(int j = 1 ; j <= n ; ++ j){
			if(j==i)continue;
			for(int k = j + 1 ; k <= n ; ++ k){
				if(k==j)continue;
				if(a[j] + a[k] == a[i])f = 1;
			}
		}
		ans+=f;
	}
	printf("%d\n",ans);
	return 0;
}
