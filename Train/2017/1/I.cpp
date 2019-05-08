#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
typedef long long ll;



int main(){
	srand(time(NULL));

	ll s1=0,s2=0;
	ll pre=0;
	for(int i=1;i<=5;++i){
		ll tmp2=rand()%100+1;
		ll tmp1=rand()%(1000-tmp2)+1+tmp2;
		ll ss1=s1+tmp1;
		ll ss2=s2+tmp2;
		ll tmp=ss1*ss1-ss1*ss2-ss2*ss2;
		if(tmp>pre&&tmp2>tmp1)printf("WA\n");
		if(tmp>pre){
			s1=ss1;s2=ss2;pre=tmp;
		}
	}
	printf("fffff\n");
	for(int i=1;i<=10;++i){
		ll tmp1;
		ll tmp2=rand()%100;
		tmp1=tmp2-1;
		ll ss1=s1+tmp1;
		ll ss2=s2+tmp2;
		ll tmp=s1*s1-s1*s2-s2*s2;
		printf("%lld %lld  %lld %lld  %lld %lld  %d\n",s1,s2,s1+tmp1,s2+tmp2,tmp1,tmp2,tmp>pre);
		s1=ss1;
		s2=ss2;
		pre=tmp;
	}
	for(int i=1;i<=10;++i){
		ll tmp1;
		ll tmp2=rand()%100;
		scanf("%lld%lld",&tmp1,&tmp2);
		s1+=tmp1;
		s2+=tmp2;
		ll tmp=s1*s1-s1*s2-s2*s2;
		if(tmp>pre)printf("aaa\n");
		else printf("bbb\n");
		pre=tmp;
	}

	return 0;
}
