#include <bits/stdc++.h> 
using namespace std;

int cnt[10005];			// cnt[i] ��ʾ���� i ���ֹ��Ĵ��� 

int main(){
	int n; 
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		int a;
		scanf("%d",&a);
		cnt[a] += 1;
	}
	for(int i = 0 ; i <= 10000; ++ i){
		if(cnt[i] == 0)continue;
		else printf("%d %d\n",i,cnt[i]);
	}
	return 0;
}
