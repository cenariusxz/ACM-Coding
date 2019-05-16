#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn],b[maxn],f[maxn];
int n;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i)b[i] = a[i];
	sort(b+1, b+n+1);
	for(int i = 1 ; i <= n ; ++ i)f[i] = a[i] == b[i];
	int left = n+1, right = -1;
	for(int i = 1 ; i <= n ; ++ i){
		if(!f[i])left = min(left, i), right = i;
	}
	if(left == n+1)printf("yes\n1 1\n");
	else{
		for(int i = left, j = right; i < j ; ++i, --j)swap(a[i],a[j]);
		for(int i = 1 ; i <= n ; ++ i){
			if(a[i] != b[i]){
				printf("no\n");
				return 0;
			}
		}
		printf("yes\n%d %d\n",left,right);
	}
	return 0;
}
