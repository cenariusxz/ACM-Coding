#include <bits/stdc++.h>
using namespace std;

int main(){
	int left = 1 , right = 100;
	while(true){
		if(left <= right){
			int mid = (left+right)/2;
			printf("�Ҳ��� %d\n", mid);
			char ans[5];
			scanf("%s",ans);
			if(ans[0] == '='){
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
		else{
			printf("��һ������ƭ�ң�\n");	
		}
	}
	return 0;	
}
