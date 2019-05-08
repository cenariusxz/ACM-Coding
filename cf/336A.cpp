#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	int x1,y1,x2,y2;
	int ans=abs(x)+abs(y);
	if(x>0&&y>0){
		printf("%d %d %d %d\n",0,ans,ans,0);
	}
	if(x>0&&y<0){
		printf("%d %d %d %d\n",0,-ans,ans,0);
	}
	if(x<0&&y<0){
		printf("%d %d %d %d\n",-ans,0,0,-ans);
	}
	if(x<0&&y>0){
		printf("%d %d %d %d\n",-ans,0,0,ans);
	}
	return 0;
}
