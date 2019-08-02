#include <bits/stdc++.h>
using namespace std;

int num[10005],n,x;

int main(){
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++ i)scanf("%d",&num[i]);
	scanf("%d",&x);
	int cnt = 0, ans1 = 100000, ans2 = -1;
	for(int i = 0 ; i < n ; ++ i){
		if(num[i] == x){
			if(i < ans1)ans1 = i;
			if(i > ans2)ans2 = i;
		}
	}
	if(ans1 != 100000)printf("%d %d\n",ans1,ans2);
	else printf("-1\n");
	return 0;
}
