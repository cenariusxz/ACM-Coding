#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;

int n,a[maxn];      //a��ԭ����
int dp[maxn];     //dp[i] ��ʾ�� a[i] Ϊ��β��LIS����

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    int ans = 0;
    for(int i = 1 ; i <= n ; ++ i){
        dp[i] = 1;      //��a[i]�Լ���Ϊһ�����У�Ҳ�����������У�����LIS���ȳ�ʼΪ1
        for(int j = 1 ; j < i ; ++ j){
            if(a[j] >= a[i])continue;           //���a[j] >= a[i]����ô���Ͳ�������a[i]Ϊ��β��������������a[i]ǰ��
            dp[i] = max(dp[i], dp[j]+1);    //��a[j]��Ϊ�����ڶ��������һ����a[i]����ô����Ⱦ�����a[j]Ϊ��β��LIS�����ټ�1����dp[j]+1
        }
        ans = max(ans,dp[i]);               //�LIS��Ȼ��ĳ��a[i]Ϊ��β�����Զ�������dp[i]ȡ�����ֵ��������ԭ���е�LIS
    }
    printf("%d\n",ans);
    return 0;
}
