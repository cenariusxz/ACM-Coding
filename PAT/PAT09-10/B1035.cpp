#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 105;

int a[maxn],b[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++i)scanf("%d",&b[i]);
	bool flag1 = 0,flag2 = 0;
	int pos = 0;
	for(int i = n ; i >= 1 ; --i){
		if(flag1 == 0){
			if(a[i] != b[i])flag1 = 1, pos = i + 1;
		}
		else{
			if(b[i] > b[i+1])flag2 = 1;
		}
	}
	if(flag2 == 0){
		printf("Insertion Sort\n");
		for(int i = 2 ; i <= n ; ++i){
			if(b[i] < b[i-1]){
				pos = i;
				break;
			}
		}
		sort(a + 1, a + 1 + pos);
	}
	else{
		printf("Merge Sort\n");
		for(int i = 2 ; i <= n ; i <<= 1){
			flag1 = 0;
			for(int j = 1 ; j <= n ; j += i){
				for(int k = j + 1 ; k <= min(j+i-1, n) ; ++k){
					if(b[k] < b[k-1])flag1 = 1;
				}
			}
			if(flag1){
				for(int j = 1 ; j <= n ; j += i){
					int len = min(i, n-j+1);
					sort(a + j, a + j + len);
				}
				break;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d",a[i]);
		if(i == n)printf("\n");
		else printf(" ");
	}
	return 0;
}
