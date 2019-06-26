#include <bits/stdc++.h>
using namespace std;

map<string,int> vis;
pair<string,string> pii[10];

char s[25],t[25];
string stx,edx;
int cnt = 0;

int BFS(){
    queue<string>q;
    q.push(stx);
    vis[stx] = 1;
    while(!q.empty()){
        string u = q.front();q.pop();
        if(vis[u] == 11)continue;
        for(int i = 1 ; i <= cnt ; ++ i){
            int pos = -1;
            int lens = pii[i].first.length();
            while((pos = u.find(pii[i].first,pos+1))!=-1){
                string tmp = u;
                tmp.replace(pos,lens,pii[i].second);
                if(tmp == edx)return vis[u]+1;
                if(vis[tmp])continue;
                q.push(tmp);
                vis[tmp] = vis[u]+1;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%s%s",s,t);
    stx = string(s);edx = string(t);
    while(scanf("%s%s",s,t)!=EOF){
        ++cnt;
        pii[cnt].first = string(s);
        pii[cnt].second = string(t);
    }
    int ans = BFS()-1;
    if(ans == -1)printf("NO ANSWER!");
    else printf("%d\n",ans);
    return 0;
}
