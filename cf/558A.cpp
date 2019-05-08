#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct tr1{
	int x,a;
	bool operator < (const tr1 a)const{
		return x<a.x;
	}
}t1[105];

struct tr2{
	int x,a;
	bool operator < (const tr2 a)const{
		return x>a.x;
	}
}t2[105];

int main(){
	int n;
	int i,j;
	int cnt1=0,cnt2=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int a,x;
		scanf("%d%d",&x,&a);
		if(x>0){
			cnt1++;
			t1[cnt1].x=x;
			t1[cnt1].a=a;
		}
		if(x<0){
			cnt2++;
			t2[cnt2].x=x;
			t2[cnt2].a=a;
		}
	}
	sort(t1+1,t1+cnt1+1);
	sort(t2+1,t2+cnt2+1);
	int ans1=0,ans2=0;
	for(i=1;i<=min(cnt1,cnt2);i++){
		ans1+=t1[i].a+t2[i].a;
	}
	if(cnt1<cnt2){
		ans1+=t2[cnt1+1].a;
	}
	if(cnt1>cnt2){
		ans1+=t1[cnt2+1].a;
	}
	printf("%d\n",ans1);
	return 0;
}
