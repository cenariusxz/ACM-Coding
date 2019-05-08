#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c,d;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF){
        if(b*log2(a)==d*log2(c))printf("=\n");
        else if(b*log2(a)<d*log2(c))printf("<\n");
        else if(b*log2(a)>d*log2(c))printf(">\n");
    }
    return 0;
}
