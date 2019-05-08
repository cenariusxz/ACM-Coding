#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

int n,a[maxn];      //a是原序列
int dp[maxn];     //dp[i] 表示以 a[i] 为结尾的LIS长度

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        dp[i] = 1;      //以a[i]自己作为一个序列，也是上升子序列，所以LIS长度初始为1
        for(int j = 1 ; j < i ; ++ j){
            if(a[j] >= a[i])continue;           //如果a[j] >= a[i]，那么它就不能在以a[i]为结尾的子序列中排在a[i]前面
            dp[i] = max(dp[i], dp[j]+1);    //把a[j]作为倒数第二个，最后一个放a[i]，那么最长长度就是以a[j]为结尾的LIS长度再加1，即dp[j]+1
        }
        ans = max(ans,dp[i]);               //最长LIS必然以某个a[i]为结尾，所以对于所有dp[i]取个最大值就是整个原序列的LIS
    }
    printf("%d\n",ans);
    return 0;
}
