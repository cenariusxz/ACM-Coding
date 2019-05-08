#include<bits/stdc++.h>
using namespace std;
bool b[21]={0};
int total=0,a[21]={0};
int search(int);                           //回溯过程
int print();                               //输出方案
bool pd(int,int);                          //判断素数

int print(){
    total++;
    printf("<%d>",total);
    for (int j=1;j<=20;j++){
        printf("%d ",a[j]);
    }
    printf("\n");
}
bool pd(int x,int y){
    int k=2,i=x+y;
    while(k<=sqrt(i)&&i%k!=0) k++;
    if (k>sqrt(i)) return 1;
    else return 0;
}

int search(int t){
    int i;
    for (i=1;i<=20;i++){		//有20个数可选
        if (pd(a[t-1],i)&&(!b[i])){
//判断与前一个数是否构成素数及该数是否可用
            a[t]=i;
            b[i]=1;
            if (t==20) { if (pd(a[20],a[1])) print();}
            else search(t+1);
            b[i]=0;
        }
    }
}

int main(){
    search(1);
    printf("%d\n",total);		//输出总方案数
}
