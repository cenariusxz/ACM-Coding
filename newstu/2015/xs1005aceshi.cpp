#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	srand(time(NULL));
	for(int i=1;i<=30;++i){
		printf("%d %d\n",rand()%100000+1,rand()%100000+1);
	}
	return 0;
}
