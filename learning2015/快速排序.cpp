#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void QuickSort(int l,int r,int a[]){
    if(l>=r)return;
    int i=l,j=r,m=a[(l+r)/2],t;
    while(i<j){
        while(a[i]<m)i++;
        while(a[j]>m)j--;
        if(i<=j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
    }
    if(l<j) QuickSort(l,j,a);
    if(i<r) QuickSort(i,r,a);
}

int main(){
    srand(time(NULL));
    int a[50],i;
    for (i=0;i<=49;i++) {a[i]=rand();printf("%d\t",a[i]);}
    printf("\n");
    QuickSort(0,49,a);
    for (i=0;i<50;i++) printf("%d\t",a[i]);
    printf("\n");
    return 0;
}
