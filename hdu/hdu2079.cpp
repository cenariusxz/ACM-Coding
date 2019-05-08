#include<stdio.h>
#include<string.h>
int c1[1000],c2[1000],a,b;

int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        int n,k;
        for(int q=1;q<=T;q++){
            scanf("%d%d",&n,&k);
            int i,j,p;
            memset(c1,0,sizeof(c1));
            c1[0]=1;int l=0;
            for(i=1;i<=k;i++){
                memset(c2,0,sizeof(c2));
                scanf("%d%d",&a,&b);
                for(j=0;j<=l;j++){
                    for(p=1;p<=b;p++){
                        c2[j+p*a]+=c1[j];
                    }
                }
                l+=a*b;
                for(j=0;j<=l;j++)c1[j]+=c2[j];
            }
            printf("%d\n",c1[n]);
        }

    }
    return 0;
}
