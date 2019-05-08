#include<stdio.h>
#include<string.h>
#include<time.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int num[10]={0,1,2,3,4,5,6,7,8,9};
int ans[10];

int main(){
	srand(time(NULL));
	printf("1000\n");
	printf("9 0 0 0 0 0 0 0 0\n");
	printf("1 1 1 1 1 1 1 1 1\n");
	printf("0 0 3 0 0 3 0 0 3\n");
	for(int i=0;i<=997;++i){
		random_shuffle(num+1,num+9);
		int n=9;
		for(int i=1;i<=8;++i){
			int p=rand()%n;
			n-=p;
			ans[num[i]]=p;
		}
		ans[num[9]]=n;
		for(int i=1;i<=9;++i){
			printf("%d",ans[i]);
			if(i==9)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
