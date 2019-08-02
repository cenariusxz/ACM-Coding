#include <bits/stdc++.h>
using namespace std;

int cnt[10005],n;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		cnt[a] ++;	
	}
	for(int i = 0 ; i <= 10000 ; ++ i){
		if(cnt[i])printf("%d %d\n",i,cnt[i]);	
	}
	return 0;
}
