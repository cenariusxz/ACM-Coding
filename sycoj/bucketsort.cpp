#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 1005;

int n;
int b[maxm];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		b[a] ++;
	}
	for(int i = 1 ; i <= 1000 ; ++ i){
		if(b[i]){
			printf("%d ",i);
			b[i]--;
		}
	}
	printf("\n");
	return 0;
}


