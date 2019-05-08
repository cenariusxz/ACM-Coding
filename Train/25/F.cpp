#include <bits/stdc++.h>
using namespace std;
char s[40],ss[20],p[128][18][45];

int main()
{
	int n,m,i,j,k,ca;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(k=1;k<=n;k++){
		for(i=1;i<=16;i++)
			scanf("%s",&p[s[k]][i][1]);
		scanf("%s",&p[s[k]][0][1]);
	}
	int dot[18][45],ast[18][45],dis[20];
	for(ca=1;ca<=m;ca++){
		printf("Query %d: ",ca);
		scanf("%s",ss+1);
		int l=strlen(ss+1);
		memset(dot,0,sizeof(dot));
		memset(ast,0,sizeof(ast));
		memset(dis,0,sizeof(dis));
		for(k=1;k<=l;k++){
			for(i=1;i<=16;i++)
				for(j=1;j<=43;j++){
					if(p[ss[k]][i][j]=='.'){
						if(dot[i][j]==0) dot[i][j]=k;
						else dot[i][j]=-1;
					}
					else{
						if(ast[i][j]==0) ast[i][j]=k;
						else ast[i][j]=-1;
					}
				}
		}
		for(i=1;i<=16;i++)
			for(j=1;j<=43;j++){
			//	if(dot[i][j]>0) dis[dot[i][j]]=1;
				if(ast[i][j]>0) dis[ast[i][j]]=1;
			}
		/*for(i=1;i<=16;i++){
			for(j=1;j<=43;j++){
				printf("%2d",dot[i][j]);
			}
			printf("\n");
		}*/
		for(i=1;i<=l;i++)
			if(dis[i]) printf("Y");
			else printf("N");
		printf("\n");
	}
 return 0;
}
