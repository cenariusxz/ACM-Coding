#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int main(){
	srand(100);
	srand(rand());
	for(int i=1;i<=10;++i){
		printf("%d ",rand());
	}
	printf("\n");
	return 0;
}
