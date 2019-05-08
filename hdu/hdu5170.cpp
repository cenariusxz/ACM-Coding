#include<stdio.h>
#include<math.h>

int main(){
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
        if(fabs(b*(double)log((double)a)-d*(double)log((double)c))<1e-10) printf("=\n");
        else if(b*(double)log((double)a)>d*(double)log((double)c)) printf(">\n");
        else if(b*(double)log((double)a)<d*(double)log((double)c)) printf("<\n");
    }
    return 0;
}
