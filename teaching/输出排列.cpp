#include <bits/stdc++.h>
using namespace std;

int n,r;                //Ҫ�����1~n��ȡr����������
int sum = 0;            //��¼��������
int a[25],used[25];     //ͬ��a�����ʾ�ڼ������ż���used��ʾĳ�����Ƿ�ʹ�ù�

void print(){                       //�����ǰ��������������
    for(int i = 1 ; i <= r ; ++ i){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void dfs(int k){                    //��ʾ�Ѿ��ź�ǰ k �����ˣ���a[1]��a[k]
    if(k == r){                      //r�����Ѿ�ȫ������
        print();                        //�����������
        sum++;
        return;                     //����Ҫ�����ڷ�����
    }
    for(int i = 1 ; i <= n ; ++ i){        //ö�������е�k+1��Ҫ�ż�
        if(used[i])continue;                    //���֮ǰk�������ù�i�ˣ��ǾͲ���������
        a[k+1] = i;                 //��i���ڵ�k+1��λ��
        used[i] = 1;                //�����i���ù���
        dfs(k+1);                   //���� k+1�����ˣ���������
        used[i] = 0;                //���ݣ���i�����գ����û���ù���״̬
    }
}

int main(){
    scanf("%d%d",&n,&r);
    dfs(0);     //һ������û���������ʼ����
    printf("%d\n",sum);
    return 0;
}
