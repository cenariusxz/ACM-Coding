#include <stdio.h>
#include <string.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e5 + 5;

char s[maxn],t[maxm];    //s为待匹配串，t为模板串
int p[maxn];    //自匹配数组

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
    	scanf("%s%s", t, s);    //这个是字符串从下标0开始的
        int i,j = 0,ans=0;    // j = 0 注意， ans记录字符串出现次数
        int n = strlen(s), m = strlen(t);    //在题目中遇到过，其实strlen很慢，所以如果不先存起来可能有TLE的风险
        p[0] = p[1] = 0;    //初始化自匹配数组
        for(i = 1 ; i < m ; ++ i){    //自匹配
            while(j && t[i] != t[j])j = p[j];
            if(t[i] == t[j])++ j; 
            p[i+1] = j;
        }
        j = 0;            //注意 j=0
        for(i = 0 ; i < n ; ++ i){    //串匹配
            while(j && s[i] != t[j])j = p[j];
            if(s[i] == t[j])++ j;
            if(j == m){
                ans++;        //此处记录出现次数（模板串在待匹配串中可重叠），或改为直接break表示是否出现过
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
