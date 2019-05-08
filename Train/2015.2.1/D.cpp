#include<stdio.h>
#define p 10007
struct Mat{
	int m[5][5];
};
Mat E,A;
int n=4,x,y,N;

 Mat matMultiply(Mat A,Mat B)
 {
 	int i,j,k;
 	Mat temp;
 	for(i=1;i<=n;i++)
 		for(j=1;j<=n;j++){
 			temp.m[i][j]=0;
 			for(k=1;k<=n;k++){
 				temp.m[i][j]+=A.m[i][k]*B.m[k][j]%p;
 				temp.m[i][j]%=p;
 			}
 		}
 	return temp;
 }

 Mat matQuickPow(Mat A,int n)
 {
 	Mat temp=E;
 	while(n){
 		if(n&1) temp=matMultiply(A,temp);
 		n>>=1;
 		A=matMultiply(A,A);
 	}
 	return temp;
 }

int main()
{
	E.m[1][1]=1;E.m[2][2]=1;E.m[3][3]=1;E.m[4][4]=1;
	while(scanf("%d%d%d",&N,&x,&y)!=EOF){
		x%=p;y%=p;
		A.m[1][1]=1;A.m[1][2]=x*x%p;A.m[1][3]=y*y%p;A.m[1][4]=2*x*y%p;
		A.m[2][1]=0;A.m[2][2]=x*x%p;A.m[2][3]=y*y%p;A.m[2][4]=2*x*y%p;
		A.m[3][1]=0;A.m[3][2]=1;A.m[3][3]=0;A.m[3][4]=0;
		A.m[4][1]=0;A.m[4][2]=x;A.m[4][3]=0;A.m[4][4]=y;
		A=matQuickPow(A,N-1);
		printf("%d\n",(A.m[1][1]*2+A.m[1][2]+A.m[1][3]+A.m[1][4])%p);
	}
 return 0;
}
