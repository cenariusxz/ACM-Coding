#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct dian{
    int x;
    int y;
    int step;
};
int x1,x2,y1,y2,xx[8]={1,1,-1,-1,2,2,-2,-2},yy[8]={2,-2,2,-2,1,-1,1,-1};
char s1[10],s2[10];
bool f[10][10];

int BFS(){
    memset(f,0,sizeof(f));
    queue <dian> q;
    dian now,t;
    t.x=x1;
    t.y=y1;
    t.step=0;
    q.push(t);
    f[t.x][t.y]=1;
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(now.x==x2&&now.y==y2)return now.step;
        for (int i=0;i<8;i++){
            t.x=now.x+xx[i];
            t.y=now.y+yy[i];
            t.step=now.step+1;
            if(!f[t.x][t.y]&&t.x>=1&&t.x<=8&&t.y>=1&&t.y<=8){
                q.push(t);
                f[t.x][t.y]=1;
            }
        }
    }
}

int main(){
    while(scanf("%s%s",s1,s2)!=EOF){
        x1=s1[0]-'a'+1;
        y1=s1[1]-'0';
        x2=s2[0]-'a'+1;
        y2=s2[1]-'0';
        printf("To get from %c%c to %c%c takes %d knight moves.\n",s1[0],s1[1],s2[0],s2[1],BFS());
    }
    return 0;
}
