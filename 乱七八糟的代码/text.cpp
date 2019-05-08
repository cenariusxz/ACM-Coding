#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
char s[20][500];
int main(){
	srand(time(NULL));
	int f;
	while(1){
		printf("输入‘1’则手动输入选项进行随机选取\n输入‘2’则在1～n中随机选取\n输入‘0’结束运行\n");
		scanf("%d",&f);
		if(f==0)break;
		else if(f==1){
			int n;
			printf("请输入选项个数：");
			scanf("%d",&n);
			int i;
			printf("请依次输入选项：\n");
			for(i=0;i<n;i++){
				scanf("%s",s[i]);
			}
			int a=rand()%n;
			printf("您的选择：%s\n",s[a]);
		}
		else if(f==2){
			int n;
			printf("请输入随机范围n：");
			scanf("%d",&n);
			printf("您的选择：%d\n",rand()%n+1);
		}
		else continue;
		printf("\n");
	}
	return 0;
}
