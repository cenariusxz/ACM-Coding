#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[100005];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		printf("Case #%d: ",q);
		bool f=0;
		for(int i=2;i<=n;++i)if(a[i]!=a[i-1]+1){
			printf("%d\n",i);
			f=1;
		}
		if(!f)printf("1\n");
	}
	return 0;
}
