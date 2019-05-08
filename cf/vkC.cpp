#include<stdio.h>
#include<string.h>
int aabs(int x){
	return x>=0?x:-x;
}

int mmin(int a,int b){
	return a<b?a:b;
}

int mmax(int a,int b){
	return a>b?a:b;
}

int main(){
	int x1,x2,y1,y2;
	while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF){
		int i,j;
		bool f=1;
		if((x1==1&&y1==0)||(x1==0&&y1==1))f=0;
		if(mmax(x2,y2)>=x1+y1)f=0;
		for(i=1;i<=mmin(x2,y2);i++){
			int p=aabs(x1-x2+i)+aabs(y1-y2+i);
			if(p<=i){
				f=0;
				break;
			}
		}
		if(!f)printf("Polycarp\n");
		else printf("Vasiliy\n");
	}
	return 0;
}
