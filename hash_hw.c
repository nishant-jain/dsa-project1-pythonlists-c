#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct info{
	char name[20];
	char pass[20];
	};
struct info *hash;

//char hash[20][20];
int n=0;
float alpha=1;
int hash_size=0;
void findsize(void)
{	int i;
	char c;
	FILE *f;
	f=fopen("namefile.txt","r");
	for(i=0;(c=fgetc(f))!=EOF;i++)
		if(c=='\n')
			n++;		
	fclose(f);
}
		


int hash_insert(char k[],char l[])
{
	int i=0;
	int j;
	do{
		j=h(k,i);
		if(strcmp(hash[j].name,"")==0)
			{strcpy(hash[j].name,k);
			strcpy(hash[j].pass,l);
			return j;
				}
		else		
			i=i+1;
	}while(i<hash_size);
	printf("error!!! hash table overflow!");
	return -1;
}

/*int h(char k[], int i) //hash function #2
{
	int j,l,sum;
	sum=0;
	for(j=strlen(k)-1;j>=0;j--)
		sum+=(int)(pow(2,j)*((int)(k[j]))); //radix 2
	l=sum%hash_size;
	return ((l+i)%hash_size);  //linear probing-primary clustering problem

}*/
int h(char k[], int i) //hash function #3
{
	int j,l,sum;
	sum=0;
	sum=strlen(k)*((int)k[0]+(int)k[strlen(k)-1]); //strlen multiplied by ascii values of 1st and last character of string
		
	l=sum%hash_size;
	return ((l+i)%hash_size);  //linear probing-primary clustering problem

}/*
int h(char k[], int i)  //hash function #1
{
	int j,l,sum;
	sum=0;
	for(j=0;j<strlen(k);j++)
		sum=sum+(int)(k[j]); //addition of ascii values mod size of  hash table(high collision rate when userids are just permutations of each other)
	l=sum%hash_size;
	return ((l+i)%hash_size);  //linear probing-primary clustering problem

}*/

int hash_search_valid(char k[])  //for checking validity of username
{
	int i,j;
	i=0;
	do{
		j=h(k,i);
		if(strcmp(hash[j].name,k)==0) 
			//if(strcmp(hash[j].pass,l)==0)
				return j;
		
		i=i+1;
	}while((strcmp(hash[j].name,"")!=0)&&(i<hash_size));
	return -1;
}

int hash_search(char k[], char l[]) 
{
	int i,j;
	i=0;
	do{
		j=h(k,i);
		if(strcmp(hash[j].name,k)==0) 
			if(strcmp(hash[j].pass,l)==0)
				return j;
		
		i=i+1;
	}while((strcmp(hash[j].name,"")!=0)&&(i<hash_size));
	return -1;
}
	
void main()
{	int i,k;
	//printf("%d",(int)pow(2,3));
	findsize();
	printf("%d\n",n);
	hash_size=(int)(n/alpha);
	hash=calloc(hash_size,sizeof(struct info));
	printf("hash table size=%d\n",hash_size);
	char name[20],pass[20];
	FILE *f;
	f=fopen("namefile.txt","r");
	for(i=0;fscanf(f,"%s %s",name,pass)!= EOF;i++)
		hash_insert(name,pass);
	//for(i=0;i<hash_size;i++) //for displaying the hash table
	//	printf("%d %s %s\n",i,hash[i].name,hash[i].pass);
	printf("Enter username : ");
	scanf("%s",name);
	if(hash_search_valid(name)!=-1)
	{
		printf("valid userid\n");
		for(i=0;i<3;i++)
			{	printf("Enter password :");
				scanf("%s",pass);
				if(hash_search(name,pass)!=-1)
					{printf("Valid password\n");break;}
				else
					printf("Invalid password.Retry\n");
			}
		if(i==3)
			printf("too many tries, access is forbidden\n");
	}
	else
		printf("invalid userid\n");
	fclose(f);
	free(hash);
			
}


//nishant jain-2010058
