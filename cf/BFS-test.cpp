#include <bits/stdc++.h>
using namespace std;

const int MAX[3] = {10,5,6};

struct node{
    int num[3];
    node(int a1,int b1,int c1){
        num[0]=a1;
        num[1]=b1;
        num[2]=c1;
    }
};

int pre[3][11][11][11];
int vis[11][11][11];

node To(node x,int a,int b){
    node tmp = x;
    if(x.num[b] < MAX[b]){
        if(x.num[a] >= (MAX[b] - x.num[b])){
        tmp.num[a] -= MAX[b] - tmp.num[b];
        tmp.num[b] = MAX[b];
}

    else{
        tmp.num[b] += tmp.num[a];
        tmp.num[a] = 0;
    }
}
    return tmp;
}

int main()
{
    queue<node>q;
    vis[0][5][6] = 1;
    pre[0][0][5][6] = -1;
    q.push(node(0,5,6));
    node ans = node(0,0,0);
    while(!q.empty()){
        node u = q.front();
        q.pop();
        if(u.num[0] == 8){
            ans = u;
            break;
        }
        for(int i = 0 ; i <= 2 ; ++ i){
            for(int  j = 0 ; j <= 2 ; ++ j){
                if(i == j)continue;
                node tmp = To(u,i,j);
                if(!vis[tmp.num[0]][tmp.num[1]][tmp.num[2]]){
                    vis[tmp.num[0]][tmp.num[1]][tmp.num[2]] = 1;
                    pre[0][tmp.num[0]][tmp.num[1]][tmp.num[2]] = u.num[0];
                    pre[1][tmp.num[0]][tmp.num[1]][tmp.num[2]] = u.num[1];
                    pre[2][tmp.num[0]][tmp.num[1]][tmp.num[2]] = u.num[2];
                    q.push(tmp);
                }
            }
        }
    }
    node tmp = ans;
    while(pre[0][tmp.num[0]][tmp.num[1]][tmp.num[2]] != -1){
        printf("%d %d %d\n",tmp.num[0],tmp.num[1],tmp.num[2]);
        ans.num[0] = pre[0][tmp.num[0]][tmp.num[1]][tmp.num[2]];
        ans.num[1] = pre[1][tmp.num[0]][tmp.num[1]][tmp.num[2]];
        ans.num[2] = pre[2][tmp.num[0]][tmp.num[1]][tmp.num[2]];
        tmp = ans;
    }
    return 0;
}
