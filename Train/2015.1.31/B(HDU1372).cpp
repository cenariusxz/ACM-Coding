#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node{
	int x,y,step;
};
bool g[10][10];
int sx,sy,ex,ey,xx[8]={2,1,-1,-2,-2,-1,1,2},yy[8]={1,2,2,1,-1,-2,-2,-1};
char s1[10],s2[10];

 int BFS()
 {
 	int i;
 	queue<node> q;
 	node tmp,now;
 	memset(g,0,sizeof(g));
 	tmp.x=sx;
 	tmp.y=sy;
 	tmp.step=0;
 	q.push(tmp);
 	while(!q.empty()){
 		now=q.front();
 		q.pop();
 		//printf("%d %d %d\n",now.x,now.y,now.step);
 		g[now.x][now.y]=1;
 		if(now.x==ex&&now.y==ey) return now.step;
 		for(i=0;i<8;i++){
 			tmp.x=now.x+xx[i];
 			tmp.y=now.y+yy[i];
 			tmp.step=now.step+1;
 			if(tmp.x<1||tmp.x>8||tmp.y<1||tmp.y>8||g[tmp.x][tmp.y]) continue;
 			q.push(tmp);
 		}
 	}
 }

int main()
{
	//freopen("out.txt","w",stdout);
	while(scanf("%s%s",s1,s2)!=EOF){
		sx=s1[0]-'a'+1;sy=s1[1]-'0';
 		ex=s2[0]-'a'+1;ey=s2[1]-'0';
 		//for(sx=1;sx<=8;sx++)
 		//for(sy=1;sy<=8;sy++)
 		//for(ex=1;ex<=8;ex++)
 		//for(ey=1;ey<=8;ey++)
 		printf("To get from %c%c to %c%c takes %d knight moves.\n",s1[0],s1[1],s2[0],s2[1],BFS());
	}
 return 0;
}

