#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
const int mod=6;

struct mat{
    int r,c;
    int m[7][7];        //经测试最大开成590*590的 ll 型矩阵
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

int m1[2000][2000],m2[2000][2000],tmp[7][7],tmp2[2000][2000],tmp3[2000][2000];

int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF&&n+k){
		int i,j,p;
		for(i=1;i<=n;i++){
			for(j=1;j<=k;j++)scanf("%d",&m1[i][j]);
		}
		for(i=1;i<=k;i++){
			for(j=1;j<=n;j++)scanf("%d",&m2[i][j]);
		}
		for(i=1;i<=k;i++){
			for(j=1;j<=k;j++){
				tmp[i][j]=0;
				for(p=1;p<=n;p++){
					tmp[i][j]+=m2[i][p]*m1[p][j];
				}
				tmp[i][j]%=6;
			}
		}
		mat a(k,k);
		memcpy(a.m,tmp,sizeof(tmp));
		a=(a^(n*n-1));
		memcpy(tmp,a.m,sizeof(tmp));
		for(i=1;i<=n;i++){
			for(j=1;j<=k;j++){
				tmp2[i][j]=0;
				for(p=1;p<=k;p++){
					tmp2[i][j]+=m1[i][p]*tmp[p][j];
				}
				tmp2[i][j]%=6;
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				tmp3[i][j]=0;
				for(p=1;p<=k;p++){
					tmp3[i][j]+=tmp2[i][p]*m2[p][j];
				}
				tmp3[i][j]%=6;
			}
		}
		int ans=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)ans+=tmp3[i][j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
