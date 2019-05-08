#include<stdio.h>
#include<string.h>
int now=0;
int next[100],head[100],point[100];
void add(int x,int y){
    next[++now]=head[x];
    head[x]=now;
    point[now]=y;
}

int main(){
    int i,a,b;
    memset(head,0,sizeof(head));
    for(i=1;i<=7;i++){
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    for(int x=1;x<=5;x++){
        printf("%d:\t",x);
        for(i=head[x];i;i=next[i]){
            int p=point[i];
            printf("%d\t",p);
        }
        printf("\n");
    }

    return 0;
}
