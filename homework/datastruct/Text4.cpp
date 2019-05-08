#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int price1=10;
const int price2=5;
const int maxstack=2;
const int maxqueue=3;

struct car{
	int id,tin1,tin2;
	car(int num1=0,int num2=-1,int num3=-1):id(num1),tin1(num2),tin2(num3){}
};

class Stack{
	car s[maxstack];
	int rear;
public:
	Stack():rear(0){}
	bool empty()const{return rear==0;}
	bool full()const{return rear==maxstack;}
	int size()const{return rear;}
	void push(car x){s[rear++]=x;}
	car top(){return s[rear-1];}
	void pop(){rear--;}
	bool check(int id);
};

bool Stack::check(int id){
	for(int i=0;i<rear;++i){
		if(s[i].id==id)return 1;
	}
	return 0;
}

struct QNode{
	car data;
	QNode *nxt;
	QNode():nxt(NULL){}
	QNode(car x):nxt(NULL),data(x){}
};

class Queue{
	QNode *head,*rear;
	int count;
public:
	Queue():head(NULL),rear(NULL),count(0){};
	bool empty()const{return count==0;}
	bool full()const{return count==maxqueue;}
	int size()const{return count;}
	void push(car x);
	void pop();
	car front();
	bool check(int id);
};

void Queue::push(car x){
	QNode *tmp=new QNode;
	tmp->data=x;
	if(count==0){
		head=new QNode;
		head->nxt=tmp;
		rear=tmp;
	}
	else{
		rear->nxt=tmp;
		rear=tmp;
	}
	count++;
}

void Queue::pop(){
	QNode *tmp=head->nxt;
	if(count==1){
		head->nxt=rear=NULL;
	}
	else{
		head->nxt=tmp->nxt;
	}
	delete tmp;
	count--;
}

car Queue::front(){
	return head->nxt->data;
}

bool Queue::check(int id){
	if(count==0)return 0;
	QNode *tmp=head->nxt;
	while(tmp!=NULL){
		if(tmp->data.id==id)return 1;
	}
	return 0;
}

int main(){
	char com[10];
	int id,xx,yy;
	Stack s;
	Queue q;
	while(scanf("%s",com)!=EOF){
		if(com[0]=='e'||com[0]=='E')break;
		scanf("%d %d:%d",&id,&xx,&yy);
		if(com[0]=='A'||com[0]=='a'){
			if(!s.full()){
				car tmp(id,xx*60+yy);
				s.push(tmp);
				printf("Id:%d\nIn Stack no.%d\n\n",id,s.size());
			}
			else{
				car tmp(id,-1,xx*60+yy);
				q.push(tmp);
				printf("Id:%d\nIn Queue no.%d\n\n",id,q.size());
			}
		}
		else if(com[0]=='L'||com[0]=='l'){
			if(s.check(id)){
				Stack tmp;
				while(!s.empty()){
					car u=s.top();
					s.pop();
					if(u.id==id){
						int cost=(xx*60+yy-u.tin1)*price1,time1=xx*60+yy-u.tin1,time2=0;
						if(u.tin2!=-1){
							cost+=(u.tin1-u.tin2)*price2;
							time2=u.tin1-u.tin2;
						}
						printf("Id:%d\nCost:%d\nTime:%d mins in stack and %d mins in queue\n\n",id,cost,time1,time2);
						break;
					}
					else{
						tmp.push(u);
					}
				}
				while(!tmp.empty()){
					car u=tmp.top();
					tmp.pop();
					s.push(u);
				}
				while(!q.empty()&&!s.full()){
					car u=q.front();
					q.pop();
					u.tin1=xx*60+yy;
					s.push(u);
				}
			}
			else if(q.check(id)){
				Queue tmp;
				while(!q.empty()){
					car u=q.front();
					q.pop();
					tmp.push(u);
				}
				while(!tmp.empty()){
					car u=tmp.front();
					tmp.pop();
					if(u.id==id){
						int time1=0,time2=xx*60+yy-u.tin2;
						int cost=time2*price2;
						printf("Id:%d\nCost:%d\nTime:%d mins in stack and %d mins in queue\n\n",id,cost,time1,time2);
					}
					else q.push(u);
				}
			}
			else{
				printf("No such car!");
			}
		}
	}
	return 0;
}