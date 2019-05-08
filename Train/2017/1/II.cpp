#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		ll s1=0,s2=0;
		for(int i=1;i<=n;++i){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			if(t1>=t2){
				s1+=t1;
				s2+=t2;
			}
		}
		printf("%lld\n",s1*s1-s2*s1-s2*s2);
	}
	return 0;
}
