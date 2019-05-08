#include<stdio.h>
#include<string.h>

long long c1[51],c2[51];

int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        for(int q=1;q<=N;q++){
            int i,j;
            memset(c1,0,sizeof(c1));
            c1[0]=1;
            for(i=1;i<=26;i++){
                memset(c2,0,sizeof(c2));
                int b;
                scanf("%d",&b);
                for(int p=1;p<=b;p++){
                    for(j=0;j+p*i<=50;j++){
                        c2[j+p*i]+=c1[j];
                    }
                }
                for(j=1;j<=50;j++)c1[j]+=c2[j];
            }
            long long ans=0;
            for(i=1;i<=50;i++) ans+=c1[i];
            printf("%d\n",ans);
        }
    }
    return 0;
}
