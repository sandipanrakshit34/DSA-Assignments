#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
	int data;
	struct bst *left;
	struct bst *right;
}bst;

struct bst *root=NULL,*newnode;
//::Inserting function::
void insert(bst *root, bst *newnode){
	if(newnode->data<root->data){
		if(root->left==NULL){
			root->left =newnode;
		}
		else{
			insert(root->left,newnode);
		}
	}
	
	if(newnode->data>root->data){
		if(root->right==NULL){
			root->right =newnode;
		}
		else{
			insert(root->right,newnode);
		}
	}
}
//::inorder traversal::
void inorder(bst * temp){
	if(temp!=NULL){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}
//::preorder traversal::
void preorder(bst * temp){
	if(temp!=NULL){
		printf("%d ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
//::postorder traversal::
void postorder(bst * temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
}
int main() {	
	int ch,i;
	while(1){
		printf("\n1.insert\n2.Inorder\n3.preorder\n4.postorder\n5.exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			newnode=(struct bst *)malloc(sizeof(struct bst));
			newnode->left=NULL;
			newnode->right=NULL;
			printf("Enter the data: ");
			scanf("%d",&newnode->data);
			if(root==NULL)
				root=newnode;
			else
				insert(root,newnode);
			break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Invalid Choice, Try again: ");
		}
	}
}