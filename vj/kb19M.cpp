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
	ll a,b,n;
	while(scanf("%lld%lld%lld%d",&a,&b,&n,&mod)!=EOF){
		if(n==1){
			printf("%lld\n",(2*a)%mod);
			continue;
		}
		mat tmp(2,2),t(2,1);
		tmp.m[1][1]=(2*a)%mod;
		tmp.m[1][2]=((b%mod-(a*a)%mod)%mod+mod)%mod;
		tmp.m[2][1]=1;
		tmp.m[2][2]=0;
		t.m[1][1]=((2*a)%mod)*a%mod+(2*(b%mod))%mod;
		t.m[2][1]=(2*a)%mod;
		t=(tmp^(n-2))*t;
		printf("%lld\n",t.m[1][1]);
	}
	return 0;
}
