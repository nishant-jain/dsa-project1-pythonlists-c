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


int
pop (struct node *f, int pos)	//if no input pos is given, then?? //check what happens to rear node if last node is removed in pop() and remove_node()
{
  int cur_pos = 0;
  struct node *pre;
  pre = malloc (sizeof (struct node));
  pre = f;
  int k;
  if (pos == 0)
    {
      k = f->value;
      front = front->next;
    }
  else
    {
      while (cur_pos < pos && f != rear)
	{
	  pre = f;
	  cur_pos++;
	  f = f->next;
	}
      k = f->value;
      if (f == rear && cur_pos == pos)
	{
	  rear = pre;
	  rear->next = NULL;
	}
      else if (f != rear && cur_pos == pos)
	pre->next = f->next;
    }
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
	    if (f == rear)
	      {
		found = 1;
		rear = pre;
		rear->next = NULL;
		break;
	      }
	    else
	      {
		found = 1;
		pre->next = f->next;
		break;
	      }
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
  printf ("enter 'a' to stop entering elements\n Enter an element");
  getchar ();
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

      while (cur_pos < pos && f != rear)
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

void
reverse (struct node *f)
{
  struct node *a, *b, *c;
  rear = front;

  b = NULL;
  while (f != NULL)
    {
      a = b;
      b = f;
      f = f->next;
      b->next = a;
    }
  front = b;
  rear->next = NULL;
}



void
main ()
{
  char ch = 'n';
  int choice = 0;
  int num, pos;
  front = rear = NULL;

  char str[5] = "";
  int no;
  printf ("enter 'a' to stop entering elements\n Enter an element");
  gets (str);

  while (strcmp (str, "a") != 0)
    {
      no = atoi (str);
      append (no);
      printf ("Enter an element ");
      gets (str);

    }
  display (front);
  do
    {
      printf ("\nLinked list implementation\n");
      printf
	("\t1.append\n\t2.extend\n\t3.insert\n\t4.remove\n\t5.pop\n\t6.index\n\t7.count\n\t8.sort\n\t9.reverse\n\t10.display\n\t11.exit");
      printf ("\nEnter a choice \n:");

      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  {
	    printf ("enter a value to append ");
	    scanf ("%d", &num);
	    append (num);
	    display (front);
	    break;
	  }
	case 2:
	  extend (front);
	  display (front);
	  break;
	case 3:
	  {
	    printf ("enter a value and position separated by a comma");
	    scanf ("%d,%d", &num, &pos);
	    insert (pos, num, front);
	    display (front);
	    break;
	  }
	case 4:
	  {
	    printf ("enter a value to remove ");
	    scanf ("%d", &num);
	    remove_node (front, num);
	    display (front);
	    break;
	  }
	case 5:
	  {
	    printf ("enter the position ");
	    scanf ("%d", &pos);
	    printf ("pop function returned %d", pop (front, pos));
	    display (front);
	    break;
	  }
	case 6:
	  {
	    printf ("enter whose index is to be returned ");
	    scanf ("%d", &num);
	    if (node_index (front, num) == -1)
	      printf ("Error! element not found\n");
	    else
	      printf ("Index of %d is %d", num, node_index (front, num));
	    break;
	  }
	case 7:
	  {
	    printf ("enter a number ");
	    scanf ("%d", &num);
	    printf ("\n%d appears %d times", num, count (front, num));
	    break;
	  }
	case 8:
	  printf ("Sort function unavailable.");
	  break;		// couldn't figure out how to swap nodes properly
	case 9:
	  reverse (front);
	  display (front);
	  break;
	case 10:
	  display (front);
	  break;
	case 11:
	  exit (0);
	  break;
	default:
	  printf ("Enter a valid option\n");
	}


    }
  while (1 == 1);
}
