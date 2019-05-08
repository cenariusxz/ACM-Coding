#include<stdio.h>
#include<string.h>
using namespace std;

bool f[1005][1005];

int main(){
	int k;
	scanf("%d",&k);
	int i,j,ans=902,cnt=1;;
	for(i=2+1;i<=2+30;i++){
		f[1][i]=f[i][1]=1;
	}
	for(i=2;i<=30;i++){
		for(j=1;j<=30;j++){
			if(j<=i-1)f[(i-2)*30+2+j][(i-1)*30+2+j]=f[(i-1)*30+2+j][(i-2)*30+2+j]=1;
			else{
				f[(i-1)*30+2+j][(i-1)*30+1]=f[(i-1)*30+2+j][(i-1)*30+2]=f[(i-1)*30+1][(i-1)*30+2+j]=f[(i-1)*30+2][(i-1)*30+2+j]=1;
			}
		}
	}
	while(k){
		if(k&1){
			f[2][29*30+2+cnt]=f[29*30+2+cnt][2]=1;
		}
		cnt++;
		k>>=1;
	}
	printf("902\n");
	for(i=1;i<=902;i++){
		for(j=1;j<=902;j++){
			if(f[i][j])printf("Y");
			else printf("N");
		}
		printf("\n");
	}
	return 0;
}
