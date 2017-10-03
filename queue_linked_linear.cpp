#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	node *next;
} node;

typedef struct queue{
	node *front;
	node *rear;
} queue;

queue q;

void initialize_queue();
int is_empty();
void enqueue(int x);
void dequeue(int *px);
void show_queue();

int main(){
	initialize_queue();
	int option,x;
	char ch;
	printf("\n\t\t\t================================================== \n\t\t\tImplementation of queue using circular linked list \n\t\t\t==================================================");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\tSukhbindra Singh Rawat");
	do{
		printf("\n1.Enqueue \n2.Dequeue \n3.Display the queue");
		printf("\nEnter an option : ");
		scanf("%d",&option);
		switch(option){
			case 1: printf("\nEnter an element : ");
					scanf("%d",&x);
					enqueue(x);
					break;
			case 2:	dequeue(&x);
					printf("Dequeued element is : %d",x);
					break;
			case 3: show_queue();
					break;
			default: printf("\nInvalid option ");
		}
		printf("\nWant to continue (y/n) : ");
		fflush(stdin);
		scanf("%c",&ch);
	} while(ch=='y');
	return 0;
}

void initialize_queue(){
	q.front = q.rear = NULL;
}

int is_empty(){
	return (q.front==NULL);
}

void enqueue(int x){
	node *p=(node *)malloc(sizeof(node));
	p->data = x;
	p->next = NULL;
	if(q.rear==NULL)
		q.front=p;
	else
		(q.rear)->next=p;
	q.rear=p;
}

void dequeue(int *px){
	if(is_empty()){
		printf("\nQueue underflow");
		return ;
	}
	node *p=q.front;
	*px = p->data;
	q.front = p->next;
	if(q.front == NULL)
		q.rear=NULL;
	free(p);
}

void show_queue(){
	node *p=q.front;
	printf("\nLinear queue is : ");
	while(p!=NULL){
			printf(" %d",p->data);
			p=p->next;
	}
}
