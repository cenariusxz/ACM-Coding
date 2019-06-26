#include <bits/stdc++.h>
using namespace std;

struct node{
    int id,x;
    bool operator < (const node a)const{
        return x > a.x;
    }
}a[1005],b[1005];

bool cmp(node a,node b){
    return a.id<b.id;
}

int main(){
    int m,n,k,l,d;
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for(int i = 1 ; i <= m ; ++ i)a[i].id = i, a[i].x = 0;
    for(int i = 1 ; i <= n ; ++ i)b[i].id = i, b[i].x = 0;
    while(d--){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1 == x2)b[min(y1,y2)].x++;
        else a[min(x1,x2)].x++;
    }
    sort(a+1,a+m+1);
    sort(a+1,a+k+1,cmp);
    sort(b+1,b+n+1);
    sort(b+1,b+l+1,cmp);
    for(int i = 1 ; i <= k ; ++ i){
        printf("%d",a[i].id);
        if(i == k)printf("\n");
        else printf(" ");
    }
    for(int i = 1 ; i <= l ; ++ i){
        printf("%d",b[i].id);
        if(i == l)printf("\n");
        else printf(" ");
    }
    return 0;
}
