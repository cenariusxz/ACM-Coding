#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int a[maxm];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)a[i] = i;
	int pos = 1;
	for(int i = 1 ; i < n ; ++ i){
		while(pos != 1){
			swap(a[pos],a[pos/2]);
			pos /= 2;
		}
		swap(a[pos], a[i+1]);
		pos = i+1;
	}
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d",a[i]);
		if(i == n)printf("\n");
		else printf(" ");	
	}
	return 0;
}

