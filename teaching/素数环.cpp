#include <bits/stdc++.h>
using namespace std;

int sum = 0;            //记录总摆放种类数
int a[25],used[25];     //一般不习惯写used，会写成vis，不过为了更加容易理解，这里就写成used好了
//a 数组中，a[1]到a[20]表示一个环上20个数分别是几，used表示某个数是否被使用过

bool check_prime(int a){        //判断a是否是素数，复杂度O(根号a)，这里的a和外面的a数组不同，这里的a是传入的参数
    if(a == 1) return 0;            //1不是素数
    for(int i = 2 ; i * i <= a ; ++ i){     //在 2 到 根号a 之间找是否有数能整除 a
        if(a % i == 0)return 0;     //如果有数 i 能整除 a，说明a不是素数
    }
    return 1;                           // 没有数能整除 a ，则 a 是素数
}

void print(){                       //输出当前搜索出来的摆放方法
    for(int i = 1 ; i <= 20 ; ++ i){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void dfs(int k){                    //表示已经填好素数环上前 k 个数了，即a[1]到a[k]
    if(k == 20){                    //已经全部填完，但是还需要判断a[1]+a[20]是否是素数
        if(check_prime(a[1]+a[20]) == 1){        //a[1]+a[20]是素数，则可以输出这种摆放方法
            print();                    //此处你可以不输出这个方法，只看最后的种类数，因为种类数太多了23333
            sum++;
        }
        return;                     //不需要继续摆放数了
    }
    for(int i = 2 ; i <= 20 ; ++ i){        //枚举第k+1个要放几，不过因为规定了a[1]放1，所以这里不需要考虑1，从2开始循环
        if(used[i])continue;                    //如果之前k个数里用过i了，那就不能再用了
        if(check_prime(a[k] + i) == 0)continue;   //如果a[k]和i的和不是素数，那么不能把i放在a[k]旁边
        a[k+1] = i;                 //把i填在第k+1个位置
        used[i] = 1;                //标记下i被用过了
        dfs(k+1);                   //填完 k+1个数了，继续搜索
        used[i] = 0;                //回溯，把i标记清空，变成没有用过的状态
    }
}

int main(){
    //规定第一个数摆放1，并标记1为已经使用
    a[1] = 1;
    used[1] = 1;
    dfs(1);     //已经摆放了一个数，开始搜索
    printf("%d\n",sum);
    return 0;
}
