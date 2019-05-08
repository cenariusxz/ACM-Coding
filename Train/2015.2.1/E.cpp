#include<stdio.h>
#include<string.h>
struct Mat{
	int m[4][4];
};
Mat E,A;
int n=4,x,N,m,p;

 Mat matMultiply(Mat &A,Mat &B)
 {
 	int i,j,k;
 	Mat temp;
 	memset(temp.m,0,sizeof(temp.m));
 	for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            if(A.m[i][k])
                for(j=0;j<n;j++)
                    if(B.m[k][j])
                        temp.m[i][j]=(temp.m[i][j]+(long long)A.m[i][k]*B.m[k][j])%m;
 	return temp;
 }

 Mat matQuickPow(Mat &A,int n)
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
	int t,i;
	long long ans;
	scanf("%d",&t);
	E.m[0][0]=1;E.m[1][1]=1;E.m[2][2]=1;E.m[3][3]=1;
	for(i=1;i<=t;i++){
		scanf("%d%d%d",&p,&N,&m);
		p%=m;x=2*p%m;
		A.m[0][0]=1;A.m[0][1]=(long long)x*x%m;A.m[0][2]=1;A.m[0][3]=-2*x%m;if(A.m[0][3]<0) A.m[0][3]+=m;
		A.m[1][0]=0;A.m[1][1]=(long long)x*x%m;A.m[1][2]=1;A.m[1][3]=-2*x%m;if(A.m[1][3]<0) A.m[1][3]+=m;
		A.m[2][0]=0;A.m[2][1]=1;A.m[2][2]=0;A.m[2][3]=0;
		A.m[3][0]=0;A.m[3][1]=x;A.m[3][2]=0;A.m[3][3]=-1;
		A=matQuickPow(A,N-2);
		ans=(A.m[0][0]*(1+(long long)p*p%m)%m+(long long)A.m[0][1]*((long long)p*p%m)%m+A.m[0][2]+(long long)A.m[0][3]*p%m)%m;
		if(ans<0) ans+=m;
		printf("%I64d\n",ans);
	}
 return 0;
}
