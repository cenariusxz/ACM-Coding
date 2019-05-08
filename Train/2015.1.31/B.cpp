#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
typedef struct dian{
    char x1;
    int x;
    int y;
    int step;
}dian;
queue <dian> q;
dian d[100],f[9][9];
void clear (){
    while(!q.empty()){
        q.pop();
    }
}

void F(){
    {
        q.pop;

    }
}

int main(){
    dian d0;
    while(scanf("%c%d",&d[1].x1,&d[1].y)!=EOF){
        memset(f,0,sizeof(f));
        getchar();
        scanf("%c%d",&d0.x1,&d0.y);
        getchar();
        d[1].x=d[1].x1-('a'-1);
        d0.x=d0.x1-('a'-1);
        d[1].step=0;
        q.push(d[1]);
        f[1]=1;
        for(;;){
            d[0]=q.front();
            if (d[0].x==d2.x&&d[0].y==d2.y) break;
            else {
                F();
            }
        }
    }
    return 0;
}
