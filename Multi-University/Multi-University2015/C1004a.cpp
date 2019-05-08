#include <iostream>
#include <memory.h>
#include <string.h>
using namespace std;

const int MAX = 64;

int T, N,m;
int pData[MAX][MAX];
char pMap[MAX][MAX];

bool Check(int x, int y, int s);
void Color(int x, int y, int s);

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            cin >> (pMap[i] + 1);
	m=strlen(pMap[i]+1);
            for(int j = 1; j <= m; j++)
            {
                if(pMap[i][j] == '.') { pData[i][j] = 0; }
                if(pMap[i][j] == 'R') { pData[i][j] = 1; }
                if(pMap[i][j] == 'B') { pData[i][j] = 1; }
                if(pMap[i][j] == 'G') { pData[i][j] = 2; }
            }
        }
        int ans = 0;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(pData[i][j] == 2)
                {
                    Color(i, j, 1);
                    Color(i, j, -1);
                    ans += 2;
                }
            }
        }
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(Check(i, j, 1)) { Color(i, j, 1); ans++; }
                if(Check(i, j, -1)) { Color(i, j, -1); ans++; }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

bool Check(int x, int y, int s)
{
    if(s == 1)
    {
        char dwTmp = pMap[x][y];
        int nTmp = min(x, y) - 1;
        x -= nTmp; y -= nTmp;
        while(x <= N && y <= m)
        {
            if(!pData[x][y] || (pMap[x][y] != dwTmp && pMap[x][y] != 'G')) { return false; }
            x++; y++;
        }
        return true;
    }
    else
    {
        char dwTmp = pMap[x][y];
        int nTmp = min(x, m - y + 1) - 1;
        x -= nTmp; y += nTmp;
        while(x <= N && y >= 1)
        {
            if(!pData[x][y] || (pMap[x][y] != dwTmp && pMap[x][y] != 'G')) { return false; }
            x++; y--;
        }
        return true;
    }
}

void Color(int x, int y, int s)
{
    if(s == 1)
    {
        int nTmp = min(x, y) - 1;
        int nx = x - nTmp, ny = y - nTmp;
        while(nx <= N && ny <= m)
        {
            pData[nx][ny]--;
            nx++; ny++;
        }
    }
    else
    {
        int nTmp = min(x, m - y + 1) - 1;
        int nx = x - nTmp, ny = y + nTmp;
        while(nx <= N && ny >= 1)
        {
            pData[nx][ny]--;
            nx++; ny--;
        }
    }
}
