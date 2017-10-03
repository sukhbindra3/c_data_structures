#include<stdio.h>
#include<string.h>
#define N 100

typedef struct stack{
	int top;
	char ch[N];
} stack;

int is_empty(stack *ps);
void push(char *pch,stack *ps,int *puvf);
int pop(char *pch,stack *ps,int *punf);

int main(){
	int unf=0,ovf=0;
	stack s;
	char ch[N],reverse[N];
	printf("\nEnter a string : ");
	gets(ch);
	int i=0;
	while(ch[i]){
		push(&ch[i],&s,&ovf);
		i++;
	}
	i=0;
	while(!is_empty(&s)){
		pop(&reverse[i],&s,&unf);
		i++;
	}
	printf("\nReverse string is : %s",reverse);
	if(strcmp(ch,reverse)==0)
		printf("\nPalindrome");
	else
		printf("\nNot palindrome");
	return 0;
}

int is_empty(stack *ps){
	if(ps->top == -1)
		return 1;
	else
		return 0;
}

void push(char *pch,stack *ps,int *povf){
	if(ps->top==N-1){
		printf("\nStack overflow ");
		*povf = 1;
		return;
	}
	*povf = 0;
	ps->ch[++(ps->top)]=*pch;
}

int pop(char *pch,stack *ps,int *punf){
	if(is_empty(&*ps)){
		printf("\nStack underflow");
		*punf = 1;
		return 1;
	}
	*punf = 0;
	*pch = ps->ch[ps->top--];
}


