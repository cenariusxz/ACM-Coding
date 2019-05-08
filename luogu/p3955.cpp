#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;

int a[maxn];
int num[10];

int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	num[0] = 1;
	for(int i = 1 ; i <= 8 ; ++ i)num[i] = num[i-1] * 10;
	while(q--){
		int len,ask;
		scanf("%d%d",&len,&ask);
		bool f = 0;
		for(int i = 1 ; i <= n ; ++ i){
			if(a[i] < ask)continue;
			if(a[i] % num[len] == ask){
				printf("%d\n",a[i]);
				f=1;
				break;
			}
		}
		if(!f)printf("-1\n");
	}
	return 0;
}
