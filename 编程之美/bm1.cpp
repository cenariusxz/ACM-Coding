#include<stdio.h>
#include<string.h>
typedef unsigned long long ull;

int a[15];
char s[5];
char aa[14]={"23456789TJQKA"};
int bb[14]={2,3,4,5,6,7,8,9,10,11,12,13,1};
int m[500];
ull dp[14][14][14][14],C[500][500],A[500];

void Init(){
    C[0][0]=1;
    for(int i=1;i<480;i++){
        C[i][0]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j]);
        C[i][i]=1;
    }
    A[0]=A[1]=1;
    for(int i=2;i<480;i++)
        A[i]=(A[i-1]*i);
}


void init(){
	int i,j,k,p;
	for(i=0;i<=12;i++)m[aa[i]]=bb[i];
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0]=1;
	for(i=0;i<=13;i++){
		for(j=0;i+j<=13;j++){
			for(k=0;i+j+k<=13;k++){
				for(p=0;i+j+k+p<=13;p++){
					if(!(i+j+k+p))continue;
					int s=i*4+j*3+k*2+p;
					if(i){
						dp[p][k][j][i]=dp[p][k][j+1][i-1]*(s+1-2*(4-1));
						if(k)dp[p][k][j][i]+=2*(k*dp[p+1][k-1][j+1][i-1]);
						if(j)dp[p][k][j][i]+=2*(j*dp[p][k+1][j][i-1]);
						if(i-1)dp[p][k][j][i]+=2*((i-1)*dp[p][k][j+2][i-2]);
					}
					else if(j){
						dp[p][k][j][i]=dp[p][k+1][j-1][i]*(s+1-2*(3-1));
						if(k)dp[p][k][j][i]+=2*(k*dp[p+1][k][j-1][i]);
						if(j-1)dp[p][k][j][i]+=2*((j-1)*dp[p][k+2][j-2][i]);
					}
					else if(k){
						dp[p][k][j][i]=dp[p+1][k-1][j][i]*(s+1-2*(2-1));
					}
					else{
						dp[p][k][j][i]=A[p];
					}
				}
			}
		}
	}
}

int main(){
	int t;
	Init();
	init();
	printf("%llu\n",dp[1][1][0][0]);
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int n,i,j;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			scanf("%s",s);
			a[m[s[0]]]++;
		}
		int num[5];
		memset(num,0,sizeof(num));
		for(i=1;i<=13;i++){
			num[a[i]]++;
		}
		for(i=1;i<=4;i++){
			printf("%d ",num[i]);
		}
		printf("\n");
		printf("%llu\n",dp[num[1]][num[2]][num[3]][num[4]]);
	}
	return 0;
}
