#include <bits/stdc++.h>
using namespace std;

int main(){
	int l,r;
	while(scanf("%d%d",&l,&r)!=EOF){
		int ans = 0;
		for(int i = l ; i <= r ; ++ i){
			int tmp = i;
			while(tmp){
				if(tmp % 10 == 2)ans++;
				tmp /= 10;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
