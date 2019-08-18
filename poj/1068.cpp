#include <stdio.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int n;
int p[maxn],w[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&p[i]);
		for(int i = 1 ; i <= n ; ++ i){
			for(int j = i-1 ; j >= 0 ; -- j){
				if(i - j <= p[i] - p[j]){
					w[i] = i-j;
					break;
				}
			}
		}
		for(int i = 1 ; i <= n ; ++ i){
			printf("%d",w[i]);
			if(i == n)printf("\n");
			else printf(" ");	
		}
	}
	return 0;
}

