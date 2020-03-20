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

char s[maxn],t[maxm];    //sΪ��ƥ�䴮��tΪģ�崮
int p[maxn];    //��ƥ������

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
    	scanf("%s%s", t, s);    //������ַ������±�0��ʼ��
        int i,j = 0,ans=0;    // j = 0 ע�⣬ ans��¼�ַ������ִ���
        int n = strlen(s), m = strlen(t);    //����Ŀ������������ʵstrlen����������������ȴ�����������TLE�ķ���
        p[0] = p[1] = 0;    //��ʼ����ƥ������
        for(i = 1 ; i < m ; ++ i){    //��ƥ��
            while(j && t[i] != t[j])j = p[j];
            if(t[i] == t[j])++ j; 
            p[i+1] = j;
        }
        j = 0;            //ע�� j=0
        for(i = 0 ; i < n ; ++ i){    //��ƥ��
            while(j && s[i] != t[j])j = p[j];
            if(s[i] == t[j])++ j;
            if(j == m){
                ans++;        //�˴���¼���ִ�����ģ�崮�ڴ�ƥ�䴮�п��ص��������Ϊֱ��break��ʾ�Ƿ���ֹ�
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
