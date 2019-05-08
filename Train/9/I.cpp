#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const ll mod = 1e12;
const int maxf=70;

struct int128{
	ll a,b;
	bool operator < (int128 x)const{
		if(a==x.a)return b<x.b;
		return a<x.a;
	}
	int128 operator + (int128 x)const{
		int128 tmp;
		tmp.a=a+x.a;
		tmp.b=b+x.b;
		tmp.a+=tmp.b/mod;
		tmp.b%=mod;
		return tmp;
	}
	int128 operator - (int128 x)const{
		int128 tmp;
		tmp.a=a-x.a;
		tmp.b=b-x.b;
		if(tmp.b<0){
			tmp.b+=mod;
			tmp.a--;
		}
		return tmp;
	}
	int128 operator * (int128 x)const{
		int128 tmp;
		tmp.a=x.a*b;
		tmp.b=x.b*b;
		tmp.a+=tmp.b/mod;
		tmp.b%=mod;
		return tmp;
	}
	bool operator == (int128 x)const{
		return a==x.a&&b==x.b;
	}
	int128():a(0),b(0){};
	int128(ll x,ll y):a(x),b(y){}
}f[100],p1,p2,sum[100],A[100];

void init(){
	f[0]=int128(0,1);
	f[1]=int128(0,1);
	sum[0]=int128(0,0);
	sum[1]=int128(0,1);
	for(int i=2;i<=70;++i){
		f[i]=f[i-1]+f[i-2]+f[i-2];
		sum[i]=sum[i-1]+f[i];
	}
	A[0]=int128(0,1);
	for(int i=1;i<=maxf;++i){
		A[i]=int128(0,2)*A[i-1];
	}
/*	for(int i=1;i<=10;++i){
		printf("%lld %lld\n",A[i].a,A[i].b);
	}*/
//	printf("%lld %lld\n",sum[70].a,sum[70].b);
}



int main(){
	init();
	ll n,m;
	int cnt=0;
	while(scanf("%lld%lld",&n,&m)!=EOF){
		if(n==0&&m==0)break;
		p1=int128(0,n)*int128((m-1)/mod,(m-1)%mod)+int128(0,1);
		p2=int128(0,n)*int128(m/mod,m%mod);
		int num;
		printf("Case %d: ",++cnt);
		
		for(int i=1;i<=maxf;++i){
			if(p1<sum[i]||p1==sum[i]){
				num=i;
				break;
			}
		}
		if(num%2==0&&p1==sum[num]){
			for(int i=1;i<=num;++i)putchar('b');
			printf(" ");
		}
		else{
			int128 cnt=sum[num-1];
			int pos=0;
			for(int i=1;i<=num;i+=2){
				cnt=cnt+A[num-i];
				if(p1<cnt||p1==cnt){
					cnt = cnt - A[num - i];
					break;
				}
				printf("bb");
				pos+=2;
			}
			printf("a");
			pos++;
			for(int i=1;i<=num-pos;++i){
				if(p1-cnt<A[num-pos-i]||p1-cnt==A[num-pos-i]){
					printf("a");
				}
				else{
					cnt=cnt+A[num-pos-i];
					printf("b");
				}
			}
			printf(" ");
		}
		for(int i=1;i<=maxf;++i){
			if(p2<sum[i]||p2==sum[i]){
				num=i;
				break;
			}
		}
		if(num%2==0&&p2==sum[num]){
			for(int i=1;i<=num;++i)putchar('b');
			printf("\n");
		}
		else{
			int128 cnt=sum[num-1];
			int pos=0;
			for(int i=1;i<=num;i+=2){
				cnt=cnt+A[num-i];
				if(p2<cnt||p2==cnt){
					cnt=cnt-A[num-i];
					break;
				}
				printf("bb");
				pos+=2;
			}
			printf("a");
			pos++;
			for(int i=1;i<=num-pos;++i){
				if(p2-cnt<A[num-pos-i]||p2-cnt==A[num-pos-i]){
					printf("a");
				}
				else{
					cnt=cnt+A[num-pos-i];
					printf("b");
				}
			}
			printf("\n");
		}

	}
	return 0;
}

