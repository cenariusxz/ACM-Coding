#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char maze[110][110];

 int fuck()
 {
 	int i,j,k,tmp,ans=0;
 	bool ok1,ok2,ok3,ok4;
 	scanf("%d%d",&n,&m);
 	for(i=1;i<=n;i++)
 		scanf("%s",&maze[i][1]);
 	for(i=1;i<=n;i++){
 		for(j=1;j<=m;j++){
 			if(maze[i][j]=='.') continue;
 			ok1=ok2=ok3=ok4=0;
 			for(k=i-1;k>0;k--) if(maze[k][j]!='.'){ok1=1;break;}
 			for(k=i+1;k<=n;k++) if(maze[k][j]!='.'){ok2=1;break;}
 			for(k=j-1;k>0;k--) if(maze[i][k]!='.'){ok3=1;break;}
 			for(k=j+1;k<=m;k++) if(maze[i][k]!='.'){ok4=1;break;}
 			tmp=ok1+ok2+ok3+ok4;
 			switch(maze[i][j]){
 				case('^'):
				 	if(!ok1){
				 		if(tmp) ans++;
				 		else return -1;
				 	}
				 	break;
				case('v'):
				 	if(!ok2){
				 		if(tmp) ans++;
				 		else return -1;
				 	}
				 	break;
				case('<'):
				 	if(!ok3){
				 		if(tmp) ans++;
				 		else return -1;
				 	}
				 	break;
				case('>'):
				 	if(!ok4){
				 		if(tmp) ans++;
				 		else return -1;
				 	}
				 	break;
 			}
 		}
 	}
 	return ans;
 }
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int a,t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		printf("Case #%d: ",k);
		a=fuck();
		if(a==-1) printf("IMPOSSIBLE\n");
		else printf("%d\n",a);
	}
 return 0;
}
