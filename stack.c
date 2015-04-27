#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
//First in last out
int pop(Stack *stk){
	if(stk->top == NULL){
		printf("Stack Underflow\n");
		return -1;
	}else{
		int item = stk->top->val;
		Node *kill = stk->top;
		stk->top = stk->top->next; 
		free(kill);
		return item;
	}
}
int peek(Stack *stk){
	if(stk->top == NULL){
		printf("This stack is empty\n");
		return -1;
	}else{
		return stk->top->val;
	}
}
void insert(Stack *stk,int val){
	if(stk->top==NULL){
		//printf("first case\n");
		stk->top = (Node *)malloc(sizeof(Node));
		stk->top->val = val;
	}else{
		//printf("Second case\n");
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->val = val;
		temp->next = stk->top;
		stk->top = temp;
		
	}
}

void strReverse(char * str){
	Stack *stk = (Stack *)malloc(sizeof(Stack));
	int i;
	int len = strlen(str);
	printf("strlen %d\n",len );
	for(i=0;i<len;i++){
		insert(stk,str[i]);
	}
	for(i=0;i<len;i++){
		printf("%c",pop(stk) );
	}
	printf("\n");
}
int main(void){
	Stack *stk = (Stack *)malloc(sizeof(Stack));
	// stk->top = NULL;
	// insert(stk,1);
	// insert(stk,2);
	// insert(stk,3);
	// insert(stk,4);
	// insert(stk,5);
	// printf("Popped item is %d \n", pop(stk));
	// printf("Popped item is %d \n", pop(stk));
	char inp[50];
	printf("Enter your string\n");
	scanf("%s",inp);
	strReverse(inp);
}	
