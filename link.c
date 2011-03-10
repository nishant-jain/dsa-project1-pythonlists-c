#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
	}*front,*rear;
//struct node * front;
//struct node * rear;

void addbeg()
{

	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	printf("Enter value of new node ");
	scanf("%d",&(newnode->value));
	printf("\nnew value %d" ,newnode->value);
	newnode->next=NULL;	
	if(front==NULL && rear==NULL)
		{	
			front = newnode;
			rear = newnode;
		}
	else
		{
			rear->next=newnode;
			rear=newnode;
			
		}		
}

void display (struct node *f)
{
	
  while(f!=NULL)
    {
        printf(" %d ",f->value);
        f=f->next;
    }

}



void main()
{	front = rear=NULL;
	addbeg();
	//display(front);
	addbeg();
	//display(front);
	addbeg();
	display(front);
	
	
	
}

