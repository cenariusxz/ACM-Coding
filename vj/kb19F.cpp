#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
const int mod=1000;

struct mat{
    int r,c;
    int m[55][55];        //经测试最大开成590*590的 ll 型矩阵
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
                printf("%d",m[i][j]);
                if(j==c)printf("\n");
                else printf(" ");
            }
        }
    }

};

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		while(T--){
			int n,r;
			scanf("%d%d",&n,&r);
			mat a(n,1),tmp(n,n);
			int i,j,c;
			for(i=1;i<=n;i++){
				scanf("%d",&a.m[i][1]);
				a.m[i][1]%=mod;
			}
			tmp.clear();
			for(i=1;i<=n;i++){
				scanf("%d",&c);
				for(j=1;j<=c;j++){
					int b;
					scanf("%d",&b);
					tmp.m[i][b+1]=1;
				}
			}
			tmp=tmp^r;
			a=tmp*a;
			for(i=1;i<=n;i++){
				printf("%d",a.m[i][1]);
				if(i==n)printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
