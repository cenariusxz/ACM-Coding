#include<stdio.h>
int b[10];//该数组可以放入归并函数内，元素个数大于等于a数组
void MERGE(int a[],int low,int mid,int high){//归并函数，a为原数组，low、high、mid为最小最大中间下标
    int h=low,i=low,j=mid+1;
    while(h<=mid&&j<=high){
        if(a[h]<=a[j]) {
            b[i]=a[h];
            h++;
        }
        else {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if (h>mid) for(int k=j;k<=high;k++){
        b[i]=a[k];
        i++;
    }
    if (j>high) for(int k=h;k<=high;k++){
        b[i]=a[k];
        i++;
    }
    for (int k=low;k<=high;k++) a[k]=b[k];
    return;
}
void MERGESORT(int a[],int low,int high){//a为原数组，low、high为需要排序的最大最小下标
    int mid=(low+high)/2;
    if(low<high){
        MERGESORT(a,low,mid);
        MERGESORT(a,mid+1,high);
        MERGE(a,low,mid,high);
    }
    return;
}
int main(){
    int a[10]={1,3,6,4,9,1,5,3,2,4};
    int i;
    MERGESORT(a,0,9);
    for(i=0;i<=9;i++)printf("%d\t",a[i]);
    printf("\n");
    return 0;
}
