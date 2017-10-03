#include <stdio.h>

typedef struct node {
	int data;
	struct node *next;
}node;

node *stack;

void initStack();
int isEmpty();
void push(int);
void pop(int*);
void disp();

int main() {
	int x, option;
	initStack();
	printf("\tStack: Linear Linked List Implementation\n================================\n\n");
	do{
		printf("1. Push\n2. Pop\n3. Display stack\n\n");
		scanf("%d", &option);
		switch(option) {
			case 1:	printf("\nEnter data: ");
					scanf("%d", &x);	
					push(x);
					break;
			case 2:	pop(&x);
					printf("\nPopped data: %d\n", x);
					break;
			case 3:	disp();
					break;
			default: printf("\nInvalid option!!\n");
			
			printf("Want to continue? (y/n): ");			
		}
	}while(getchar() == 'y');
	return 0;
}

void initStack() {
	stack = NULL;
}

int isEmpty() {
	return (stack == NULL);
}

void push(int x) {
	
}
void pop(int *px) {
	
}
void disp() {
	
}
