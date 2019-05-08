#include<stdio.h>
#include<string.h>

char s[10];
int vis[1000005];
int num[105];

int main(){
	int n;
	scanf("%d",&n);
	int i,j,p=0;
	for(i=1;i<=n;i++){
		scanf("%s",s);
		int b;
		scanf("%d",&b);
		if(s[0]=='+'){
			vis[b]=1;
			num[i]=++p;
		}
		else if(s[0]='-'){
			if(vis[b]){
				vis[b]=0;
				num[i]=--p;
			}
			else{
				num[i]=num[i-1];
				for(j=1;j<=i;j++){
					num[j]++;
				}
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)if(num[i]>ans)ans=num[i];
	printf("%d\n",ans);
	return 0;
}
