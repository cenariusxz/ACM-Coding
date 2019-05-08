#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;


int main(){
	int k,w;
	while(scanf("%d%d",&k,&w)!=EOF){
		int ans=0;
		for(int i=0;i<=k;++i){
			int sum=i;
			int step=0;
			int wa=0;
			int high=k;
			while(1){
				if(wa==w-1){
					step+=sum+1;
					break;
				}
			}
		}
	}
	return 0;
}
