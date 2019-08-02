#include <stdio.h>
using namespace std;

int main(){
	int a;
	scanf("%d", &a);
	if(a <= 9)printf("1\n");
	else if(a <= 99)printf("2\n");
	else if(a <= 999)printf("3\n");
	else if(a <= 9999)printf("4\n");
	else if(a <= 99999)printf("5\n");
	else if(a <= 999999)printf("6\n"); 
	return 0;
}
