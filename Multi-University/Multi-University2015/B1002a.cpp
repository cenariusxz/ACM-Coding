#include<stdio.h>

inline int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

inline int min(int x,int y){
	return x<y?x:y;
}

inline int max(int x,int y){
	return x>y?x:y;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int m=read();
		int x=read();
		int y=read();
		int ans=(min(m,n)+1)/2,a;
		if(m==n&&m%2&&x==y&&x==(m+1)/2)ans--;
		a=min(y-1,min(x,n-x+1));
		ans=max(ans,a);
		a=min(x-1,min(y,m-y+1));
		ans=max(ans,a);
		a=min(m-y,min(x,n-x+1));
		ans=max(ans,a);
		a=min(n-x,min(y,m-y+1));
		ans=max(ans,a);
		printf("%d\n",ans);
	}
	return 0;
}
