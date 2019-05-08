#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int minn(int a,int b){
	return a<b?a:b;
}

int maxx(int a,int b){
	return a>b?a:b;
}

int main(){
	int n,m,x,y;
	while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF){
		int t;
		int a,b,c,d,e;
		int ans=0;
		if(n==m){
			ans=n/2+(n%2);
			if(n%2){
				if(x==n/2+1&&y==m/2+1)ans--;
			}
		}
		else if(n<m){
			ans=n/2+(n%2);
			a=x-1;
			c=n-x;
			if(y<=m/2){
				b=y;
				ans=minn(ans,m-y);
			}
			else{
				b=m-y+1;
				ans=minn(ans,y-1);
			}
			d=minn(a,b);
			e=minn(c,b);
			e=maxx(d,e);
			ans=maxx(e,ans);
		}
		else if(n>m){
			ans=m/2+(m%2);
			a=y-1;
			c=m-y;
			if(x<=n/2){
				b=x;
				ans=minn(ans,n-x);
			}
			else{
				b=n-x+1;
				ans=minn(ans,x-1);
			}
			d=minn(a,b);
			e=minn(c,b);
			e=maxx(d,e);
			ans=maxx(e,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
