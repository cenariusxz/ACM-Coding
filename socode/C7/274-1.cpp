#include <bits/stdc++.h>
using namespace std;

int num[10005],n,x;

int main(){
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++ i)scanf("%d",&num[i]);
	scanf("%d",&x);
	int cnt = 0, ans1 = -1, ans2 = -1;
	for(int i = 0 ; i < n ; ++ i){
		if(num[i] == x){
			cnt ++;
			if(cnt == 1)ans1 = i;
			ans2 = i;
		}
	}
	if(cnt)printf("%d %d\n",ans1,ans2);
	else printf("-1\n");
	return 0;
}
