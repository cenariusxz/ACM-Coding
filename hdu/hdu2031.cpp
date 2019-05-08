#include<stdio.h>
void cmp(long long N,long long R);
int main()
{
    long long N,R;
    while(scanf("%I64d%I64d",&N,&R)!=EOF)
    {
        if (N<0)
        {
            printf("-");
            N=-N;
        }
        cmp(N,R);
        printf("\n");
    }
    return 0;
}

void cmp(long long N,long long R)
{
    char a[17]="0123456789ABCDEF";
    if (N>=R) cmp(N/R,R);
    printf("%c",a[N%R]);
}