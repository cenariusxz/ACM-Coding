#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=1e5;

int num[100000004];

int main(){
	memset(num,0,sizeof(num));
	for(int i=1;i<=maxn;++i){
		for(int j=i;j<=maxn;j+=i){
			num[j]++;
		}
	}
	int maxx=0;
	for(int i=1;i<=maxn;++i){
		if(num[i]>num[maxx])maxx=i;
	}
	printf("%d\n",maxx);
	return 0;
}
