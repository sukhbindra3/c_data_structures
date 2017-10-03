#include<stdio.h>
#define N 100

int n=0;

void insert(int A[],int x);
void build_heap(int A[]);
void del(int A[]);
void heapify(int A[],int i);
void heap_sort(int A[]);
void swap(int *p,int *q);
void display(int A[]);
void search(int A[],int x);

int main(){
	int m,option,i,x;
	char ch;
	printf("\n ==============\n PRIORITY QUEUE \n ==============");
	printf("\n\nEnter the number of element : ");
	scanf("%d",&m);
	int A[N];
	printf("\nEnter %d values : \n",m);
	for(i=1;i<=m;i++){
		scanf("%d",&A[i]);
		n++;
	}
	build_heap(A);
	do{
		printf("\n1.Insert \n2.Delete \n3.Search \n4.Heap sort \n5.Display \n\nSelect an option : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\nEnter the value : ");
				scanf("%d",&x);
				insert(A,x);
				break;
			case 2:
				del(A);
				break;
            case 3:
                printf("\nEnter an element to search : ");
                scanf("%d",&x);
                search(A,x);
                break;
			case 4:
			    m=n;
				heap_sort(A);
				n=m;
				break;
			case 5:
                display(A);
                break;
			default:
				printf("\nInvalid option!! ");
				break;
		}
		printf("\nWant to continue (y/n) : ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y');
}

void insert(int A[],int x){
	int p = ++n;
	while(p>1 && x>A[p/2]){
		A[p]=A[p/2];
		p=p/2;
	}
	A[p]=x;
}

void build_heap(int A[]){
	int i;
	for(i=n/2;i>0;i--)
		heapify(A,i);
}

void del(int A[]){
	A[1] = A[n];
	n--;
	heapify(A,1);
}

void heapify(int A[],int i){
	int max,x,left,right;
	x=A[i];
	while(2*i <= n){
		left = 2*i;
		right = left+1;
		if(right<=n && A[left]<A[right])
			max = right;
		else
			max = left;
		if(A[max]>x){
			A[i] = A[max];
			i = max;
		}
		else
			break;
	}
	A[i]=x;
}

void heap_sort(int A[]){
	while(n>0){
		swap(&A[1],&A[n]);
		n--;
		heapify(A,1);
	}
}


void swap(int *p,int *q){
	int r = *p;
	*p = *q;
	*q = r;
}

void display(int A[]){
	int i;
	printf("\nHeap is : ");
	for(i=1;i<=n;i++)
		printf(" %d",A[i]);
}

void search(int A[],int x){
    int i=1,m,left,right;
    while((2*i<=n) && A[i]!=x){
        left=i*2;
        right=left+1;
        if(right<=n)
			i = right;
		else
			i = left;
    }
    if(A[i]==x)
        printf("\nElement found ");
    else
        printf("\nElement not found");
}
