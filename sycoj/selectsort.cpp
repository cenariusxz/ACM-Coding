#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n;
int a[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i){
		int k = i;
		for(int j = i + 1 ; j <= n ; ++ j){
			if(a[j] < a[k])k = j;
		}
		swap(a[k], a[i]);
	}
	for(int i = 1 ; i <= n ; ++ i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}


