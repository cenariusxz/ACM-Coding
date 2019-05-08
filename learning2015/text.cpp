#include<stdio.h>
#include<string.h>
int main()
{
    int b[21];
    memset(b,0,sizeof(b));
    for(int i=0;i<=20;i++) printf("%d\t",b[i]);
    printf("\n");
    return 0;
}
