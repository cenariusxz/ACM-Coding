#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

char s[maxn];
char t[maxn];

int main(){
	scanf("%s", s);
	int len = 0, b = 0, posdot = 1, pose;
	
	// ȷ������ָ���ָ�λ�� 
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] == 'e')pose = i;
	}
	
	// ȷ����Ч��λ���ȡ�ĩβ������'0' 
	for(int i = 0 ; i < pose ; ++ i){
		if(s[i] != '.')t[++len] = s[i];
	}
	if(t[len] == '0')len --;
	for(int i = len + 1 ; i <= 205 ; ++ i)t[i] = '0';
	
	// ȷ��ָ�����ƶ�С���� 
	for(int i = pose+1 ; s[i] ; ++ i){
		b = b * 10 + s[i] - '0';
	}
	posdot += b;
	
	// ����������� 0~pos�������ǰ��0����¼����������֣����δ������֣������һ��'0' 
	int cnt = 0;
	for(int i = 1 ; i <= posdot ; ++ i){
		if(t[i] == '0' && cnt == 0)continue;
		cnt++;
		putchar(t[i]);
	}
	if(cnt == 0)putchar('0');
	
	// ���С���� ���len>pos���С���� 
	if(len > posdot)putchar('.');
	
	// ���С������ �������len>pos�����pos+1~len��������� 
	for(int i = posdot + 1 ; i <= len ; ++ i)putchar(t[i]);
	
	putchar('\n'); 
	return 0;
}

