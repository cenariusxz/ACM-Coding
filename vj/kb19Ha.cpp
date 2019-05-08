#include<stdio.h>
#include<string.h>
typedef long long ll;
const int mod=10;

struct mat{
    int r,c;
    int m[50][50];        //经测试最大开成590*590的 ll 型矩阵
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

	mat operator^(int n)const{
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
				printf("%d",m[i][j]);
				if(j==c)printf("\n");
				else printf(" ");
			}
		}
	}

}a,tmp,ans;

mat run(int k){
	if(k==1){
		return a;
	}
	if(!(k%2)){
		return (tmp+(a^(k/2)))*run(k/2);
	}
	return (tmp+(a^(k/2)))*run(k/2)+(a^k);
}

int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF&&n!=0){
		a.c=a.r=tmp.c=tmp.r=n;
		tmp.clear();
		int i,j;
		for(i=1;i<=n;i++)tmp.m[i][i]=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				int b;
				scanf("%d",&b);
				a.m[i][j]=b%mod;
			}
		}
		ans=run(k);
		ans.print();
		printf("\n");

	}
	return 0;
}
