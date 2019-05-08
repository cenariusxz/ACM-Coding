#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		bool f1=0,f2=0,f3=0,ff=0;
		char c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while(c>='a'&&c<='z'){
		//	printf("%c",c);
			if(f1==0){
				if(c=='w')f1=1;
				else if(ff){
					if(c=='v')f1=1;
					else ff=0;
				}
				else if(c=='v')ff=1;
			}
			else{
				if(f2==0){
					if(c=='y')f2=1;
				}
				else{
					if(f3==0){
						if(c=='h')f3=1;
					}
				}
			}
			c=getchar();
		}
		if(f3)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
