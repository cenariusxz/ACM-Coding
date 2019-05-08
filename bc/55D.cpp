#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int l,r;
	while(scanf("%d%d",&l,&r)){
		int aans=0;
		for(int i=l;i<=r;++i){
			int p=i;
			int ans=0;
			while(p){
				ans^=(p%10);
				p/=10;
			}
			aans+=ans;
		}
		printf("%d\n",aans);
	}
	return 0;
}
