#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
	int ans=0;
	for(int i=1;i<(1<<20);++i){
		int tmp=i;
		int num=0;
		for(int j=1;j<=20;++j){
			if(!(tmp&1))num++;
			tmp>>=1;
		}
		if(num>15)continue;
		tmp=i;
		num=0;
		for(int j=1;j<=18;++j){
			if((tmp&7)==7)num++;
			tmp>>=1;
		}
		if(num)continue;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
