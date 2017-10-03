#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int pos;
	node *next;
} node;

void create_list(node **plist);
void insert_end(node **plist,int x);
void find_survival(node *p);
int delete_after(node *p);

int main(){
	node *list=NULL;
	create_list(&list);
	find_survival(list);
	return 0;
}

void create_list(node **plist){
	int n,i;
	printf("\nEnter the number of soldiers :");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		insert_end(plist,i);
}

void insert_end(node **plist,int x){
	node *q=(node *)malloc(sizeof(node));
	q->pos = x;
	if(*plist == NULL)
		(*plist) = q;
	else
		q->next = (*plist)->next;
	(*plist)->next = q;
	(*plist) = q;
}

void find_survival(node *p){
	int n;
	while(p->next != p){
		p=p->next;
		n=delete_after(p);
	}
	printf("\nWinner is:%d",n);
}

int delete_after(node *p){
	int x;
	node *q;
	if(p==NULL || p->next == p)
		return 0;
	q = p->next;
	p->next = q->next;
	x=q->pos;
	free(q);
	return x;
}
