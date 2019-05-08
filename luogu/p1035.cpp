#include <bits/stdc++.h>
using namespace std;

int main(){
	int k;
	while(scanf("%d",&k)!=EOF){
		double sum = 0;
		for(int i = 1 ; i <= 100000000 ; ++ i){
			sum += 1.0 / i;
			if(sum > k){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
