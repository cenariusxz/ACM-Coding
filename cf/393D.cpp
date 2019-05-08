#include<stdio.h>
#include<string.h>
typedef long long ll;

ll ans=0,min1,min2,min3;
int t[4][4];

void mo(int i,int j,int k,int num){
	if(num==1){
		ans+=t[i][j];
	}
	else{
		mo(i,k,j,num-1);
		mo(i,j,k,1);
		mo(k,j,i,num-1);
	}
}

int main(){
	int i,n,j;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			scanf("%d",&t[i][j]);
		}
	}
	scanf("%d",&n);
	if(t[1][2]>t[1][3]+t[3][2])t[1][2]=t[1][3]+t[3][2];
	if(t[1][3]>t[1][2]+t[2][3])t[1][3]=t[1][2]+t[2][3];
	if(t[2][1]>t[2][3]+t[3][1])t[2][1]=t[2][3]+t[3][1];
	if(t[2][3]>t[2][1]+t[1][3])t[2][3]=t[2][1]+t[1][3];
	if(t[3][1]>t[3][2]+t[2][1])t[3][1]=t[3][2]+t[2][1];
	if(t[3][2]>t[3][1]+t[1][2])t[3][2]=t[3][1]+t[1][2];
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	mo(1,3,2,n);
	printf("%lld\n",ans);
	return 0;
}
