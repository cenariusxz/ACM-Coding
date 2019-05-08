#include <bits/stdc++.h>
using namespace std;

int n,r;                //要求输出1~n中取r个数的排列
int sum = 0;            //记录总排列数
int a[25],used[25];     //同样a数组表示第几个数放几，used表示某个数是否使用过

void print(){                       //输出当前搜索出来的排列
    for(int i = 1 ; i <= r ; ++ i){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void dfs(int k){                    //表示已经放好前 k 个数了，即a[1]到a[k]
    if(k == r){                      //r个数已经全部填完
        print();                        //输出这种排列
        sum++;
        return;                     //不需要继续摆放数了
    }
    for(int i = 1 ; i <= n ; ++ i){        //枚举排列中第k+1个要放几
        if(used[i])continue;                    //如果之前k个数里用过i了，那就不能再用了
        a[k+1] = i;                 //把i填在第k+1个位置
        used[i] = 1;                //标记下i被用过了
        dfs(k+1);                   //填完 k+1个数了，继续搜索
        used[i] = 0;                //回溯，把i标记清空，变成没有用过的状态
    }
}

int main(){
    scanf("%d%d",&n,&r);
    dfs(0);     //一个数都没有填过，开始搜索
    printf("%d\n",sum);
    return 0;
}
