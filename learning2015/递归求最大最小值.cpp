#include<stdio.h>
int mmax(int i,int n,int a[])
{
    int k,j;
    if (i<n)
    {
        j=mmax(i+1,n,a);
        if(a[i]>a[j])k=i;
        else k=j;
    }
    else k=n;
    return k;
}

int mmin(int i,int n,int a[])
{
    int k,j;
    if (i<n)
    {
        j=mmin(i+1,n,a);
        if(a[i]<a[j])k=i;
        else k=j;
    }
    else k=n;
    return k;
}

int main()
{
    int a[10]={1,2,6,3,5,89,4,68,156,45},tmax,tmin;
    tmax=mmax(0,9,a);
    tmin=mmin(0,9,a);
    printf("%d\t%d\n",tmax,tmin);
}
