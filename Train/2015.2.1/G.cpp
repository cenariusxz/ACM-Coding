#include<stdio.h>
#include<string.h>
#define p 10000007

struct Mat{
	int m[12][12];
};
int n,N,m,a[12];
Mat E,A;

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
                        temp.m[i][j]=(temp.m[i][j]+(long long)A.m[i][k]*B.m[k][j])%p;
 	return temp;
 }

 void matQuickPow(Mat &temp,Mat &A,int n)
 {
 	while(n){
 		if(n&1) temp=matMultiply(A,temp);
 		n>>=1;
 		A=matMultiply(A,A);
 	}
 }

int main()
{
	int i,j;
	while(scanf("%d%d",&N,&m)!=EOF){
		memset(E.m,0,sizeof(E.m));
		memset(A.m,0,sizeof(A.m));
		for(i=1;i<=N;i++)
			scanf("%d",&a[N]);
		n=N+2;
		A.m[0][0]=10;A.m[0][n-1]=3;A.m[n-1][n-1]=1;
		for(i=1;i<n-1;i++)
			for(j=0;j<i;j++)
				A.m[i][j]=1;
		E.m[0][0]=233;E.m[n-1][0]=1;
		for(i=1;i<n-1;i++)
			E.m[i][0]=E.m[i-1][0]+a[i];
		matQuickPow(E,A,m-1);
		printf("%d\n",E.m[n][0]);
	}
 return 0;
}

