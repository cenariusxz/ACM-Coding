#include<stdio.h>
#include<string.h>
int main()
{
    long long a[21],i;
    a[1]=1;
    for(i=2;i<=20;i++) a[i]=(i-1)*a[i-1]+1;
    long long n,m;
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        long long b[21],k=m,l=n,t,s;
        memset(b,0,sizeof(b));
        for(;k>0;){
            t=(k-1)/a[l]+1;
            s=0;
            for (t;t>0;t--){
                s++;
                while (b[s]) s++;
            }
            b[s]=1;
            printf("%I64d",s);
            k=(k-1)%a[l];
            if (k==0) printf("\n");
            else printf(" ");
            l--;
        }
    }
    return 0;
}
