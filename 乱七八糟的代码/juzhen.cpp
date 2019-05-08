#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=3;

struct mat{
    int r,c;
    ll m[50][50];        //经测试最大开成590*590的 ll 型矩阵
    void clear(){
        memset(m,0,sizeof(m));
    }

	mat operator+(mat a)const{
		mat ans;
		ans.r=r;
		ans.c=c;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				ans.m[i][j]=(m[i][j]+a.m[i][j])%mod;
			}
		}
		return ans;
	}

	mat operator*(mat a)const{
		mat tmp;
		tmp.r=r;
		tmp.c=a.c;
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

	mat operator^(int n)const{		//需要时可以用 ll n，注意运算符优先级比较低，多用括号；
		mat ans,tmp;
		tmp.r=tmp.c=r;
		memcpy(tmp.m,m,sizeof(tmp.m));
		ans.r=ans.c=r;
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
	mat a;
	a.c=a.r=5;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++)scanf("%lld",&a.m[i][j]);
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		mat ans=a^n;
		ans.print();
	}
}
