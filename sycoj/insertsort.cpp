#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n;
int a[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 2 ; i <= n ; ++ i){
		int j;
		for(j = 1 ; j < i ; ++ j){
			if(a[j] > a[i])break;	
		}
		int tmp = a[i];
		for(int k = i-1 ; k >= j ; -- k)a[k+1] = a[k];
		a[j] = tmp;
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}


