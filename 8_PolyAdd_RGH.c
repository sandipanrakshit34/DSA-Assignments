//Addition of two polynomial using SLL
#include <stdio.h>
#include <malloc.h>
struct node
{
int coeff;
int exp;
struct node *next;
};
struct node *createpoly(struct node *);
void display(struct node *);
struct node *addpoly(struct node *,struct node *,struct node *);
struct node *addnode(struct node *,int,int);

int main()
{
  struct node *poly1=NULL, *poly2=NULL, *poly=NULL;
  printf("\nCreate first polynomial(Enter values of exponent in decending order):");
  poly1=createpoly(poly1);
  printf("\nCreate second polynomial(Enter values of exponent in decending order):");
  poly2=createpoly(poly2);
  printf("\nPrint polynomials:\n");
  printf(" \nCoefficient | Exponent ->\n");
  display(poly1);
  printf("\n");
  display(poly2);
  poly=addpoly(poly1,poly2,poly);
  printf("\n Print added polynomial:");
  printf(" \nCoefficient | Exponent ->\n");
  display(poly);
return 0;
}

struct node *createpoly(struct node *start)
  {
     struct node *newnode, *ptr;
     int coef,exponent;
     int x;
     
	 printf("Enter exponent = -1 to stop poly creation:\n");
     printf("Enter exponent : ");
     scanf("%d", &exponent);
     while(exponent!=-1)
	 {  
	    printf("\nEnter coefficient : ");
        scanf("%d", &coef);
      	newnode = (struct node*)malloc(sizeof(struct node));
		newnode -> coeff=coef;
		newnode -> exp=exponent;
		newnode -> next = NULL;
	  if(start==NULL)
	    start = newnode;
	  else
	  { 
	    ptr=start;
	   	while(ptr->next!=NULL)
		    ptr=ptr->next;
	   	ptr->next = newnode;
	  }
     
     printf("Enter exponent : ");
     scanf("%d", &exponent);
    };
return start;
}


void display(struct node *start)
{  struct node *ptr;
   ptr = start;
   if (ptr==NULL)
     printf("List is empty\n");
   else
	{
      while(ptr != NULL)
      {
       printf(" %d | %d -> ",ptr->coeff, ptr->exp);
       ptr = ptr -> next;
      }
    }
}

struct node *addpoly(struct node *p1,struct node *p2,struct node *p3)
{
    struct node *ptr1, *ptr2;
    int x;
    ptr1=p1;
    ptr2=p2;

    while(ptr1 !=NULL  && ptr2 !=NULL)
	{
	    if (ptr1->exp > ptr2->exp)
		{
		 p3=addnode(p3,ptr1->coeff,ptr1->exp);
		 ptr1=ptr1->next;
		}
    else
	    if (ptr2->exp > ptr1->exp)
		{
		 p3=addnode(p3,ptr2->coeff,ptr2->exp);
		 ptr2=ptr2->next;
		}
	else
		{
		 x= ptr1->coeff+ptr2->coeff ;
		 p3=addnode(p3,x,ptr1->exp);
		 ptr1=ptr1->next;
		 ptr2=ptr2->next;
		}
	}
 if (ptr2==NULL)
 {
  while (ptr1!=NULL)
  {
     p3=addnode(p3,ptr1->coeff,ptr1->exp);
	 ptr1=ptr1->next;
  }
 }

 if (ptr1==NULL)
 {
	while (ptr2!=NULL)
	  {
	    p3=addnode(p3,ptr2->coeff,ptr2->exp);
		ptr2=ptr2->next;
	  }
 }
return p3;
}

struct node *addnode(struct node *start, int co , int ex)
{
  struct node *ptr , *newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->next=NULL;
  newnode->exp=ex;
  newnode->coeff=co;
 if (start==NULL)
   start=newnode;
 else
 {
    ptr=start;
    while(ptr -> next != NULL)
	   ptr = ptr -> next;
    ptr -> next = newnode;
 }
return start;
}
