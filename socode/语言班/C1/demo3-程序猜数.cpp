#include <bits/stdc++.h>
using namespace std;

int main(){
	int left = 1 , right = 100;		// �����ķ�Χ 
	while(true){
		if(left <= right){			// �ڻ���δ�ų�����ʱ���в��� 
			int mid = (left+right)/2;	// ���м��һ���� 
			printf("�Ҳ��� %d\n", mid);
			char ans[5];
			scanf("%s",ans);		// ������´��˵�ʱ������'>'����������е�ʱ������'=',�������С��ʱ������'<' 
			if(ans[0] == '='){		// �����û���������ѭ����������С�����ķ�Χ 
				printf("���п���\n");
				break;	
			}
			else if(ans[0] == '<'){
				left = mid + 1;
			}
			else{
				right = mid - 1;	
			}
		}
		else{		// ���������ų��˵���û�еõ���ȷ�𰸣���˵��ʹ������ʹ���� 
			printf("��һ������ƭ�ң�\n");	
		}
	}
	return 0;	
}
