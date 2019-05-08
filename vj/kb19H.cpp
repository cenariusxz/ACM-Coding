#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=10;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

struct mat{
    int r,c;
    int m[100][100];
    void clear(){
        for(int i=1;i<=r;i++)memset(m[i],0,sizeof(m[i]));
    }
};

mat MatMul(mat m1,mat m2){
    mat tmp;
    tmp.r=m1.r;
    tmp.c=m2.c;
    int i,j,k;
    for(i=1;i<=tmp.r;i++){
        for(j=1;j<=tmp.c;j++){
            int t=0;
            for(k=1;k<=m1.c;k++){
                t=(t+m1.m[i][k]*m2.m[k][j])%mod;
            }
            tmp.m[i][j]=t;
        }
    }
    return tmp;
}

mat MatQP(mat a,int n){    
	mat ans,tmp=a;
	ans.r=ans.c=a.r;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=1;i<=ans.r;i++){
        ans.m[i][i]=1;
    }
    while(n){
        if(n&1)ans=MatMul(ans,tmp);
        n>>=1;
        tmp=MatMul(tmp,tmp);
    }
    return ans;
}

int main(){
	int n,k,i,j;
	while(scanf("%d%d",&n,&k)!=EOF&&n!=0||k!=0){
		mat a;
		a.c=a.r=n;
		mat tmp;
		tmp.c=tmp.r=2*n;
		a.clear();
		tmp.clear();
		for(i=1;i<=n;i++){
			tmp.m[i][i]=1;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				a.m[i][j]=read();
				tmp.m[i][j+n]=tmp.m[i+n][j+n]=a.m[i][j];
			}
		}
		tmp=MatQP(tmp,k-1);
		mat t;
		t.r=t.c=n;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				t.m[i][j]=tmp.m[i][j]+tmp.m[i][j+n];
			}
		}
		a=MatMul(t,a);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				printf("%d",a.m[i][j]);
				if(j==n)printf("\n");
				else printf(" ");
			}
		}
		printf("\n");
	}
    return 0;
}
