#include<stdio.h>
int bsrch(int a[],int n,int x)//a为正序数组，n为数组中数的个数，x为需要查找的数
{
    int low=0,high=n-1,mid;
    while (low<=high){
        mid=(low+high)/2;
        if(x==a[mid])return mid;
        if(low==high&&x!=a[mid])return -1;
        if(x<a[mid])high=mid;
        if(x>a[mid])low=mid+1;
    }
    return -1;
}

int main()
{
    int a[10]={1,2,5,8,11,13,14,15,20,22};
    int x,i;
    while(1){
        scanf("%d",&x);
        i=bsrch(a,10,x);
        printf("%d\n",i);
    }

    return 0;
}
