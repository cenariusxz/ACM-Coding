#include <bits/stdc++.h>
using namespace std;

int num[105];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
		sort(num + 1 , num + n + 1);
		int t = unique(num + 1 , num + 1 + n) - (num + 1);
		printf("%d\n",t);
		for(int i = 1 ; i <= t ; ++ i){
			printf("%d",num[i]);
			if(i == t)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
