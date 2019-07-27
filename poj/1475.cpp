#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
const int maxn = 25;

char push[4]={'N','S','E','W'};
char move[4]={'n','s','e','w'};
int xx[4] = {-1,1,0,0};
int yy[4] = {0,0,1,-1};

int n,m;
char s[maxn][maxn];
bool vis1[maxn][maxn][4];//bfs_box	记录按某方向push到某个格子是否已搜索过 
bool vis2[maxn][maxn];	//bfs_person
string tmp;

struct box{
    int x,y;
    int px,py;//当前状态person所在的地方
    string ans;
    box(){}
    box(int _x,int _y,int _px,int _py,string _ans):x(_x),y(_y),px(_px),py(_py),ans(_ans){}
};
struct node{
	int x,y;
	string ans;
	node(){}
    node(int _x,int _y,string _ans):x(_x),y(_y),ans(_ans){}
};

bool bfs_person(node p, node t, node b){	
	//person 在 (p.x,p.y)，目标 (t.x,t.y), box 在 (b.x,b.y)
    queue<node>q;
    memset(vis2, 0, sizeof(vis2));
    q.push(p);
    vis2[p.x][p.y] = 1;
    while(!q.empty()){
        node u = q.front(); q.pop();
        if(u.x == t.x && u.y == t.y){
            tmp = u.ans;
            return 1;
        }
        for(int i = 0 ; i < 4 ; i ++){
            int dx = u.x + xx[i];
            int dy = u.y + yy[i];
            if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
            if(s[dx][dy] == '#')continue;
            if(dx == b.x && dy == b.y)continue;
            if(vis2[dx][dy])continue;
            vis2[dx][dy] = 1;
            q.push(node(dx, dy, u.ans+move[i]));
        }
    }
    return 0;
}

string bfs_box(){
    box st;
    st.ans="";
    for(int i = 1 ; i <= n ; ++ i){
    	for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == 'B'){
				st.x = i; st.y = j;
				s[i][j] = '.';	
			}
			if(s[i][j] == 'S'){
				st.px = i; st.py = j;
				s[i][j] = '.';	
			}
		}
    }
    queue<box>q;
    q.push(st);
    memset(vis1,0,sizeof(vis1));
    while(!q.empty()){
        box u = q.front(); q.pop();    
        if(s[u.x][u.y]=='T')return u.ans;
        for(int i=0;i<4;i++){
            int dx = u.x + xx[i];
            int dy = u.y + yy[i];
            if(dx < 1 || dx > n || dy < 1 || dy > m)continue;
            if(s[dx][dy] == '#')continue;
            if(vis1[dx][dy][i])continue;
            bool flag = bfs_person(node(u.px,u.py,""), 
				node(u.x-xx[i], u.y-yy[i], ""), node(u.x,u.y,""));
            if(!flag)continue;
            vis1[dx][dy][i] = 1;
            q.push(box(dx,dy,u.x,u.y,u.ans + tmp + push[i]));
        }
    }
    return "Impossible.";
}

int main(){
    int cnt=0;
    while(scanf("%d%d",&n,&m) && (n + m)){
        for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i] + 1);
        printf("Maze #%d\n", ++cnt);
        printf("%s\n\n",bfs_box().c_str());
    }
    return 0;
}
