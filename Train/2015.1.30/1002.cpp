#include<stdio.h>
#include<string.h>
int C[10001],Y[10001],F[10001];
int main(){
    int N,S;
    while (scanf("%d%d",&N,&S)!=EOF){
        int i,l,t;
        memset(F,0,sizeof(F));
        for(i=1;i<=N;i++)scanf("%d%d",&C[i],&Y[i]);
        long long sum=0,cost;
        for(i=1;i<=N;i++){
            if (!F[i]){
                t=i;
                sum+=C[i]*Y[i];
                cost=C[i]+S;
                while(cost<C[t+1]){
                    F[t+1]=1;
                    t++;
                    sum+=cost*Y[t];
                    cost+=S;
                }
            }
        }
        printf("%I64d\n",sum);
    }

}
