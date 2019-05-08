#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[25];

bool check(int sum){
	for(int i = 2 ; i * i <= sum ; ++ i){
		if(sum % i == 0)return 0;
	}
	return 1;
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		for(int i = 0 ; i < n ; ++ i)scanf("%d",&a[i]);
		int ans = 0;
		for(int i = 1 ; i < 1<<n ; ++ i){
			int bits = 0, sum = 0;
			for(int j = 0 ; j < n ; ++ j){
				if(i & (1 << j))bits++,sum+=a[j];
			}
			if(bits != k)continue;
			if(check(sum))ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
