#include<stdio.h>

int main(){
    int N;
    int i,a[21];
    a[0]=0;
    for(i=1;i<=6;i++){
        a[i]=(15-i)*i/2;
    }
    for(i=7;i<=21;i++){
        a[i]=a[i-1]+8;
    }
    while(scanf("%d",&N)!=EOF){
        for(i=1;i<=N;i++){
            int L,SP,SO;
            scanf("%d%d%d",&L,&SP,&SO);
            if(a[L]>=SO-SP) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
