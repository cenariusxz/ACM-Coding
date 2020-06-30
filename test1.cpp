#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char a[5][5]; 
int dx[5]={0,0,0,-1,1};
int dy[5]={0,1,-1,0,0};
int vis[5][5],ans=0x3f3f3f3f;
bool check(){
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(a[i][j]!=a[0][0])return 0;
    return 1;
}
int flip(int x,int y){
    for(int i=0;i<5;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>3||ny>3||nx<0||ny<0)continue;
        if(a[nx][ny]=='w')a[nx][ny]='b';
        else a[nx][ny]='w';
    }
}
void DFS(int x,int y,int sum){
    if(x==3&&y==3){
        if(check())ans=min(sum,ans);
        return;
    }
    if(y==3)x++,y=0;
    else y++;
    DFS(x,y,sum);
    flip(x,y);
    DFS(x,y,sum+1);
    flip(x,y);
}
int main(){
    for(int i=0;i<4;i++)scanf("%s",a[i]);
    DFS(0,-1,0);
    if(ans==0x3f3f3f3f)cout<<"Impossible"<<endl;
    cout<<ans<<endl;
    return 0;
}
