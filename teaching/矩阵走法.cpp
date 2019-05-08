#include <bits/stdc++.h>
using namespace std;

// ��������
int xx[3] = {1,-1,0};
int yy[3] = {0,0,1};

int used[105][105];         //ĳ��������û���߹�


int dfs(int k,int x,int y){     //�Ѿ�����k������Ҫ����ʣ�²������߷�������
    if(k == 20)return 1;        //����20���ˣ�����ֻ��һ�����
    int sum = 0;
    for(int i = 0 ; i < 3 ; ++ i){
        int dx = x + xx[i];
        int dy = y + yy[i];
        //dx,dy �Ǵ� x,y �� i ��������һ��֮���λ��
        //��ͨ��Ŀ��һ��˴�Ӧ�����ж��Ƿ���磬�������Ⲣ����Ҫ
        if(used[dx][dy])continue;           //�����������߹��ˣ���ô�Ͳ�������һ��
        used[dx][dy] = 1;                   //������һ�����������
        sum += dfs(k+1,dx,dy);          //�ߵ�k+1������������
        if(sum > 1000000000)printf("No\n");
        used[dx][dy] = 0;                   //���ݣ�����߹��ı��
    }
    return sum;                         //���صõ��Ĳ���
}

int main(){
    used[50][50] = 1;
    printf("%d\n",dfs(0,50,50));
    return 0;
}
