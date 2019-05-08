#include<stdio.h>
const int INF=0x7fffffff;

inline int read(){
	int x=0,d=1;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-'){
		d=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*d;
}

inline int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int n=read();
//	int n;
//	scanf("%d",&n);
	int maxx=-INF;
	int size=0;
	while(n--){
		int s=read();
	//	int s;
	//	scanf("%d",&s);
		if(s==1){
			int a=read();
		//	int a;
		//	scanf("%d",&a);
			size++;
			maxx=max(a,maxx);
		}
		else if(s==2){
			if(size){
				size--;
				if(!size)maxx=-INF;
			}
		}
		else if(s==3){
			if(size)printf("%d\n",maxx);
			else printf("0\n");
		}
	}
	return 0;
}
