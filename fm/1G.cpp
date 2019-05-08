#include<stdio.h>
#include<string.h>

int m[16][16],a[16],tmp[16][16];

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		int n,cnt=0;
		scanf("%d",&n);
		int i,j,ans=-1;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&m[i][j]);
			}
		}
		for(i=1;i<=n;i++){
			if(m[1][i]==0)a[++cnt]=i;
		}
		int k;
		if(n==1)ans=0;
		else{
			for(i=0;i<=(1<<cnt)-1;i++){
				int num=0;
				bool f=1;
				memcpy(tmp,m,sizeof(tmp));
				for(j=1;j<=cnt;j++){
					if(i&(1<<(j-1))){
						tmp[1][a[j]]=1;
						num++;
					}
				}
				for(j=1;j<n&&f;j++){
					for(k=1;k<=n&&f;k++){
						int s=0;
						if(j>1)s+=tmp[j-1][k];
						if(k>1)s+=tmp[j][k-1];
						if(k<n)s+=tmp[j][k+1];
						if(s%2){
							if(!tmp[j+1][k]){
								tmp[j+1][k]=1;
								num++;
							}
						}
						else{
							if(tmp[j+1][k]){f=0;break;}
						}
					}
				}
				for(k=1;k<=n&&f;k++){
					int s=tmp[n-1][k];
					if(k>1)s+=tmp[n][k-1];
					if(k<n)s+=tmp[n][k+1];
					if(s%2){f=0;break;}
				}
				if(f&&(ans==-1||ans>num))ans=num;
			}
		}
		printf("Case %d: %d\n",q,ans);
	}
	return 0;
}
