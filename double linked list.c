#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int ID;
    char name[10];
} student;

typedef struct node{
    student data;
    struct node *prev;
    struct node *next;
} node;

node *head;

void emptylist();
void insert_data(student *ps);
void insert_beg(student *ps);
void insert_end(student *ps);
void insert_position(student *ps,int n);
void delete_beg();
void delete_end();
void delete_position(int n);
void print_list();

void main(){
    int y,option,n;
    student s;
    emptylist();
    do{
        printf("\n1.Insert at beginning \n2.Insert at end \n3.Insert at any position \n4.Delete from beginning \n5.Delete from end \n6.Delete from any position \n7.Print the list");
        printf("\nChoose an option : ");
        scanf("%d",&option);
        switch(option){
            case 1:
                insert_data(&s);
                insert_beg(&s);
                break;
            case 2:
                insert_data(&s);
                insert_end(&s);
                break;
            case 3:
                printf("\nEnter the position : ");
                scanf("%d",&n);
                insert_data(&s);
                insert_position(&s,n);
                break;
            case 4:
                delete_beg();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                printf("\nEnter the position : ");
                scanf("%d",&n);
                delete_position(n);
                break;
            case 7:
                print_list();
                break;
            }
        printf("\nWant to continue (y=1,n=0)");
        scanf("%d",&y);
    }
    while(y==1);
}

void emptylist(){
    head = (node *)malloc(sizeof(node));
    head->next = NULL;
}

void insert_data(student *ps){
    printf("\nEnter id and name of student : ");
    scanf("%d%s",&ps->ID,ps->name);
}

void insert_beg(student *ps){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = *ps;
    newNode->prev = head;
    newNode->next = head->next;
    head->next = newNode;
    if(newNode->next)
        newNode->next->prev = newNode;
}

void insert_end(student *ps){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = *ps;
    newNode->next = NULL;
    node *q = head;
    while(q->next)
        q = q->next;
    q->next = newNode;
    newNode->prev = q;
}

void insert_position(student *ps,int n){
    int i;
    if(n<1 ||(head->next == NULL && n>1)){
        printf("\nInvalid statement");
        return ;
    }
    node *q = head;
    for(i=1; i<n && q->next; i++)
        q = q->next;
    
    if(i==n){
    	node *newNode = (node *)malloc(sizeof(node));
        newNode->data = *ps;
        newNode->prev = q;
        newNode->next = q->next;
        q->next = newNode;
        if(newNode->next)
        	newNode->next->prev = newNode;
    }
    else{
    	printf("\nInvalid statement");
        return ;
	}
}

void delete_beg(){
    if(head->next == NULL)
        return ;
    node *q = head->next;
    head->next = q->next;
    if(q->next)
        q->next->prev = head;
    free(q);
}

void delete_end(){
    if(head->next == NULL)
        return ;
	node *q = head;
    while(q->next->next)
        q = q->next;
    free(q->next);
    q->next = NULL;
}

void delete_position(int n){
    int i;
    if(n<1 || (head->next == NULL)){
    	printf("\nInvalid position");
        return ;
	}
        
    node *q = head;
    for(i=1;i<n && q->next;i++)
        q = q->next;
    if(i==n && q->next){
        node *p = q->next;
        q->next = p->next;
        if(p->next)
            p->next->prev = q;
        free(p);
    }
    else{
        printf("\nInvalid position");
        return ;
    }
}

void print_list(){
    node *q=head->next;
    while(q){
        printf("\n%d\t\t%s",q->data.ID,q->data.name);
        q = q->next;
    }
}
