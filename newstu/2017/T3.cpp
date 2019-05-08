#include <stdio.h>
using namespace std;
typedef long long ll;

const int maxn = 1e4 + 5;

int num[maxn],n,a,k,sum;

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d",&a);
		num[a]++;
	}
	for(int i = 1 ; i <= 10000 ; ++ i){
		sum += num[i];
		if(sum >= k){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}
