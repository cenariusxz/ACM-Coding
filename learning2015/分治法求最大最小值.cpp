#include<stdio.h>
int MMAX(int a[],int i,int j)//i,j为需要查找最大值的区间
{
    int gmax,hmax,g,h;
    if(i==j) return i;
    else if(i+1==j) return a[i]>=a[j]?i:j;
    else{
        g=(i+j)/2;
        h=g+1;
        gmax=MMAX(a,i,g);
        hmax=MMAX(a,h,j);
        return a[gmax]>=a[hmax]?gmax:hmax;
    }
}

int MMIN(int a[],int i,int j)
{
    int gmin,hmin,g,h;
    if(i==j) return i;
    else if(i+1==j) return a[i]<=a[j]?i:j;
    else{
        g=(i+j)/2;
        h=g+1;
        gmin=MMIN(a,i,g);
        hmin=MMIN(a,h,j);
        return a[gmin]<=a[hmin]?gmin:hmin;
    }
}

int main()
{
    int a[10]={248,425,156,31,48,65,14,165,486,123},i,j;
    i=MMAX(a,0,10);
    j=MMIN(a,0,10);
    printf("%d\t%d\n",i,j);
    return 0;
}
