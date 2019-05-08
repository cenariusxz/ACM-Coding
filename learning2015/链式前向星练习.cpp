#include<stdio.h>
#include<string.h>
int now=0;
int head[100],next[100],point[100],value[100];
void add(int x,int y/*,int v*/){
    next[++now]=head[x];
    head[x]=now;
    point[now]=y;
//    value[now]=v;
}
int main(){
    int x;
    for(int i=head[x];i;i=next[i]){
        int p=point[i];
    }
}
