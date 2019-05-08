#include<stdio.h>

int main(){
	FILE *fp;
	fp=fopen("C:\\MATLAB\\R2010b\\work\\b.text","r");
	if(!fp)
	{printf("can't open file\n");
	return -1;
	}/*
	while(!feof(fp))
	{int n=92,m=20;		//n个点，m个警卫点
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			fscanf(fp,"%lf",&D[i][j]);
			printf("%4d",D[i][j]);
		}
		printf("\n");
	}
		fclose(fp);
		return 0;
	}
	read();
	pre();
	solve();
	return 0;*/
}