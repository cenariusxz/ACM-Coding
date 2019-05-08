#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
int mod;

struct mat{
    int r,c;
	ll m[4][4];        //经测试最大开成590*590的 ll 型矩阵
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

    mat operator^(ll n)const{        //需要时可以用 ll n，注意运算符优先级比较低，多用括号；
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
	ll n;
	mat tmp(3,3),a(3,1);
	tmp.clear();
	tmp.m[1][1]=tmp.m[1][2]=tmp.m[1][3]=tmp.m[2][1]=tmp.m[3][3]=1;
	a.m[1][1]=a.m[2][1]=a.m[3][1]=1;
	int cnt=0;
	while(scanf("%lld%d",&n,&mod)!=EOF&&n+mod){
		printf("Case %d: %lld %d ",++cnt,n,mod);
		if(n==0){printf("1\n");continue;}
		mat b=tmp^(n-1);
		b=b*a;
		printf("%lld\n",b.m[1][1]);
	}
	return 0;
}
