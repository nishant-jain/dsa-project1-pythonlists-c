#include<stdio.h>
#include<stdlib.h>
struct node
{
  int value;
  struct node *next;
} *front, *rear;
//struct node * front;
//struct node * rear;

void
display (struct node *f)
{
  printf ("\n");
  while (f != NULL)
    {
      printf (" %d-> ", f->value);
      f = f->next;
    }
  printf ("End\n");

}

/*

~~~~~list.append(x)
  

~~~~~~list.extend(L)
  

~~~~~list.insert(i, x)
  

~~~~~~list.remove(x)
  

~~~~~list.pop([i])
  
~~~~~~~~~~~~~list.index(x)
  

~~~~~list.count(x)

list.sort()


list.reverse()

*/



int
pop (struct node *f, int pos)	//if no input pos is given, then?? //check what happens to rear node if last node is removed in pop() and remove_node()
{
  int cur_pos = 0;
  struct node *pre;
  pre = malloc (sizeof (struct node));
  pre = f;
  while (cur_pos < pos)
    {
      pre = f;
      cur_pos++;
      f = f->next;
    }
  int k = f->value;
  pre->next = f->next;
  return k;

}

int
remove_node (struct node *f, int x)
{
  int found = -1;
  struct node *pre;
  pre = malloc (sizeof (struct node));
  pre = f;
  if (f->value == x)
    {
      found = 1;
      front = front->next;
      return found;
    }
  else
    while (f != NULL)
      {
	if (f->value == x)
	  {
	    found = 1;
	    pre->next = f->next;
	    break;
	  }
	else
	  {
	    pre = f;
	    f = f->next;
	  }
      }

  return found;


}

void
append (int x)
{

  struct node *newnode;
  newnode = malloc (sizeof (struct node));
  //printf("Enter value of new node ");
  //scanf("%d",&(newnode->value));
  //printf("\nnew value %d" ,newnode->value);
  newnode->value = x;
  newnode->next = NULL;
  if (front == NULL && rear == NULL)
    {
      front = newnode;
      rear = newnode;
    }
  else
    {
      rear->next = newnode;
      rear = newnode;

    }
}

int
extend (struct node *f)
{
  char str[5] = "";
  int no;
  printf ("Enter an element ");
  gets (str);

  while (strcmp (str, "a") != 0)
    {
      no = atoi (str);
      append (no);
      printf ("Enter an element ");
      gets (str);

    }
}

void
insert (int pos, int ele, struct node *f)
{
  int i;
  int cur_pos = 0;
  struct node *pre;
  pre = f;
  struct node *newnode;
  newnode = malloc (sizeof (struct node));
  pre = malloc (sizeof (struct node));
  newnode->value = ele;
//      printf("newnode value %d",newnode->value);
/*
	if(f!=NULL && rear!=NULL)
		{	if(pos==cur_pos)
				{pre->next=newnode;
					newnode->next=f;}	//insert a new node here
			else {
			cur_pos+=1;
			pre=f;
			f=f->next;}*/
  if (pos == 0)
    {
      newnode->next = f;
      front = newnode;
    }
  else
    {

      while (cur_pos < pos && f!=rear)
	{
	  pre = f;
	  f = f->next;
	  cur_pos++;
	}
      if (f != rear)
	{
	  //printf("previous node = %d,%d",pre->value,f->value);
	  printf ("f not equal to rear");
	  pre->next = newnode;
	  newnode->next = f;
	}
      else
	{
	  printf ("f equal to rear\n");
	  rear->next = newnode;
	  rear = newnode;
	}
    }
  display (front);
}


int
count (struct node *f, int ele)
{
  int counter = 0;
  while (f != NULL)
    {
      if (f->value == ele)
	{
	  f = f->next;
	  counter++;
	}
      else
	f = f->next;
    }
  return counter;
}


int
node_index (struct node *f, int x)
{
  int found = -1;
  int pos = 0;
  while (f != NULL)
    {
      if (f->value == x)
	{
	  found = pos;
	  break;
	}
      else
	{
	  pos++;
	  f = f->next;
	}

    }
  return found;
}

void reverse(struct node *f)
{
	
}



void
main ()
{
  front = rear = NULL;
  append (4);
  //display(front);
  append (5);
  //display(front);
  append (2);
  append (6);
  display (front);
  insert (4, 45, front);
  printf ("index of 3 %d", node_index (front, 45));
  printf ("count of 5 %d", count (front, 5));
/*	int k=remove_node(front,45);		
	display(front);	
	k=remove_node(front,0);*/
  //printf("popped elemnt %d",pop(front,2));
  display (front);
  extend (front);
  display (front);
}
