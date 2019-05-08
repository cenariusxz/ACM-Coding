#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

int num[1005];

int main(){
	memset(num,0,sizeof(num));
	for(int i=1;i<=1000;++i){
		for(int j=1;j<=i;++j){
			if(i%j==0)num[i]++;
		}
	}
	int ma=0;
	for(int i=1;i<=1000;++i)if(num[i]>num[ma])ma=i;
	printf("%d %d\n",ma,num[ma]);
}
