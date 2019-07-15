#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n;
int a[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = n ; i > 1 ; -- i){
		for(int j = 1 ; j < i ; ++ j){
			if(a[j] > a[j+1])swap(a[j], a[j+1]);
		}
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}


