#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct book{
	int w,t;
	bool operator < (const book a)const{
		if(t==a.t)return w<a.w;
		return t>a.t;
	}
}b[105];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,tt=0,ww=0,ans=0;
		for(i=1;i<=n;i++){
			scanf("%d%d",&b[i].t,&b[i].w);
			tt+=b[i].t;
		}
		sort(b+1,b+n+1);
//		printf("%d\n",tt);
//		for(i=1;i<=n;i++)printf("%d %d\n",b[i].w,b[i].t);
		for(i=1;i<=n;i++){
			tt-=b[i].t;
			int tmp=ans+b[i].w;
			if(tmp<=tt)ans=tmp;
			else{
				tt+=b[i].t;
				break;
			}
		}
		printf("%d\n",tt);
	}
	return 0;
}
