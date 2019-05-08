#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int main(){
	int a1=40,a2=42,a3=44,a4=46,a5=48;
	priority_queue<int>q;
	q.push(a1);
	q.push(a2);
	q.push(a3);
	q.push(a4);
	q.push(a5);
	int a=q.top();
	q.pop();
	int b=q.top();
	q.pop();
	int t=0;
	while(a!=0&&b!=0){
		a--;
		b--;
		t++;
		q.push(a);
		q.push(b);
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
	}
	printf("%d\n",t);
}
