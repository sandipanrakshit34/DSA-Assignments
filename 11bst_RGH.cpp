/*C program to construct BST and traverse the tree in InOrder PreOrder and PostOrder*/
# include <stdio.h>
# include<conio.h>
# include <stdlib.h>
 
typedef struct BST {
   int data;
   struct BST *lchild, *rchild;
} node;
 
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);

 
main() 
{
   int choice;
   char ans = 'N';
   int key;
   node *new_node, *root=NULL;
    
   printf("\nProgram For Binary Search Tree ");
   do {
      printf("\n1.Create/insert");
      printf("\n2.Recursive Traversals");
      printf("\n3.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &choice);
 
      switch (choice) 
	  {
      case 1: //insert node in a BS tree
         	do {
            new_node = (node *) malloc(sizeof(node));
   			new_node->lchild = NULL;
   			new_node->rchild = NULL;
			printf("\nEnter The Element ");
            scanf("%d", &new_node->data);
            if (root == NULL) /* Tree is not Created */
               root = new_node;
            else
               insert(root, new_node);
 
            printf("\nWant To enter More Nodes?(y/n)");
            ans = getch();
         } while (ans == 'y');
         break;
 
      
      case 2:
         if (root == NULL)
            printf("Tree Is Not Created");
         else 
		 {
            printf("\nThe Inorder display : ");
            inorder(root);
            printf("\nThe Preorder display : ");
            preorder(root);
            printf("\nThe Postorder display : ");
            postorder(root);
         }
         break;
      }
   } while (choice != 3);
}


void insert(node *root, node *new_node) 
{
   if (new_node->data < root->data) 
   {
      if (root->lchild == NULL)
         root->lchild = new_node;
      else
         insert(root->lchild, new_node);
   }

   if (new_node->data > root->data) 
   {
      if (root->rchild == NULL)
         root->rchild = new_node;
      else
         insert(root->rchild, new_node);
   }
}
/*  This function displays the tree in inorder fashion  */
void inorder(node *temp) 
{
   if (temp != NULL) 
   {
      inorder(temp->lchild);
      printf("%d\t", temp->data);
      inorder(temp->rchild);
   }
}
/*  This function displays the tree in preorder fashion  */
void preorder(node *temp) 
{
   if (temp != NULL) 
   {
      printf("%d\t", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}
 
/* This function displays the tree in postorder fashion  */
void postorder(node *temp) 
{
   if (temp != NULL) 
   {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d\t", temp->data);
   }
}
