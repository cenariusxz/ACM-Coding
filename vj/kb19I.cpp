#include<stdio.h>
#include<string.h>
typedef long long ll;

struct mat{
    int r,c;
    ll m[3][3];		//经测试最大开成590*590的 ll 型矩阵
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
            tmp.m[i][j]=0;
            for(k=1;k<=m1.c;k++){
                tmp.m[i][j]+=m1.m[i][k]*m2.m[k][j];
            }
        }
    }
    return tmp;
}

mat MatQP(mat a,ll n){		//根据题目需要也可用 ll n
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
	ll p,q,n;
	while(scanf("%lld%lld%lld",&p,&q,&n)==3&&p+q+n){
		if(n==0)printf("%lld\n",2);
		else{
			mat tmp,a;
			a.r=2;
			a.c=1;
			tmp.r=tmp.c=2;
			a.m[1][1]=p;
			a.m[2][1]=2;
			tmp.m[1][1]=p;
			tmp.m[1][2]=-q;
			tmp.m[2][1]=1;
			tmp.m[2][2]=0;
			tmp=MatQP(tmp,n-1);
			a=MatMul(tmp,a);
			printf("%lld\n",a.m[1][1]);
		}
	}
	return 0;
}
