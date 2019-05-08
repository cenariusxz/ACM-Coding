#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(unsigned(time(NULL)));
	printf("%d\n",rand()%50);
	return 0;
}
