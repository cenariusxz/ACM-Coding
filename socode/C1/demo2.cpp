#include <bits/stdc++.h>
using namespace std;

int main(){
	int MAX = 100;
	int ans = rand()%MAX + 1;
	printf("����һ�� 1 �� %d ֮������������²��Ƕ��٣�\n", MAX);
	while(true){
		int a;
		scanf("%d", &a);
		if( a < ans ){
			printf("��С�ˣ��ٲ£�\n");
		}
		else if( a == ans ){
			printf("��ϲ�㣬�����ˣ�\n");
			break; 
		}
		else{
			printf("�´��ˣ��ٲ£�\n");	
		}
	}
	return 0;
}
