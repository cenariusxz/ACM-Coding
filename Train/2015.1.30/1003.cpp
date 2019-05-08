#include<stdio.h>
int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        int i,j,count=1,l,k;
        char a[2001],b[2001];
        for(i=1;i<=N;i++) {
            getchar();
            scanf("%c",&a[i]);
        }
        for(i=1,j=N;i<=j;count++){
            if(a[i]<a[j]){
                b[count]=a[i];
                i++;
            }
            else if(a[i]>a[j]){
                b[count]=a[j];
                j--;
            }
            else if(a[i]==a[j]){
                    l=i+1;k=j-1;
                    while (a[l]==a[k]&&l<=N&&k>=0)
                    {
                        l++;k--;
                        if(a[l]<a[k]){
                            b[count]=a[i];
                            i++;
                            break;
                        }
                        else if(a[k]<a[l]){
                            b[count]=a[j];
                            j--;
                            break;
                        }
                    }

                    if(a[i+1]<a[j]){
                        b[count]=a[i];
                        i++;
                    }
                    else if(a[i]>a[j-1]){
                        b[count]=a[j];
                        j--;
                    }
                    else{
                        for(l=i+1,k=j-1;l<=N,k>=0;l++,k--){
                            if(a[l]<a[k]){
                                b[count]=a[i];
                                i++;
                                break;
                            }
                            else if(a[k]<a[l]){
                                b[count]=a[j];
                                j--;
                                break;
                            }
                        }
                    }

            }
        }
        count=0;
        for(i=1;i<=N;i++){
            printf("%c",b[i]);
            count++;
            if(!count%80) printf("\n");
        }
        printf("\n");
    }
}
