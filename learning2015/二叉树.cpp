//示例，C++
/*
#include<cstdio>
#include<cstring>
const int maxd=20;
int s[1<<maxd];
int main(){
    int D,I;
    while(scanf("%d%d",&D,&I)==2){
        memset(s,0,sizeof(s));
        int k,n=(1<<D)-1;
        for(int i=0;i<I;i++){
            k=1;
            for(;;){
                s[k]=!s[k];
                k=s[k]?k*2:k*2+1;
                if(k>n)break;
            }
        }
        printf("%d\n",k/2);
    }
    return 0;
}*/
//改用纯C
/*
#include<stdio.h>
#include<string.h>
#include<math.h>
#define Size 1024
bool s[Size];
int main(){
    int D,I;
    while(scanf("%d%d",&D,&I)==2){
        memset(s,0,sizeof(s));
        int k,n=pow(2,D)-1;
        for (int i=0;i<I;i++){
            k=1;
            for(;;)
            {
                s[k]=!s[k];
                k=s[k]?2*k:2*k+1;
                if(k>n)break;
            }
        }
        printf("%d\n",k/2);
    }
    return 0;
}
*/
//纯C，根据提示方案改进
#include<stdio.h>
#include<string.h>
int main(){
    int D,I;
    while(scanf("%d%d",&D,&I)==2){
        int k=1;
        for(int i=0;i<D-1;i++){
            if(I%2){k*=2;I=(I+1)/2;}
            else {k=k*2+1;I/=2;}
        }
        printf("%d\n",k);
    }
    return 0;
}
