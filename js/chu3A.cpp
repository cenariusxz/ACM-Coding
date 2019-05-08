#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
#define PI 3.1415926535897

int R[10005],l[10005],r[10005];
int num[400];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int i,j;
		memset(num,0,sizeof(num));
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&R[i],&l[i],&r[i]);
			for(j=l[i]+95;j<r[i]+95;j++){
				if(R[i]>num[j])num[j]=R[i];
			}
		}
		double sum=0;
		for(i=0;i<370;i++){
			sum+=PI*(double)num[i]*(double)num[i];
		}
		printf("%.10lf\n",sum/360.0);
	}
	return 0;
}
