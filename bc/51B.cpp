#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	int T=read();
	while(T--){
		int k=read();
		int b=read();
		int x=read();
		int mod=read();
		if(k==0){
			if(b==x)printf("1\n");
			else printf("-1\n");
			continue;
		}
		
	}
	return 0;
}
