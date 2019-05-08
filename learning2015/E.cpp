#include<stdio.h>
#include<string.h>

int c[50002];

int lowbit(int x){
    return x&(-x);
}

int sum(int x){
    int cnt=0;
    while(x>0){
        cnt+=c[x];
        x-=lowbit(x);
    }
    return cnt;
}

void add(int x,int d,int n){
    while(x<=n){
        c[x]+=d;
        x+=lowbit(x);
    }
}

int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        memset(c,0,sizeof(c));
        for(int i=1;i<=T;i++){
            printf("Case %d:\n",i);
            int N;
            scanf("%d",&N);
            for(int j=1;j<=N;j++){
                int a0;
                scanf("%d",&a0);
                add(j,a0,N+1);
            }
            char a[10];
            while (1){
                scanf("%s",a);
                if(!strcmp(a,"Add")){
                    int m,n;
                    scanf("%d%d",&m,&n);
                    add(m,n,N+1);
                }
                if(!strcmp(a,"Sub")){
                    int m,n;
                    scanf("%d%d",&m,&n);
                    add(m,-n,N+1);
                }
                if(!strcmp(a,"Query")){
                    int m,n;
                    scanf("%d%d",&m,&n);
                    printf("%d\n",sum(n)-sum(m-1));
                }
                if(!strcmp(a,"End"))break;
            }
        }
    }
    return 0;
}
