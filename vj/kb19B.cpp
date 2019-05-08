#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=10000007;
struct mat{
    int r,c;
    ll m[15][15];        //经测试最大开成590*590的 ll 型矩阵
    mat(){}
    mat(int r,int c):r(r),c(c){}
    void clear(){
        memset(m,0,sizeof(m));
    }

    mat operator+(mat a)const{
        mat ans(r,c);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                ans.m[i][j]=(m[i][j]+a.m[i][j])%mod;
            }
        }
        return ans;
    }

    mat operator*(mat a)const{
        mat tmp(r,a.c);
        int i,j,k;
        for(i=1;i<=tmp.r;i++){
            for(j=1;j<=tmp.c;j++){
                tmp.m[i][j]=0;
                for(k=1;k<=c;k++){
                    tmp.m[i][j]=(tmp.m[i][j]+(m[i][k]*a.m[k][j])%mod)%mod;
                }
            }
        }
        return tmp;
    }

    mat operator^(int n)const{        //需要时可以用 ll n，注意运算符优先级比较低，多用括号；
        mat ans(r,r),tmp(r,r);
        memcpy(tmp.m,m,sizeof(tmp.m));
        ans.clear();
        for(int i=1;i<=ans.r;i++){
            ans.m[i][i]=1;
        }
        while(n){
            if(n&1)ans=ans*tmp;
            n>>=1;
            tmp=tmp*tmp;
        }
        return ans;
    }
    
    void print()const{
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                printf("%lld",m[i][j]);
                if(j==c)printf("\n");
                else printf(" ");
            }
        }
    }

};

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		mat a(n+2,1);
		a.m[n+1][1]=233;
		a.m[n+2][1]=3;
		int i,b;
		for(i=1;i<=n;i++){
			scanf("%d",&b);
			a.m[i][1]=b%mod;
		}
		mat t(n+2,n+2);
		int j;
		t.clear();
		for(i=1;i<=n;i++){
			for(j=1;j<=i;j++)t.m[i][j]=1;
			t.m[i][n+1]=1;
		}
		t.m[n+1][n+1]=10;
		t.m[n+1][n+2]=t.m[n+2][n+2]=1;
		t=(t^m);
		a=t*a;
		printf("%lld\n",a.m[n][1]);
	}
	return 0;
}
