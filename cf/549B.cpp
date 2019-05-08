#include<stdio.h>
#include<string.h>

char s[105][105];
int a[105],b[105],vis[105];
int n;
int main(){
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)scanf("%s",s[i]);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	while(1){
		bool f=0;
		for(i=0;i<n;i++)if(a[i]==b[i]){
			vis[i]=1;
			for(j=0;j<n;j++)b[j]+=s[i][j]-'0';
			f=1;
			break;
		}
		if(!f)break;
	}
	int ans=0;
	for(i=0;i<n;i++){
		if(vis[i])ans++;
	}
	printf("%d\n",ans);
	for(i=0;i<n;i++)if(vis[i])printf("%d\n",i+1);
	return 0;
}
