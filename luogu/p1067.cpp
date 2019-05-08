#include <bits/stdc++.h>
using namespace std;

int a[105],n;

int main(){
	while(scanf("%d",&n)!=EOF){
		bool flag = 0;
		for(int i = n ; i >= 0 ; -- i){
			scanf("%d",&a[i]);
			if(a[i])flag = 1;
			if(!flag && a[i] == 0)--n;
		}
		if(n <= 0){
			printf("%d\n",a[0]);
			continue;
		}
		for(int i = n ; i >= 1 ; -- i){
			if(!a[i])continue;
			if(a[i] < 0){
				printf("-");
				a[i] = -a[i];
			}
			else if(i != n){
				printf("+");
			}
			if(a[i] != 1)printf("%d",a[i]);
			printf("x");
			if(i > 1)printf("^%d",i);
		}
		if(a[0] < 0)printf("%d",a[0]);
		else if(a[0] > 0)printf("+%d",a[0]);
		printf("\n");
	}
	return 0;
}
