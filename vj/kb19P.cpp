#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
int mod;

struct mat{
    int r,c;
    int m[205][205];        //经测试最大开成590*590的 ll 型矩阵
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
	mat a(3,1),tmp(3,3);
	a.m[1][1]=2;
	a.m[2][1]=a.m[3][1]=1;
	tmp.clear();
	tmp.m[1][1]=tmp.m[1][2]=tmp.m[1][3]=tmp.m[2][2]=tmp.m[2][3]=tmp.m[3][2]=1;
	int n,T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			scanf("%d%d",&n,&mod);
			mat t=tmp^(n-2);
			t=t*a;
			printf("Case %d: ",q);
			if(t.m[1][1]%2||t.m[1][1]==0)printf("No\n");
			else{
				printf("Yes\n");
				int i,j;
				int r=t.m[1][1];
				mat ans(r,r);
				for(i=1;i<=r;i++){
					for(j=1;j<=r-i;j++){
						ans.m[i][j]=1;
					}
					for(j=r-i+2;j<=r;j++){
						ans.m[i][j]=-1;
					}
					ans.m[i][r-i+1]=(i&1);
				}
				ans.print();
			}
		}
	}
	return 0;
}
