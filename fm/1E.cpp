#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct ant{
	int num,dis;
	bool d;
	bool operator<(ant a)const{
		return dis<a.dis;
	}
}a[10005],b[10005];

struct anss{
	int f,dis;	//f: 0 L 1 R 2 Fell out 3 Turning;
}ans[10005];

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			int l,t,n;
			scanf("%d%d%d",&l,&t,&n);
			int i;
			for(i=1;i<=n;i++){
				a[i].num=i;
				scanf("%d",&a[i].dis);
				char s[10];
				scanf("%s",s);
				if(s[0]=='L')a[i].d=0;
				else a[i].d=1;
			}
			sort(a+1,a+n+1);
			for(i=1;i<=n;i++){
				b[i].d=a[i].d;
				if(a[i].d)b[i].dis=a[i].dis+t;
				else b[i].dis=a[i].dis-t;
			}
			sort(b+1,b+n+1);
			for(i=1;i<=n;i++){
				int pos=a[i].num;
				ans[pos].f=b[i].d;
				ans[pos].dis=b[i].dis;
				bool f=1;
				if(i-1>=1&&b[i-1].dis==b[i].dis)f=0;
				if(i+1<=n&&b[i+1].dis==b[i].dis)f=0;
				if(!f)ans[pos].f=3;
				if(b[i].dis>l||b[i].dis<0)ans[pos].f=2;
			}
			printf("Case #%d:\n",q);
			for(i=1;i<=n;i++){
				if(ans[i].f==2)printf("Fell off\n");
				else{
					printf("%d ",ans[i].dis);
					if(ans[i].f==0)printf("L\n");
					else if(ans[i].f==1)printf("R\n");
					else if(ans[i].f==3)printf("Turning\n");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
