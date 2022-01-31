#include<stdio.h>
#include<stdlib.h>

void addBeg();
void display();
void addEnd();
void addPos();
void delBeg();
void delEnd();
void delPos();				

typedef struct Node
{
	int data;
	struct Node *next;
}node;

node *start=NULL,*q,*temp,*r;  

int main()
{
	char choice;
	while(1)
	{
		int option;
		printf("Choose[1] to add list in the begin \n");
		printf("Choose[2] to add list in the end\n");
		printf("Choose[3] to insert in required pos\n");
		printf("Choose[4] to delete list from the begin \n");
		printf("Choose[5] to delete list from the end \n");
		printf("Choose[6] to delete list from the pos \n");
		printf("Choose[7] to display\n"); 
		printf("Choose[8] to exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				{
					addBeg();
					break;
				}
			case 2:
				{
					addEnd();
					break;
				}
			case 3:
				{
					int position;
					printf("Which position do you want to add the node??\n");
					scanf("%d",&position);
					addPos(position);
					break;	
				}
			case 4:
				{
					delBeg();
					break;
				}
			case 5:
				{
					delEnd();
					break;
				}
			case 6:
				{
					int pos;
					printf("Which position do you want to add the node??\n");
					scanf("%d",&pos);
					delPos(pos);
					break;
				}
			case 7:
				{
					display();
					break;	
				}
			case 8:
				{
					exit(0);
				}
			default:
				{
					printf("Invalid input");
					break;
				}
			}
		}
}


void addBeg()
{
	int num;
	temp=(node*)malloc(sizeof(node*));	
	printf("Enter node");
	scanf("%d",&num);					
	temp->data=num;					
	

	if (start==NULL)
	{
		 temp->next=NULL;			
		 start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}
	
void display()
{
	if (start==NULL)
	{
		printf("No elements to display\n");
	}
	else{
	q=start;
	while(q!=NULL)
	{
		printf("%d>>",q->data);
		q=q->next;
	}
	printf("\n");
		}
}

void addEnd()
{
	int num;
	temp=(node*)malloc(sizeof(node*));	
	printf("Enter node");
	scanf("%d",&num);					
	temp->data=num;	
	if (start==NULL)
	{
		start=temp;
		temp->next=NULL;
	}			
	else
	{
		r=start;
		while(r->next!=NULL)
		{
			r=r->next;
		}
		r->next=temp;
		temp->next=NULL;
	}
}


void addPos(int p)
{
	int num,i;
	node *ptr,*a;
	ptr=start;
	temp=(node*)malloc(sizeof(node*));
	printf("enter the node");
	scanf("%d",&num);
	temp->data=num;
	if (p==1)
	{
		temp->next=start;
		a=start->next;
		start=temp;
			
	}
	else
	{
		for(i=2;i<p;i++)
			{
				ptr=ptr->next;	
			}
		a=ptr->next;
		ptr->next=temp;
		temp->next=a;
	}
}

void delBeg()
{
	node *ptr,*fNode;
	ptr=start;
	fNode=start;
	if (start==NULL)
	{
		printf("There is no element to delete\n");
	}
	else
	{
		ptr=ptr->next;
		start=ptr;
	}
}

void delEnd()
{
	node *ptr;
	ptr=start;
	if (start==NULL)
	{
		printf("No elements to delete");
	}
	else if (ptr->next==NULL)
	{
		free(ptr->next);
		start=NULL;
	}
	else
	{
		while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;	
		}
		ptr->next=NULL;
		free(ptr->next);
		}
}


void delPos(int n)
{
	int i;
	node *ptr,*ptr1;
	ptr=start;
	ptr1=ptr;
	if (start==NULL)
	{
		printf("No elements to delete\n");
	}
	if (n==1)
	{
		start=ptr->next;
		free(ptr);
	}
	for(i=2;i<n;i++)
	{
		ptr=ptr->next;		
	}
	for(i=2;i<=n;i++)
	{
		ptr1=ptr->next->next;
	}
	ptr->next=ptr1;	
}
