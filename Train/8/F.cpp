#include<stdio.h>
#include<string.h>

char s[50001];

void fuck()
{
	int i,j,l,r,ans=0;
	scanf("%s",s+1);
	l=1;r=strlen(s+1);
	while(l<=r){
		for(i=1;i<=(r-l+1);i++){
			for(j=1;j<=i;j++){
				if(s[l+j-1]!=s[r-i+1+j-1]) break;
			}
			if(j>i){
				l=l+i;
				r=r-i;
				ans+=2;
				break;
			}
		}
		//printf(" %d %d\n",l,r);
	}
	if(l-r!=1) ans--;
	printf("%d\n",ans);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		fuck();
	}
 return 0;
}

