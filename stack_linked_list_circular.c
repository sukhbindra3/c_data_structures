#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	node *next;
} node;

node *stack;

void initialize_stack();
int is_empty();
void push(int x);
void pop(int *px);
void show_stack();

int main() {
	int x, option;
	char ch;
	initialize_stack();
	printf("\tStack: Linear Linked List Implementation\n================================\n\n");
	do{
		printf("\n1. Push\n2. Pop\n3. Display stack\n\nEnter an option : ");
		scanf("%d", &option);
		switch(option) {
			case 1:	printf("\nEnter data: ");
					scanf("%d", &x);	
					push(x);
					break;
			case 2:	pop(&x);
					printf("\nPopped data: %d\n", x);
					break;
			case 3:	show_stack();
					break;
			default: printf("\nInvalid option!!\n");
		}
		printf("\nWant to continue? (y/n): ");
		fflush(stdin);
		scanf("%c",&ch);			
	}while(ch == 'y');
	return 0;
}

void initialize_stack(){
	stack=NULL;
}

int is_empty(){
	return (stack==NULL);
}

void push(int x){
	node *p=(node *)malloc(sizeof(node));
	p->data = x;
	if(is_empty())
		stack=p;
	else
		p->next = stack->next;
	stack->next = p;
}

void pop(int *px){
	if(is_empty()){
		printf("\nStack underflow ");
		return;
	}
	node *p = stack->next;
	*px = p->data;
	if(stack==p)
		stack=NULL;
	else
		stack->next = p->next;
	free(p);
}

void show_stack(){
	node *p=stack->next;
	do{
		printf(" %d",p->data);
		p = p->next;
	}while(p!=stack->next);
}
