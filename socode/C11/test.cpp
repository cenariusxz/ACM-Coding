#include <bits/stdc++.h>
using namespace std;

int fa[1005];	// fa[i] ��ʾ i �ĸ��� 
// fa[i] == 0 ��ʾ i ������

int find(int x){	// �� x ������
	if( fa[x] == 0 ) return x ;	// x �Լ���������
	return find(fa[x]);	// �� x�ĸ��� ������ 
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; ++ i){
		int u,v;
		scanf("%d%d",&u,&v);
		fa[v] = u;
	}
	int a = find(1);
	int b = find(n);
	if(a == b)printf("Yes.\n");
	else printf("No.\n"); 

	return 0;
}
