#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-8;

int h1,a1,h2,a2,b,d;

int check(int t1,int t2){
//	printf("%d %d\n",t1,t2);
	int ans=0;
	int hh1=h1,hh2=h2,aa1=a1,aa2=a2;
	int cnt0=0,cnt1=0;
	while(cnt1<t1){
		cnt0++;
		if(hh1<=aa2-d)hh1=h1;
		else{
			aa2-=d;
			cnt1++;
		}
		hh1-=aa2;
		if(cnt0>5&&cnt1<=1)return INF;
	}
//	if(t1==4&&t2==0)printf("aaa %d %d %d %d %d\n",cnt0,hh1,aa1,hh2,aa2);
	cnt1=0;
	int cc=0;
	while(cnt1<t2){
		cnt0++;
		cc++;
		if(hh1<=aa2)hh1=h1;
		else{
			aa1+=b;
			cnt1++;
		}
		hh1-=aa2;
		if(cc>5&&cnt1<=1)return INF;
	}
//	if(t1==4&&t2==0)printf("aaa %d %d %d %d %d\n",cnt0,hh1,aa1,hh2,aa2);
	cnt1=0;
	cc=0;
	while(hh2>0){
		cnt0++;
		cc++;
		if(hh2<=aa1){
			hh2-=aa1;
			continue;
		}
		if(hh1<=aa2)hh1=h1;
		else{
			hh2-=aa1;
			cnt1++;
		}
		hh1-=aa2;
		if(cc>5&&cnt1<=1)return INF;
	}
//	if(t1==4&&t2==0)printf("aaa %d %d %d %d %d\n",cnt0,hh1,aa1,hh2,aa2);
	return cnt0;

}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d%d%d%d%d%d",&h1,&a1,&h2,&a2,&b,&d);
		int lim1,lim2;
		if(d==0)lim1=0;
		else{
			lim1=a2/d;
			if(lim1*d<a2)lim1++;
		}
		if(b==0)lim2=0;
		else{
			lim2=(h2-a1)/b;
			if(b*lim2<(h2-a1))lim2++;
		}
		int ans=INF;
		for(int i=0;i<=lim1;++i){
			for(int j=0;j<=lim2;++j){
				ans=min(ans,check(i,j));
			}
		}
		printf("Case #%d: ",q);
		if(ans==INF)printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}
