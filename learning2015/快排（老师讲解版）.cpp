#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int PARTITION(int a[],int l,int r){
    int i=l,m=a[l],j=r,t;
    for(;;){
        for(i=i+1;a[i]<m;i++);
        for(j=j-1;a[j]>m;j--);
        if(i<j) {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        }
        else break;
    }
    a[l]=a[j];a[j]=m;
    return j;
}

void QuickSort(int a[],int p,int q){
    if(p<q){
        int j=PARTITION(a,p,q+1);
        QuickSort(a,p,j-1);
        QuickSort(a,j+1,q);
    }
    return;
}
/*
//Data swop function
void Swap(int &p,int &q)
{
     int temp = p;
       p=q;
       q=temp;
}

//Partition function
int Partition(int ArrayInput[],int nLow,int nHigh)
{
    int nTemp=ArrayInput[nHigh];
    int i = nLow, j=nLow-1;
       for(; i<nHigh; i++)
       {
              if( ArrayInput[i]<=nTemp )
              {
                     j++;
                     if(i !=j )
                     {
                           Swap(ArrayInput[i], ArrayInput[j]);
                    #include<stdio.h>
#include<stdlib.h>
#include<time.h>
 }
              }
       }

       Swap(ArrayInput[j+1],ArrayInput[nHigh]);

    return (j+1);
}

//Quick sort
void Quick_sort(int ArrayInput[],int nLow,int nHigh)
{
    if(nLow < nHigh)
    {
        int nIndex=Partition(ArrayInput , nLow, nHigh);
        Quick_sort(ArrayInput , nLow, nIndex-1);
        Quick_sort(ArrayInput , nIndex+1, nHigh);
    }
}
*/
int main(){
    srand(time(NULL));
    int a[50],i;
    bool f=0;
    for (i=0;i<50;i++) {a[i]=rand();printf("%d\t",a[i]);}
    printf("\n");
    QuickSort(a,0,49);
    for (i=0;i<50;i++) printf("%d\t",a[i]);
    printf("\n");
    for (i=0;i<49;i++) {
        if (a[i]>a[i+1])f=1;
    }
    if(f)printf("N");
    else printf("Y");
    return 0;
}




