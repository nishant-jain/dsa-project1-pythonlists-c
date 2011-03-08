#include<stdio.h>
#include<stdlib.h>
int num=0;

void display1(int list[])
{	int i;
	printf("elements are: \n[");
	for(i=0;i<num;i++)
		printf("%d  ",list[i]);
	printf("]");
//	printf("\n");
}

void append(int list[])
{	
	int x;
	printf("enter element to be appended");
	scanf("%d",&x);
	num+=1;
	list=realloc(list,sizeof(int)*(num));
	list[num-1]=x;	
	printf("%dNew list: \n",num);
	display1(list);
//	printf("\n");
}

void extend(int list[])
{
	char b[5],a[5];
	gets(a);
	printf("enter elements separated by a newline(enter 'a' when finished)");
	//fflush(stdout);
	//fflush(stdin);	//gets(a);
	//printf("first string %s",a);
	fgets(b, 5, stdin);
	
	while(strcmp(b,"a\n")!=0)
	{	
		//if(strcmp(b,"a")==0)
		//	break;
		list=realloc(list,sizeof(int)*(num+1));		
		list[num]=atoi(b);
		num+=1;
		fgets(b, 5, stdin);
	}
	printf("%dnew list :\n",num);
	display1(list);	
	printf("\n");
}

void insert(int list[])
{
	int i,	a,pos;
	printf("enter element to be inserted ");
	scanf("%d",&a);
	printf("enter position ");
	scanf("%d",&pos);
	num+=1;
	list=realloc(list,sizeof(int)*(num+1));
	for(i=num-1;i>pos;i--)
		list[i]=list[i-1];
	list[pos]=a;
	display1(list);
	
}

void remove1(int list[])
{
	int i,x,pos;
	int flag=0;
	printf("enter element to be removed");
	scanf("%d",&x);
	for(i=0;i<num;i++)
		if(x==list[i])
			{flag=1;pos=i; break;}
		else
			flag=0;
	if(flag==1)
		{
			for(i=pos;i<num-1;i++)        //check for correctness(last element)
				list[i]=list[i+1];
			num-=1;
			list=realloc(list,sizeof(int)*num);		
		}
	else
		printf("\nError!! element not in list");
	display1(list);
}

int pop(int list[],int x)
{	
	if(x<=num && x>=0)
	{	int i,ele;
		ele=list[x];
		for(i=x;i<num-1;i++)				//check for correctness(last element)
			list[i]=list[i+1];
		num-=1;
		list=realloc(list,sizeof(int)*num);
		return ele;
	}
	else
		return -1;
	
}

int index1(int list[],int n)
{	
	int i;
	for(i=0;i<num;i++)
		if(list[i]==n)
			return i;
	return -1;
}

int count(int list[],int n)
{
	int i,sum=0;
	for(i=0;i<num;i++)
		if(list[i]==n)
			sum+=1;
	return sum;
}

void reverse(int list[])                 //not correct
{
	int i,j,k;
	j=num-1;
	for(i=0;i<num/2;i++)
		{
			k=list[j];
			list[j]=list[i];
			list[i]=k;
			j--;
		}	
	display1(list);
}

void in_sort(int list[])
{	int i,temp,j;
	for(i=1; i<num; i++)
	{
		temp = list[i];
		j = i-1;
		while(temp<list[j] && j>=0)
		{
			list[j+1] = list[j];
			j = j-1;
		}
		list[j+1] = temp;
	}display1(list);
}


void main()
{

	char ch='y';
	int *list;
	int choice;
	char a[5];
	list=malloc(sizeof(int));
	printf("enter initial elements of list:(enter 'a' to stop entering letters)");
	gets(a);
	while(strcmp(a,"a")!=0)
	{	
		list=realloc(list,sizeof(int)*(num+1));	
		list[num]=atoi(a);
		num+=1;
		gets(a);
	}
	printf("%d elements added to list\n",num);	
	display1(list);
	//append(list);
	//extend(list);
	int n,ans;
	do{	
		printf("1.append\n2.extend\n3.insert\n4.remove\n5.pop\n6.index\n7.count\n8.sort\n9.reverse\n");
		printf("enter a choice");
		scanf("%d",&choice);
		switch(choice){
			case 1:append(list);break;
			case 2:extend(list);break;
			case 3:insert(list);break;
			case 4:remove1(list);break;
			case 5:{ 
				 printf("enter position of element to be popped :");
				 scanf("%d",&n);
				
				 if((ans=pop(list,n))==-1)
					printf("Index out of range\n");
				else
					printf("%d was popped.",ans);
				display1(list);
				break;
				}
			case 6: { printf("Enter value :");
				  scanf("%d",&n);
				  if((ans=index1(list,n))==-1)
					printf("Error!!No such element");
				  else
					printf("index is %d",ans);
				  break;
				}
			case 7 : { 
					printf("Enter value :");
				  	scanf("%d",&n);
					printf("%d appears %d times in the list",n,count(list,n)); 
					break;
				}
			case 8:in_sort(list);break;
			case 9:reverse(list);break;
			default:printf("enter a valid choice\n" );break;
			}
	getchar();
	printf("\nDo you want to continue?");
	scanf("%c",&ch);
	}while(ch=='y');
	
	free(list);

}

