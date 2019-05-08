#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const double eps=1e-8;

double len[7];
int x[5],y[5];

double get(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])*1.0+(y[i]-y[j])*(y[i]-y[j])*1.0);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=4;++i){
			scanf("%d%d",&x[i],&y[i]);
		}
		len[1]=get(1,2);
		len[2]=get(1,3);
		len[3]=get(1,4);
		len[4]=get(2,3);
		len[5]=get(2,4);
		len[6]=get(3,4);
		sort(len+1,len+6+1);
		if(len[2]-len[1]<eps&&len[3]-len[2]<eps&&len[4]-len[3]<eps&&len[6]-len[5]<eps&&len[1]*sqrt(2.0)-len[5]<eps){
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}
