#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const int maxn=1e6+5;
const int mod=1e9+7;
char s[maxn],t[maxn<<1];
int p[maxn<<1];
ll ladd[maxn],lnum[maxn],radd[maxn],rnum[maxn];
ll lcnt[maxn],rcnt[maxn],lsub[maxn],rsub[maxn];

int manacher(){
	int len=strlen(s),l=0;
	t[l++]='$';
	t[l++]='#';
	for(int i=0;i<len;++i){
		t[l++]=s[i];
		t[l++]='#';
	}
	t[l]=0;
	int maxx=0,num=0;
	for(int i=0;i<l;++i){
		p[i]=maxx>i?min(p[2*num-i],maxx-i):1;
		while(t[i+p[i]]==t[i-p[i]])p[i]++;
		if(i+p[i]>maxx){
			maxx=i+p[i];
			num=i;
		}
	}
	return l;
}

int main(){
	while(scanf("%s",s)!=EOF){
		int n=strlen(s);
		int len=manacher();
//		printf("%s\n",t);
//		for(int i=0;i<len;++i){
//			printf("%d ",p[i]);
//		}
//		printf("\n");
		memset(ladd,0,sizeof(ladd));
		memset(lnum,0,sizeof(lnum));
		memset(radd,0,sizeof(radd));
		memset(rnum,0,sizeof(rnum));
		memset(lcnt,0,sizeof(lcnt));
		memset(rcnt,0,sizeof(rcnt));
		memset(lsub,0,sizeof(lsub));
		memset(rsub,0,sizeof(rsub));
		for(int i=0;i<len;++i){
			if(p[i]-1){
				if(i%2){
					int ra=p[i]-2;
					ladd[(i-ra)/2]+=(i+ra)/2;
					ladd[(i-ra)/2]%=mod;
					ladd[(i+1)/2]-=(i+ra)/2;
					ladd[(i+1)/2]=(ladd[(i+1)/2]%mod+mod)%mod;
					lnum[(i-ra)/2+1]-=1;
					lnum[(i-ra)/2+1]=(lnum[(i-ra)/2+1]%mod+mod)%mod;
					lnum[(i+1)/2]+=1;
					lnum[(i+1)/2]%=mod;
					lsub[(i+1)/2]+=max(0,(p[i]-3)/2);
					lsub[(i+1)/2]%=mod;
					radd[(i+ra)/2]+=(i-ra)/2;
					radd[(i+ra)/2]%=mod;
					radd[(i-1)/2]-=(i-ra)/2;
					radd[(i-1)/2]=(radd[(i-1)/2]%mod+mod)%mod;
					rnum[(i+ra)/2-1]+=1;
					rnum[(i+ra)/2-1]%=mod;
					rnum[(i-1)/2]-=1;
					rnum[(i-1)/2]=(rnum[(i-1)/2]%mod+mod)%mod;
					rsub[(i-1)/2]-=max(0,(p[i]-3)/2);
					rsub[(i-1)/2]=(rsub[(i-1)/2]%mod+mod)%mod;
				}
				else{
					int ra=p[i]-2;
					ladd[(i-ra)/2]+=(i+ra)/2;
					ladd[(i-ra)/2]%=mod;
					ladd[i/2+1]-=(i+ra)/2;
					ladd[i/2+1]=(ladd[i/2+1]%mod+mod)%mod;
					lnum[(i-ra)/2+1]-=1;
					lnum[(i-ra)/2+1]=(lnum[(i-ra)/2+1]%mod+mod)%mod;
					lnum[i/2+1]+=1;
					lnum[i/2+1]%=mod;
					lsub[i/2+1]+=max(0,(p[i]-2)/2);
					lsub[i/2+1]%=mod;
					radd[(i+ra)/2]+=(i-ra)/2;
					radd[(i+ra)/2]%=mod;
					radd[i/2-1]-=(i-ra)/2;
					radd[i/2-1]=(radd[i/2-1]%mod+mod)%mod;
					rnum[(i+ra)/2-1]+=1;
					rnum[(i+ra)/2-1]%=mod;
					rnum[i/2-1]-=1;
					rnum[i/2-1]=(rnum[i/2-1]%mod+mod)%mod;
					rsub[i/2-1]-=max(0,(p[i]-2)/2);
					rsub[i/2-1]=(rsub[i/2-1]%mod+mod)%mod;
				}
/*				printf("%d:\n",i);
				for(int i=1;i<=n;++i){
					printf("%lld ",ladd[i]);
				}
				printf("\n");
				for(int i=1;i<=n;++i){
					printf("%lld ",lnum[i]);
				}
				printf("\n");
				for(int i=1;i<=n;++i){
					printf("%lld ",lsub[i]);
				}
				printf("\n");

				for(int i=0;i<=n;++i){
					printf("%lld ",radd[i]);
				}
				printf("\n");
				for(int i=0;i<=n;++i){
					printf("%lld ",rnum[i]);
				}
				printf("\n");
				for(int i=0;i<=n;++i){
					printf("%lld ",rsub[i]);
				}
				printf("\n");*/
			}
		}
		ll la=0,ls=0,ln=0;
		for(int i=0;i<=n;++i){
			ln=(ln+lnum[i])%mod;
			ls=(ls+lsub[i]+ln)%mod;
			la=(la+ladd[i])%mod;
			lcnt[i]=((ls+la)%mod+mod)%mod;
		}
		ll ra=0,rs=0,rn=0;
		for(int i=n+1;i>=1;--i){
			rn=(rn+rnum[i])%mod;
			rs=(rs+rsub[i]+rn)%mod;
			ra=(ra+radd[i])%mod;
			rcnt[i]=((rs+ra)%mod+mod)%mod;
		}
		ll ans=0;
		for(int i=1;i<n;++i){
			ans=(ans+lcnt[i+1]*rcnt[i]%mod)%mod;
		}
/*		for(int i=1;i<=n;++i){
			printf("%lld ",lcnt[i]);
		}
		printf("\n");
		for(int i=1;i<=n;++i){
			printf("%lld ",rcnt[i]);
		}
		printf("\n");*/
		printf("%lld\n",ans);
	}
	return 0;
}
