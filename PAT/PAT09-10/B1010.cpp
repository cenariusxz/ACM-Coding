#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int cnt = 0;
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a * b != 0){
			if(cnt != 0)printf(" ");
			printf("%d %d",a*b,b-1);
			cnt++;
		}
	}
	if(cnt == 0)printf("0 0");
	printf("\n");
	return 0;
}
