#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;
typedef long long ll;

int main(){
	srand(time(NULL));
	int T=10000;
	printf("%d\r\n",T);
	for(int i=1;i<=998;++i){
		printf("%d\r\n",i);
	}
	printf("83336\r\n83337\r\n");
	for(int i=1001;i<=5000;++i){
		printf("%d\r\n",rand());
	}
	for(int i=5001;i<=10000;++i){
		ll tmp=rand()*(ll)2147483647+rand();
		while(tmp>1000000000000000000ll){
			tmp=rand()*(ll)2147483647+rand();
		}
		printf("%lld\r\n",tmp);
	}
	return 0;
}
