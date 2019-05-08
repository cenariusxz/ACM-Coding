#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n == 0)printf("0\n");
		else{
			if(n < 0){
				printf("-");
				n = -n;
			}
			bool f = 0;
			while(n){
				int tmp = n % 10;
				n /= 10;
				if(!f && tmp == 0)continue;
				if(tmp)f=1;
				printf("%d",tmp);
			}
			printf("\n");
		}
	}
	return 0;
}
