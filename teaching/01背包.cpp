#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;       //��Ʒ����
const int maxm = 1005;      //������������������

//int dp[maxn][maxm];         //dp[i][j]��ʾ���������[i]����Ʒ��ÿ����Ʒ����ȡ��ȡ��ռ�� j ���������ܹ�װ������ֵ
int dp[maxm];
int n,m;
int v[maxn],w[maxn];        //ÿ����ʯ��w[i],��ֵv[i]

int main(){
    scanf("%d%d",&m,&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&w[i],&v[i]);
    int ans = 0;

    /*
    for(int i =  1 ; i <= n ; ++ i){        // ���ǵ�i����ʯ
        for(int j = 0 ; j <= m ; ++ j)dp[i][j] = dp[i-1][j];        //�������Ͽ�ʱ��������ʵ������Ҫ���ǵ�i����ʯ��ѡȡ����ô�ڿ������i-1����ʯ�Ļ����ϣ�����������ֵ��û�б仯
        for(int j = w[i] ; j <= m ; ++ j){                                 //���ѭ���ǿ��Ƿŵ�i����ʯ�ģ����ڷ���� i ����ʯ����������Ϊw[i],����ѭ����w[i]��ʼ
            dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);       //�����i����ʯ֮������Ϊj����ô��֮ǰ����Ϊj-w[i]�������ÿ�����i-1����ʯ���ﵽ j-w[i] ������dp[i-1][j-w[i]] ���ϵ� i ����Ʒ�ļ�ֵv[i]��������dp[i][j];
        }
    }
    for(int j = 0 ; j <= m ; ++ j)ans = max(ans,dp[n][j]);      //�˴���ʵ���Բ�ѭ��ȡ���ֵ�����ֵ��Ȼ��dp[n][m]��
    */

    for(int i =  1 ; i <= n ; ++ i){        // ���ǵ�i����ʯ
        for(int j = m ; j >= w[i] ; -- j){
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);       //�����i����ʯ֮������Ϊj����ô��֮ǰ����Ϊj-w[i]�������ÿ�����i-1����ʯ���ﵽ j-w[i] ������dp[i-1][j-w[i]] ���ϵ� i ����Ʒ�ļ�ֵv[i]��������dp[i][j];
        }
    }


    printf("%d\n",dp[m]);
    return 0;
}
