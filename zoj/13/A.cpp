#include <stdio.h>
#include <algorithm>
using namespace std;

int a,b,c,d;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		swap(a,c);
		int t = b + d;
		b = t;
		d = t;
		printf("%d %d\n",a,b);
		printf("%d %d\n",c,d);
	}
	return 0;
}
