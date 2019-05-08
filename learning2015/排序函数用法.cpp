#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

bool cmp(int x,int y){
    return x>y;//大于为倒序，小于或不加此函数为正序
}

int main(){
    using namespace std;
    srand(time(NULL));
    int a[50],i;
    for (i=0;i<50;i++) {a[i]=rand();printf("%d\t",a[i]);}
    printf("\n");
    sort(a,a+50,cmp);
    for (i=0;i<50;i++) printf("%d\t",a[i]);
    printf("\n");
    return 0;
}
