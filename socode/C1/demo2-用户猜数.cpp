#include <bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));		// ��������ֵĳ�ʼ�� 
	int MAX = 100;		// ������������Χ 
	int ans = rand() % MAX + 1;	// �������һ��1��MAX֮������� 
	printf("����һ�� 1 �� %d ֮������������²��Ƕ��٣�\n", MAX);	// �����ʾ 
	while(true){	// û�н���������ѭ�� 
		int a;
		scanf("%d", &a);	// ����һ������������a 
		if( a < ans ){		// ������������ʹ𰸵Ĵ�С��ϵ����Ҫִ�еķ�֧ 
			printf("��С�ˣ��ٲ£�\n");
		}
		else if( a == ans ){
			printf("��ϲ�㣬�����ˣ�\n");
			break; 		// �ڲ���ʱ����ѭ�� 
		}
		else{
			printf("�´��ˣ��ٲ£�\n");	
		}
	}
	return 0;
}
