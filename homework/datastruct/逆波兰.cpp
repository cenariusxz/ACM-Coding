#include<stdio.h>
#include<string.h>

const int maxstack=1005;

class Stack{
private:
	double stack[maxstack];
	int head;
public:
	Stack():head(0){}
	bool push(double x);
	bool empty()const{return !head;}
	int size()const{return head;}
	bool pop();
	double top();
	bool exchange();
	double getsum();
	double getave();
};

bool Stack::push(double x){
	if(head==maxstack){
		printf("Stack Overflow!\n");
		return 0;
	}
	stack[head++]=x;
	return 1;
}

bool Stack::pop(){
	if(head==0){
		printf("Stack is Empty!\n");
		return 0;
	}
	head--;
	return 1;
}

double Stack::top(){
	if(head==0){
		printf("Stack is Empty!\n");
		return 0;
	}
	return stack[head-1];
}

bool Stack::exchange(){
	if(head<2){
		printf("The elem in the stack is less than 2!\n");
		return 0;
	}
	double tmp=stack[head-1];
	stack[head-1]=stack[head-2];
	stack[head-2]=tmp;
}

double Stack::getsum(){
	double ans=0;
	for(int i=0;i<head;++i){
		ans+=stack[i];
	}
	return ans;
}

double Stack::getave(){
	return getsum()*1.0/head;
}

char tolower(char c){
	if(c>='A'&&c<='Z')return c-'A'+'a';
}

char get_command(){
	char str[10];
	char command;
	bool waiting=1;
	printf("Select command and press <Enter> :");
	while(waiting){
		scanf("%s",str);
		command=str[0];
		command=tolower(command);
		if(command=='?'||command=='='||command=='+'||command=='-'||command=='*'||command=='/'||command=='q'||command=='a'||command=='s'||command=='c'){
			waiting=0;
		}
		else{
			printf("Please enter a valid command:\n");
			printf("[?]push to stack [=]print top\n");
			printf("[+] [-] [*] [/] are arithmetic operations\n");
			printf("[A] to get average in the stack\n");
			printf("[S] to get sum in the stack\n");
			printf("[C] to exchange the top 2 elem in the stack\n");
			printf("[Q]uit.\n");
		}
	}
	return command;
}

bool do_command(char command,Stack &numbers){
	double p,q;
	switch(command){
	case '?':
		printf("Enter a real number:");
		scanf("%lf",&p);
		numbers.push(p);
		break;
	case '=':
		if(!numbers.empty()){
			p=numbers.top();
			printf("%lf\n",p);
		}
		else{
			printf("Stack is empty!\n");
		}
		break;
	case '+':
		if(numbers.size()<2){
			printf("The elem in the stack is less than 2!\n");
		}
		else{
			p=numbers.top();
			numbers.pop();
			q=numbers.top();
			numbers.pop();
			numbers.push(q+p);
		}
		break;
	case '-':
		if(numbers.size()<2){
			printf("The elem in the stack is less than 2!\n");
		}
		else{
			p=numbers.top();
			numbers.pop();
			q=numbers.top();
			numbers.pop();
			numbers.push(q-p);
		}
		break;
	case '*':
		if(numbers.size()<2){
			printf("The elem in the stack is less than 2!\n");
		}
		else{
			p=numbers.top();
			numbers.pop();
			q=numbers.top();
			numbers.pop();
			numbers.push(q*p);
		}
		break;
	case '/':
		if(numbers.size()<2){
			printf("The elem in the stack is less than 2!\n");
		}
		else{
			p=numbers.top();
			numbers.pop();
			q=numbers.top();
			numbers.pop();
			numbers.push(q/p);
		}
		break;
	case 'a':
		p=numbers.getave();
		printf("The average %lf\n",p);
		break;
	case 's':
		p=numbers.getsum();
		printf("The sum %lf\n",p);
		break;
	case 'c':
		numbers.exchange();
		break;
	case 'q':
		printf("Calculation finished.\n");
		return 0;
	}
	return 1;
}

int main(){
	Stack numstore;
	while(do_command(get_command(),numstore));
	return 0;
}