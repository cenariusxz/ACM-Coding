#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const ll Mod=9901;
int A,B;
ll ans=1,M;

ll qmul(ll a,ll b){
    ll ret=0;
    while(b){
        if(b&1) ret=(ret+a)%M;
        b>>=1;
        a=(a+a)%M;
    }
    return ret;
}

ll qpow(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1) ret=qmul(ret,a);
        b>>=1;
        a=qmul(a,a);
    }
    return ret;
}

int main(){
    scanf("%d%d",&A,&B);
    if(A == 0){
		printf("0\n");
		return 0;
	}
    for(int i=2;i*i<=A;++i){
        if(A%i==0){
            int num=0;
            while(A%i==0){
                A/=i;
                ++num;
            }
            M=Mod*(i-1);
            ans=ans*(qpow(i,num*B+1)-1ll+M)/(i-1)%Mod;
        }
    }
    if(A!=1){
        M=Mod*(A-1);
        ans=ans*(qpow(A,B+1)-1ll+M)/(A-1)%Mod;
    }
    printf("%lld\n",ans);
    return 0;
}
