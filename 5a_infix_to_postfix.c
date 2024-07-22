#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[20];
int top=-1;
void push(char x){
	stack[++top] = x;
}
int pop(){
	if(top == -1){
		return -1;
	}
	else{
		return stack[top--];
	}
}
int priority(char x){
//	if(x=='('){
//		return 0;
//	}
	if(x=='+' || x=='-'){
		return 1;
	}
	if(x=='*' || x=='/'){
		return 2;
	}
	if(x=='^'){
		return 3;
	}
	else{
		return 0;
	}
}

int main(){
	char exp[20];
	char *e,x;
	printf("Enter the expression: ");
	gets(exp);
	// printf("%s\n",exp);
	e=exp;
	while(*e != '\0'){
		if(isalnum(*e)){    // isalnum = alphanumeric character (like A,B,2,10)
		    printf("%c",*e);
		}
		else if(*e == '('){     // '(' is non alphanumeric character
		    push(*e);
		}
		else if(*e == ')'){
			while((x=pop())!='('){
				printf("%c",x);
			}
		}
		else {
			while(priority(stack[top])>=priority(*e)){
				x = pop();
				printf("%c",x);
			}
			push(*e);
		}
		e++;
	}
	while(top!=-1){
		x=pop();
		printf("%c",x);
	}
	return 0;
}