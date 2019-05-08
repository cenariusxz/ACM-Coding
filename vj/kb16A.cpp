#include<stdio.h>
#include<string.h>

int s[1000005],t[10005];
int p[10005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)scanf("%d",&s[i]);
		for(int i=0;i<m;++i)scanf("%d",&t[i]);
		int i,j,ans=-1;
		p[0]=p[1]=0;
		for(i=1;i<m;++i){
			j=p[i];
			while(j&&t[i]!=t[j])j=p[j];
			p[i+1]=t[i]==t[j]?j+1:0;
		}
		j=0;
		for(i=0;i<n;++i){
			while(j&&s[i]!=t[j])j=p[j];
			if(s[i]==t[j])j++;
			if(j==m){
				ans=i-m+2;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
