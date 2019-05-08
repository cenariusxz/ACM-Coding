#include<stdio.h>
#include<string.h>
using namespace std;

char m[105][105];
int val[105],cnt,r,c;
bool vis[105][105];

int judge1(int s){
    int i;
    int t=val[cnt];
    vis[s][t]=1;
    if(m[s][t]=='>'||m[s][t]=='<'){
        for(i=1;i<=r;i++){
            if(i!=s&&m[i][t]!='.')return 1;
        }
        return 0;
    }
    if(m[s][t]=='^'){
        for(i=1;i<=r;i++){
            if(i<s&&m[i][t]!='.')return -1;
            else if(i>s&&m[i][t]!='.')return 1;
        }
        return 0;
    }
    if(m[s][t]=='v'){
        for(i=r;i>=1;i--){
            if(i>s&&m[i][t]!='.')return -1;
            else if(i<s&&m[i][t]!='.')return 1;
        }
        return 0;
    }
}

int judge2(int s){
    int i;
    int t1=val[1],t2=val[cnt];
    vis[s][t1]=1;
    vis[s][t2]=1;
    int ans=0;
    if(m[s][t1]!='<'){
        ans++;
    }
    else if(m[s][t1]=='^'){
        bool f=1;
        for(i=1;i<s&&f;i++){
            if(m[i][t1]!='.')f=0;
        }
        if(f)ans++;
    }
    else if(m[s][t1]=='v'){
        bool f=1;
        for(i=s+1;i<r&&f;i++){
            if(m[i][t1]!='.')f=0;
        }
        if(f)ans++;
    }
    if(m[s][t2]!='>'){
        ans++;
    }
    else if(m[s][t2]=='^'){
        bool f=1;
        for(i=1;i<s&&f;i++){
            if(m[i][t2]!='.')f=0;
        }
        if(f)ans++;
    }
    else if(m[s][t2]=='v'){
        bool f=1;
        for(i=s+1;i<r&&f;i++){
            if(m[i][t2]!='.')f=0;
        }
        if(f)ans++;
    }
    if(ans==0)return -1;
    return ans;
}

int judge3(int s){
    int i;
    int t=val[cnt];
    vis[t][s]=1;
    if(m[t][s]=='^'||m[s][t]=='v'){
        for(i=1;i<=c;i++){
            if(i!=s&&m[t][i]!='.')return 1;
        }
        return 0;
    }
    if(m[s][t]=='<'){
        for(i=1;i<=c;i++){
            if(i<s&&m[t][i]!='.')return -1;
            else if(i>s&&m[t][i]!='.')return 1;
        }
        return 0;
    }
    if(m[s][t]=='>'){
        for(i=c;i>=1;i--){
            if(i>s&&m[t][i]!='.')return -1;
            else if(i<s&&m[t][i]!='.')return 1;
        }
        return 0;
    }
}

int judge4(int s){
    int i;
    int t1=val[1],t2=val[cnt];
    vis[t1][s]=1;
    vis[t2][s]=1;
    int ans=0;
    if(m[s][t1]!='^'){
        ans++;
    }
    else if(m[s][t1]=='<'){
        bool f=1;
        for(i=1;i<s&&f;i++){
            if(m[t1][i]!='.')f=0;
        }
        if(f)ans++;
    }
    else if(m[s][t1]=='>'){
        bool f=1;
        for(i=s+1;i<c&&f;i++){
            if(m[t1][i]!='.')f=0;
        }
        if(f)ans++;
    }
    if(m[s][t2]!='v'){
        ans++;
    }
    else if(m[s][t2]=='<'){
        bool f=1;
        for(i=1;i<s&&f;i++){
            if(m[t2][i]!='.')f=0;
        }
        if(f)ans++;
    }
    else if(m[s][t2]=='>'){
        bool f=1;
        for(i=s+1;i<c&&f;i++){
            if(m[t2][i]!='.')f=0;
        }
        if(f)ans++;
    }
    if(ans==0)return -1;
    return ans;
}

int main(){
    freopen("E://in.txt","r",stdin);
    freopen("E://out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int q=1;q<=T;q++){
        memset(vis,0,sizeof(vis));
        int i,j,ans=0;
        bool f=1;
        scanf("%d%d",&r,&c);
        for(i=1;i<=r;i++){
            scanf("%s",m[i]+1);
        }
        for(i=1;i<=r&&f;i++){
            cnt=0;
            for(j=1;j<=c;j++){
                if(m[i][j]!='.'){
                    val[++cnt]=j;
                }
            }
            if(cnt==0)continue;
            else if(cnt==1){
                if(vis[i][val[cnt]])continue;
                int p=judge1(i);
                if(p==0)f=0;
                else if(p==1)ans++;
            }
            else if(cnt>=2){
                int t1=val[1];
                int t2=val[cnt];
                int p;
                if(vis[i][t1]&&vis[i][t2])continue;
                else if(vis[i][t1]){
                    val[1]=val[cnt];
                    cnt=1;
                    p=judge1(i);
                }
                else if(vis[i][t2]){
                    cnt=1;
                    p=judge1(i);
                }
                else p=judge2(i);
                if(p==0)f=0;
                else if(p==1)ans++;
                else if(p==2)ans+=2;
            }
        }
       // printf("")
        for(i=1;i<=c&&f;i++){
            cnt=0;
            for(j=1;j<=r;j++){
                if(m[j][i]!='.'){
                    val[++cnt]=i;
                }
            }
            if(cnt==0)continue;
            else if(cnt==1){
                if(vis[j][i])continue;
                int p=judge3(i);
                if(p==0)f=0;
                else if(p==1)ans++;
            }
            else if(cnt>=2){
                int p;
                int t1=1,t2=val[cnt];
                if(vis[j][t1]&&vis[j][t2]){
                    continue;
                }
                else if(vis[j][t1]){
                    val[1]=val[cnt];
                    cnt=1;
                    p=judge3(i);
                }
                else if(vis[j][t2]){
                    cnt=1;
                    p=judge3(i);
                }
                else p=judge4(i);
                if(p==1)ans++;
                else if(p==2)ans+=2;
            }
        }
        printf("Case #%d: ",q);
        if(!f)printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
