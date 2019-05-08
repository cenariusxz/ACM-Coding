#include<stdio.h>
#include<string.h>
#define elem char

const int maxqueue=2005;
elem str[2005];

class Queue{
	elem q[maxqueue];
	int head,rear;
	int count;
public:
	Queue():head(0),rear(0),count(0){}
	int size()const{return count;}
	bool empty()const{return count==0;}
	bool full()const{return count==maxqueue;}
	elem front(){return q[head];}
	void pop(){head=(head+1)%maxqueue;count--;}
	void push(elem x){q[rear]=x;rear=(rear+1)%maxqueue;count++;}
};

int main(){
	scanf("%s",str);
	bool f=0,eq=1,isR=0;
	int len=strlen(str);
	Queue q1;
	for(int i=0;i<len;++i){
		if(str[i]==':')f=1;
		else if(!f)q1.push(str[i]);
		else if(f){
			if(!q1.empty()){
				elem c=q1.front();
				q1.pop();
				if(str[i]!=c)eq=0;
			}
			else{
				isR=1;
				break;
			}
		}
	}
	if(!f)printf("N\n");
	else if(isR)printf("R\n");
	else if(!q1.empty())printf("L\n");
	else if(!eq)printf("D\n");
	else printf("S\n");
	return 0;
}