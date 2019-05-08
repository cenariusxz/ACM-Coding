#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int s[6];
	for(int n = 5; n <= 7; ++n){
		for(int k = 0; k <= n * (n - 1) / 2; ++k){
			for(int i = 1; i <= n; ++i) s[i] = i;
			int cnt = 0;
			do{
				int f = 0;
				for(int i = 1; i < n; ++i) if(s[i] > s[i + 1]) f += i;
				if(f == k){
					cnt++;
				}
			}while(next_permutation(s + 1,s + n + 1));
			printf("%d,%d : %d\n",n,k,cnt);
		}
	}
	return 0;
}
