#include<stdio.h>
#include<string.h>
#define MAXN 65
long long b[MAXN][MAXN];
char s[MAXN];
int n,q=0;
void solve()
{
    int len = strlen(s);
    for(int i = 0; i < len; i ++)
    b[i][i] = 1;
    for(int i = 1; i < len; i ++)
        for(int j = 0; i+j < len; j ++)
        {
            long long t;
            if(s[j] != s[i+j]) 
            {
                if(i+j-1 < j+1) t = 0;
                else t = b[j+1][i+j-1];
                b[j][i+j] = b[j][i+j-1] + b[j+1][i+j] - t;
            }
            else
            {
                b[j][i+j] = b[j][i+j-1] + b[j+1][i+j] + 1;
            }
        }
    printf("Case #%d: %lld\n",++q,b[0][len-1]);
}
void input()
{
    while(~scanf("%d",&n))
    while(n --)
    {
        scanf("%s",s);
        solve();
    }
}
int main()
{
    input();
    return 0;
}
