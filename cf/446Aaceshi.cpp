#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	for(int i=1;i<=5;++i){
		printf("5\n");
		int n=5;
		for(int i=1;i<=n;++i){
			printf("%d ",rand()%10+1);
		}
		printf("\n");
	}
	return 0;
}
