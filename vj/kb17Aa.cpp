// 有nxt数组版本。。
#include<cstdio>
#include<string.h>
#include<math.h>
#include<queue>
#include<algorithm>
#define N 500006
using namespace std;

char st[1000005];
char keyword[55];
int n,m;
int nxt[N][26],cnt[N],fail[N],pos;

int newnode()
{
    for(int i=0; i<26; i++) nxt[pos][i] = 0;
    fail[pos] = cnt[pos] = 0;
    return pos++;
}

void insert(char *s) //构造trie
{
    int i,p = 0;
    for(i=0; s[i]; i++)
    {
        int k = s[i] - 'a', &x = nxt[p][k];
        p = x?x : x = newnode();
    }
    cnt[p]++; // 位运算要用
}

void makenxt()  // 构造失败指针
{
    int i;
    queue<int>q;
    q.push(0);
    while(!q.empty())  // 这个代码为什么会这么强？
    {
        int u = q.front();
        cnt[u] += cnt[fail[u]];

        q.pop();
        for(i=0; i<26; i++)
        {
            int v = nxt[u][i];
            if(v == 0)
              nxt[u][i] = nxt[fail[u]][i]; // why? 缺少v, 求nxt
            else
              q.push(v);

            if(u && v)
            {
                fail[v]=nxt[fail[u]][i]; // 为什么只弄了一下? 如果没有会怎么样? 求fail
            }
        }
    }
}

int query(char *s)
{
    int ret = 0, idx, d = 0;
    for(int i=0; s[i]; i++)
    {
        idx = s[i] - 'a';
        d = nxt[d][idx];
        ret += cnt[d];
        cnt[d] = 0;
    }
    return ret;
}

int main()
{
    int cas;
    scanf("%d",&cas);

    while(cas--)
    {
        scanf("%d",&n);
        pos = 0, newnode();
        for(int i=0; i<n; i++)
        {
            scanf("%s",keyword);
            insert(keyword);
        }

        makenxt();
        scanf(" %s",st);
        printf("%d\n",query(st));
    }
}

