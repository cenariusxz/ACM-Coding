#include <bits/stdc++.h>
using namespace std;
bool b[9][9];
int a[9][9];int a1,a2,b1,b2;int ans;
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

struct node{
	int x,y,zt;
};
queue<node>q;
void bfs(){
	while(!q.empty()){
		node u;
		u=q.front();
		q.pop();
		for(int i=0;i<=7;++i){
			int xx=u.x+dx[i];
			int yy=u.y+dy[i];
			if(xx>=1&&xx<=8&&yy>=1&&yy<=8&&b[xx][yy]==0){
				if(xx==a2&&yy==b2){
					cout<<u.zt<<endl;
					return;
				}
				b[xx][yy]=1;
				q.push(node{xx,yy,u.zt+1});
			}
		}
	}
	cout<<-1<<endl;
	return;
}

int main(){
	int t;cin>>t;
	for(int i=1;i<=t;++i){
        cin>>a1>>b1>>a2>>b2;                         //cout<<1;
        while(!q.empty())q.pop();
        memset(b,0,sizeof(b));
        b[a1][b1]=1;
        q.push(node{a1,b1,1});
        bfs();
	}
	return 0;
}
