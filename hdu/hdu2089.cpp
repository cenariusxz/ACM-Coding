#include<stdio.h>
#include<string.h>
long long ans;
bool a[1000000];
void fun(){
    for(long long i=0;i<=1000000;i++){
        bool f1=0,f2=1;
        for(long long n=i;n>0;n/=10){
            int a=n%10;
            if((a==4)||(f1&&a==6)){
                f2=0;
                break;
            }
            else if(a==2){
                f1=1;
            }
            else if(f1||a!=6){
                f1=0;
            }
        }
        if(f2)a[i]=1;
    }

    return;
}
int main(){
    long long n,m;
    memset(a,0,sizeof(a));
    fun();
    while(scanf("%I64d%I64d",&n,&m)!=EOF&&(n!=0||m!=0)){
        ans=0;
        for(long long i=n;i<=m;i++){
            if(a[i])ans++;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
