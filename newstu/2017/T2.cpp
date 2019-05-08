#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

int num[15];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int cnt = 0, ans = 0, a ,n1 ,n2;
		for(int i = 1 ; i <= 3 ; ++ i){
			scanf("%d",&a);
			for(int i = 1 ; i <= 3 ; ++ i){
				num[++cnt] = a % 10;
				a /= 10;
			}
		}
		sort(num + 1 , num + 10);
		for( int i = 1 ; i <= 9 ; ++ i){
			for( int j = i + 1 ; j <= 9 ; ++ j){
				for(int k = j + 1 ; k <= 9 ; ++ k){
					int tmp = num[k] * 100 + num[j] * 10 + num[i];
					cnt = 0 , n1 = 0 , n2 = 0;
					for(int p = 9 ; p >= 1 ; -- p){
						if(p == i || p == j || p == k)continue;
						cnt++;
						if(cnt <= 3)n1 = n1 * 10 + num[p];
						else n2 = n2 * 10 + num[p];
					}
					if(n1 >= tmp && n2 <= tmp && tmp > ans)ans = tmp;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
