#include<stdio.h>
#include<string.h>

int read(){
	char c=getchar();
	int x=0;
	while((c>'9'||c<'0')&&c!='?')c=getchar();
	if(c=='?')return -1;
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int q=1;q<=t;q++){
			int x=read(),y=read(),z=read();
		
		if(x==-1)printf("%d\n",(int)(z/2.0+y));
		if(y==-1)printf("%d\n",(int)(x-z/2.0));
		if(z==-1)printf("%d\n",(int)(2*x-2*y));
	
		}
	}
	return 0;
}
