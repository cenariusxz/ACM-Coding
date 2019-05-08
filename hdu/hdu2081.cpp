#include<stdio.h>

int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        for(int q=1;q<=N;q++){
            long long a;
            scanf("%I64d",&a);
            printf("6");
            long long b=a%100000;
            printf("%I64d\n",b);
        }
    }
    return 0;
}

/*int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        for(int q=1;q<=N;q++){
            char a[12];
            scanf("%s",a);
            printf("6");
            for(int i=6;i<=10;i++)printf("%c",a[i]);
            printf("\n");
            getchar();
        }
    }
    return 0;
}
*/
