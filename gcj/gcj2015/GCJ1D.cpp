#include<stdio.h>
#include<string.h>

int main(){
    freopen("D-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int q=1;q<=T;q++){
        int r,c,ans=0;
        scanf("%d%d",&r,&c);
        if(r==2){
            if(c==3)ans=2;
            if(c==4)ans=1;
            if(c==5)ans=1;
            if(c==6)ans=2;
        }
        if(r==3){
            ans=2;
        }
        if(r==4){
            if(c==3)ans=2;
            if(c==4)ans=0;
            if(c==5)ans=0;
            if(c==6)ans=2;
        }
        if(r==5){
            ans=1;
        }
        if(r==6){
            if(c==3)ans=1;
            if(c==4)ans=0;
            if(c==5)ans=0;
            if(c==6)ans=1;
        }
        printf("Case #%d: %d\n",q,ans);
    }
    return 0;
}
