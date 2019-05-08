#include<stdio.h>
#include<string.h>
#include<math.h>
typedef long long ll;
int mod;

ll a[550][2],tmp[550][550],ans[550][550],tmp2[550][550],tmp3[550][550],tmp4[550][2];

int main(){
	int n,d,K;
	while(scanf("%d%d%d%d",&n,&mod,&d,&K)!=EOF){
		memset(tmp,0,sizeof(tmp));
		int i,j,k;
		for(i=1;i<=n;i++){
			for(j=i-d;j<=i+d;j++){
				int t=(j+n)%n;
				if(t==0)t=n;
				tmp[i][t]=1;
			}
		}
		for(i=1;i<=n;i++)scanf("%lld",&a[i][1]);
		memcpy(tmp2,tmp,sizeof(tmp));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++){
			ans[i][i]=1;
		}
		while(K){
			if(K&1){
				for(i=1;i<=n;i++){
					for(j=1;j<=n;j++){
						tmp3[i][j]=0;
						for(k=1;k<=n;k++){
							tmp3[i][j]=(tmp3[i][j]+(ans[i][k]*tmp2[k][j])%mod)%mod;
						}
					}
				}
				memcpy(ans,tmp3,sizeof(tmp3));
			}
			K>>=1;
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					tmp3[i][j]=0;
					for(k=1;k<=n;k++){
						tmp3[i][j]=(tmp3[i][j]+(tmp2[i][k]*tmp2[k][j])%mod)%mod;
					}
				}
			}
			memcpy(tmp2,tmp3,sizeof(tmp3));
		}
		for(i=1;i<=n;i++){
			tmp4[i][1]=0;
			for(k=1;k<=n;k++){
				tmp4[i][1]=(tmp4[i][1]+(ans[i][k]*a[k][1])%mod)%mod;
			}
		}
		for(i=1;i<=n;i++){
			printf("%lld",tmp4[i][1]);
			if(i==n)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}

