#include <bits/stdc++.h>

int read(){
	int x=0,f=1;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

int main(){
	int a[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	printf("%d\n",*(a[1]+1));
	printf("%d\n",*(&a[1][1]));
	printf("%d\n",(*(a+1)[1]));
	printf("%d\n",*(a+5));
	return 0;
}
