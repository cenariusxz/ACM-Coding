#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
	int a,b,s;
	scanf("%d%d%d",&a,&b,&s);
	int t=abs(a)+abs(b);
	if(t>s)printf("No\n");
	else if((s-t)%2)printf("No\n");
	else printf("Yes\n");
	return 0;
}
