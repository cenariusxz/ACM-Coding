#include<stdio.h>
#include<string.h>
const int maxn=1e5+5;
int n,m,k;
int a[maxn];
int b[maxn];

int judge(int s){
	s++;
	for(int j=2;j<=m;++j){
		if(b[j]-b[j-1]>0&&a[s]-a[s-1]>0)s++;
		else if(b[j]-b[j-1]<0&&a[s]-a[s-1]<0)s++;
		else if(b[j]-b[j-1]==0&&a[s]-a[s-1]==0)s++;
		else return 0;
	}
	return 1;
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=m;++i)scanf("%d",&b[i]);
		if(m==1){printf("%d\n",n);continue;}
		int ans=0;
		for(int i=1;i<=n-m+1;++i){
			if(judge(i)){
				i=i+m-1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
