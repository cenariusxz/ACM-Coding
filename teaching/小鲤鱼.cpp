#include <stdio.h>

void me_fish(int t){
	if(t == 0){
		printf("�ҵ�С����");
		return;
	}
	printf("����");
	me_fish(t-1);
	printf("����");
}

int main(){
	printf("�ŵ��ұ�����");
	me_fish(3);
	printf("\n");
	return 0;
}
