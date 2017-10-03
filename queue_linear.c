#include<stdio.h>

#define N 10

typedef struct queue{
    int item[N];
    int front;
    int rear;
} queue;

queue q;

void initialize_queue();
int is_empty();
void enqueue(int x,int *povf);
void dequeue(int *px,int *punf);
void show_queue();

void main(){
    initialize_queue();
    int option,x,ovf=0,unf=0;
    char ch;
    do{
        printf("\n1.Enqueue \n2.Dequeue \n3.Display the queue \n");
        printf("\nChoose an option : ");
        scanf("%d",&option);
        switch(option){
            case 1: printf("\nEnter an element : ");
                    scanf("%d",&x);
                    enqueue(x,&ovf);
                    break ;
            case 2: dequeue(&x,&unf);
                    printf("\nDequeued element is : %d",x);
                    break;
            case 3: show_queue();
                    break;
	    default: printf("\nInvalid option!!\n");
        }
        printf("\nwant to continue (y/n) : ");
        fflush(stdin);
        scanf("%c",&ch);
    }
    while(ch=='y');
}

void initialize_queue(){
    q.front=0;
    q.rear=-1;
}

int is_empty(){
    return (q.rear<q.front);
}

void enqueue(int x,int *povf){
    if(q.rear==N-1){
        printf("\nQueue overflow");
        *povf=1;
        return ;
    }
    *povf=0;
    q.item[++(q.rear)] = x;
}

void dequeue(int *px,int *punf){
    int i;
    if(is_empty()){
        printf("\nQueue underflow");
        *punf=1;
        return ;
    }
    *punf=0;
    *px = q.item[q.front];
    for(i=0;i<q.rear;i++)
        q.item[i]=q.item[i+1];
    q.rear=q.rear-1;
}

void show_queue(){
    int i;
    printf("\nThe linear queue is : ");
    for(i=q.front ; i<=q.rear ; i++)
        printf(" %d",q.item[i]);
    printf("\n");
}
