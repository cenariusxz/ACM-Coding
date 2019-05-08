#include<cstdio>
#include<cstring>
int main(){
    int s,d;
    while(scanf("%d",&s)==1){
        d=4>>s;
        printf("%d\n",d);
    }
    return 0;
}

//程序中"<<"的意思是按位进，">>"是按位退，退到无数字就是0；
