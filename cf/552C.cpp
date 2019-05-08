#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

int w;
ll m;

int main(){
	scanf("%d%lld",&w,&m);
/*	if(w==2||w==3){
		printf("YES\n");
		return 0;
	}*/
	int cnt=50;
	ll pre=0;
	while(m&&cnt>=1){
		int i;
	/*	if(m==1){
			printf("YES\n");
			return 0;
		}*/
		ll tmp=1;
		for(i=1;i<=cnt;i++){
			tmp=tmp*w;
			if(tmp>abs(m))break;
		}
		ll tmp2=tmp/w;
		if(abs(tmp-m)>abs(tmp2-m)){
			if(pre==tmp2){
				printf("NO\n");
				return 0;
			}
			cnt=i-1;
			m=m-tmp2;
			pre=tmp2;
			printf("- %lld\n",tmp2);
		}
		else{
			if(pre==tmp){
				printf("NO\n");
				return 0;
			}
			cnt=i;
			m=tmp-m;
			pre=tmp;
			printf("+ %lld\n",tmp);
		}
	}
	if(m==0)printf("YES\n");
	else printf("NO\n");
	return 0;	
}
