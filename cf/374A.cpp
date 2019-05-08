#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
	int n,m,a,b,i,j;
	scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b);
	int ans=0x7fffffff;
	if((abs(i-1)<a&&abs(i-n)<a)||(abs(j-1)<b&&abs(j-m)<b)){
		if(i==1){
			if(j==1||j==m){
				printf("0\n");
				return 0;
			}
		}
		else if(i==n){
			if(j==1||j==m){
				printf("0\n");
				return 0;
			}
		}
		printf("Poor Inna and pony!\n");
		return 0;
	}
	if((!(abs(i-1)%a))&&(!(abs(j-1)%b))){
		int x=abs(i-1)/a;
		int y=abs(j-1)/b;
		if((x%2)==(y%2)){
			ans=min(max(x,y),ans);
		}
	}
	if((!(abs(i-1)%a))&&(!(abs(j-m)%b))){
		int x=abs(i-1)/a;
		int y=abs(j-m)/b;
		if((x%2)==(y%2)){
			ans=min(max(x,y),ans);
		}
	}
	if((!(abs(i-n)%a))&&(!(abs(j-1)%b))){
		int x=abs(i-n)/a;
		int y=abs(j-1)/b;
		if((x%2)==(y%2)){
			ans=min(max(x,y),ans);
		}
	}
	if((!(abs(i-n)%a))&&(!(abs(j-m)%b))){
		int x=abs(i-n)/a;
		int y=abs(j-m)/b;
		if((x%2)==(y%2)){
			ans=min(max(x,y),ans);
		}
	}
	if(ans==0x7fffffff)printf("Poor Inna and pony!\n");
	else printf("%d\n",ans);
	return 0;
}
