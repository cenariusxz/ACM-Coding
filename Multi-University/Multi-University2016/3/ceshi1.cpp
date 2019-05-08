#include<stdio.h>
#include<time.h>

int main(){
	int t1;
	t1=clock();
	for(int i=1;i<=2000000000;++i){
		i%1000000007;
	}
	printf("%lf\n",(clock()-t1)/1000000.0);
	t1=clock();
	for(int i=1;i<=2000000000;++i){
		i+1000000007;
	}
	printf("%lf\n",(clock()-t1)/1000000.0);
}
