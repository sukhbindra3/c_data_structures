#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	node *left;
	int data;
	node *right;
} node;

int m,n;

node *bst_insert(node *q, int x);
node *bst_delete(node *q, int x);
node *get_node(int x);
node *bst_search(node *q, int x);
node *bst_min(node *q);
node *bst_max(node *q);
node *bst_successor(node *root, int x);
node *bst_predecessor(node *root, int x);
void traverse(node *q);
void preorder(node *q);
void inorder(node *q);
void postorder(node *q);
int height(node *q,int x);

int main(){
	int option, x;
	//char ch;
	node *root = NULL, *t = NULL;
	printf("\nBinary Search Tree\n==================\n");
	do {
		printf("\n1. Insert\n2. Delete\n3. Search\n4. Find minimum\n5. Find maximum\n6. Successor\n7. Predecessor\n8. Traverse \n9. Height of the node");
		printf("\n\nEnter an option: ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				printf("\nEnter data: ");
				scanf("%d", &x);
				root = bst_insert(root, x);
				printf("\nData successfully inserted.\n");
				break;
			case 2:
				printf("\nEnter data: ");
				scanf("%d", &x);
				root = bst_delete(root, x);
				printf("\nData successfully deleted.\n");
				break;
			case 3:
				printf("\nEnter data: ");
				scanf("%d", &x);
				if(bst_search(root, x))
					printf("\nData found.\n");
				else
					printf("\nData not found.\n");
				break;
			case 4:
				t = bst_min(root);
				if(t)
					printf("\nMinimum node = %d", t->data);
				else
					printf("\nEmpty Tree.\n");
				break;
			case 5:
				t = bst_max(root);
				if(t)
					printf("\nMaximum node = %d", t->data);
				else
					printf("\nEmpty Tree.\n");
				break;
			case 6:
				printf("\nEnter data: ");
				scanf("%d", &x);
				t = bst_successor(root, x);
				if(t)
					printf("\nSuccessor node = %d", t->data);
				else
					printf("\nSuccessor does not exist.\n");
				break;
			case 7:
			    printf("\nEnter data: ");
				scanf("%d", &x);
				t = bst_predecessor(root, x);
				if(t)
					printf("\nPredecessor node = %d", t->data);
				else
					printf("\nPredecessor does not exist.\n");
					break;
			case 8:
				traverse(root);
				break;
            case 9:
                m=0,n=0;
                printf("\nEnter the element : ");
                scanf("%d",&x);
                printf("\nHeight of the element in the tree is : %d",height(root,x));
                break;
			default:
				printf("\nInvalid input option!!\n");
				break;
		}
		printf("\nWant to continue? (y/n): ");
		fflush(stdin);
	} while(getchar() == 'y');
	return 0;
}

node *bst_insert(node *q,int x){
	if(q==NULL)
		q=get_node(x);
	else if(x<= q->data)
		q->left = bst_insert(q->left , x);
	else
		q->right = bst_insert(q->right , x);
	return q;
}

node *bst_delete(node *q,int x){
    if(q==NULL)
        return NULL;
    if(x < q->data)
        q->left = bst_delete(q->left , x);
    else if(x > q->data)
        q->right = bst_delete(q->right , x);
    else{
        node *t;
        if(!q->left){
            t=q;
            q = q->right;
            free(t);
        }
        else if(!q->right){
            t=q;
            q = q->left;
            free(t);
        }
        else{
            t = bst_min(q->right);
            q->data = t->data;
            q->right = bst_delete(q->right , t->data);
        }
    }
    return q;
}

node *get_node(int x){
	node *q=(node *)malloc(sizeof(node));
	q->data = x;
	q->left = q->right = NULL;
	return q;
}

node *bst_search(node *q, int x){
	if(q==NULL || q->data == x)
		return q;
	if(x < q->data)
		return bst_search(q->left , x);
	else
		return bst_search(q->right , x);
}

node *bst_min(node *q){
	if(q==NULL)
		return NULL;
	if(q->left == NULL)
		return q;
	return bst_min(q->left);
}

node *bst_max(node *q){
	if(q==NULL)
		return NULL;
	if(q->right == NULL)
		return q;
	return bst_min(q->right);
}

node *bst_successor(node *root, int x){
	node *a=root;
	node *s=NULL;
	node *q;
	q=bst_search(root,x);
	if(q->right)
		return bst_min(q->right);
	else{
		while(q!=a){
            if(q->data < a->data){
                s=a;
                a = a->left;
            }
            else
                a = a->right;
        }
	}
	return s;
}

node *bst_predecessor(node *root, int x){
	node *a=root;
	node *s=NULL;
	node *q;
	q=bst_search(root,x);
	if(q->left)
        return bst_max(q->left);
	else{
	    while(q!=a){
            if(q->data > a->data){
                s=a;
                a = a->right;
            }
            else
                a = a->left;
		}
    }
	return s;
}

void traverse(node *q){
	printf("\n Pre-order  :");
	preorder(q);
	printf("\n In_order   :");
	inorder(q);
	printf("\n Post-order :");
	postorder(q);
}

void preorder(node *q){
	if(q==NULL)
		return ;
	printf("   %d",q->data);
	preorder(q->left);
	preorder(q->right);
}

void inorder(node *q){
	if(q==NULL)
		return ;
	inorder(q->left);
	printf("   %d",q->data);
	inorder(q->right);
}

void postorder(node *q){
	if(q==NULL)
		return ;
	postorder(q->left);
	postorder(q->right);
	printf("   %d",q->data);
}

int height(node *q,int x){
    if((q->right || q->left)==NULL)
        return 0;
    if(!q->left)
        return (height(q->right,x)+1);
    else if(!q->right)
        return (height(q->left,x)+1);
    else
        m = height(q->right,x)+1;
        n = height(q->left,x)+1;
        return (m>n)?m:n;
}

