#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
string s;
int dp[maxm];
int maxi=-1;
int main(){
    cin>>s;
    s=s+s;
//    cout<<s;
    int cnt=1;
    dp[0]=1;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]&&cnt<s.size()/2){
            dp[i]=dp[i-1]+1;
            cnt++;
        }
        else dp[i]=1;
        maxi=max(maxi,dp[i]);
    }
//    for(int i=0;i<200000;i++)maxi=max(maxi,dp[i]);
    cout<<maxi;
    return 0;
}
