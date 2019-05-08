#include <stdio.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e5 + 5;

int num[maxn],left[maxn],right[maxn];
int n;

bool solve(){
	if(num[n])return 0;
	if(n == 1)return 1;
	if(num[n-1])return 1;
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i)if(!num[i])cnt++;
	if(cnt <= 2)return 0;
	cnt = 0;
	for(int i = n ; i >= 1 ; -- i){
		if(!num[i]){
			cnt++;
			if(cnt == 2)right[i] = 2;
			if(cnt == 3){
				left[i] = 1;
				left[i+1] = 1;
				break;
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&num[i]);
	if(!solve())printf("NO\n");
	else{
		printf("YES\n");
		for(int i = 1 ; i <= n ; ++ i){
			if(i != 1)printf("->");
			if(left[i]){
				for(int j = 1 ; j <= left[i] ; ++ j)printf("(");
			}
			printf("%d",num[i]);
			if(right[i]){
				for(int j = 1 ; j <= right[i] ; ++ j)printf(")");
			}
		}
		printf("\n");
	}
	return 0;
}
