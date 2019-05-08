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
		ll p,q;
		scanf("%lld%lld",&p,&q);
		if(p<=q){
			printf("%lld\n",q-p);
			continue;
		}
		int step=0;
		ll sub=1;
		int ans=0x3f3f3f3f;
		while(1){
			ll prep=p;
			p-=sub;
			if(p<0)p=0;
			step++;
			if(p==q){
				if(step<ans)ans=step;
				break;
			}
			if(p<q){
				int tmp=step+q-p;
				if(tmp<ans)ans=tmp;
				p=prep;
				sub=1;
				continue;
			}
			sub*=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
