#include<stdio.h>
#include<algorithm>
using namespace std;
int h[55];
int main(){
    int N,t=0;
    while(scanf("%d",&N)!=EOF&&N!=0){

        int sum=0,q;
        for(q=1;q<=N;q++){
            scanf("%d",&h[q]);
            sum+=h[q];
        }
        if(t++){printf("\n");}
        int ave=sum/N;
        sort(h+1,h+N+1);
        int t=0;
        for(q=N;h[q]>ave;q--)t+=(h[q]-ave);
        printf("%d\n",t);
    }
    return 0;
}
