#include <bits/stdc++.h>
using namespace std;

int main(){
	printf("1000\n");
	for(int T = 1 ; T <= 1000 ; ++ T){
		for(int i = 1 ; i <= 3 ; ++ i){
			for(int j = 1 ; j <= 3 ; ++ j){
				printf("%d",rand() % 9 + 1);
			}
			if(i == 3)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
