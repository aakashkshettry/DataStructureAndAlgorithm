  #include<stdio.h>
#include<stdlib.h>
int a=0;
void addEnd();
void addBeg();
void addPos();
void displayfromBeg();
void displayfromEnd();
void delBeg();
void delEnd();
void delPos();

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *previous;
}node;
node *start=NULL,*current=NULL;  //global variables
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
		printf("Choose[8] to display from end\n");
		printf("Choose[9] to exit\n");
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
					addPos();
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
					delPos();
					break;
				}
			case 7:
				{
					displayfromBeg();
					break;	
				}
			case 8:
				{
					displayfromEnd();
					break;		
				}
			case 9:
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

void addEnd()
{
	int num;
	node *temp,*q;
	temp=(node*)malloc(sizeof(node*));
	printf("value of the node you want to enter?\n");
	scanf("%d",&num);
	temp->data=num;
	temp->next=NULL;
	current=temp;
	if (start==NULL)
	{
		start=temp;
		temp->previous=NULL;
		temp->next=NULL;
		a++;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;		
		}
		q->next=temp;
		temp->previous=q;
		a++;	
	}
}

void displayfromBeg()
{
	
	if (start==NULL)
	{
		printf("No elements to display\n");
	}
	else{
		node *q;
		q=start;
		while(q!=NULL)
		{
			printf("%d>>",q->data);
			q=q->next;
		}
		printf("\n");
		}
}

void displayfromEnd()
{
	node *r;
	if (start==NULL)
	{
		printf("No elements to display\n");
	}
	else	
	{
		r=current;
	while(r->previous!=NULL)
	{
		printf("%d>>",r->data);
		r=r->previous;
	}
		printf("%d>>",r->data);
	}
}

void addBeg()
{
	int num;
	node *temp,*q,*r;
	temp=(node*)malloc(sizeof(node*));
	printf("value of the node you want to enter?\n");
	scanf("%d",&num);
	temp->data=num;
	temp->next=NULL;
	if (start==NULL)
	{
		start=temp;
		temp->previous=NULL;
		current=start;
		a++;
	}
	else
	{
		q=start;
		temp->next=q;
		q->previous=temp;
		temp->previous=NULL;
		start=temp;
		a++;
	}	
}

void addPos()
{
	node *temp,*q;
	int i,num;
	int position;
	printf("Which position do you want to add node betwee 1 to %d??\n",a);
	scanf("%d",&position);
	q=start;
	{
		q=q->next;
	}
	temp=(node*)malloc(sizeof(node*));
	printf("value of the node you want to enter?\n");
	scanf("%d",&num);
	temp->data=num;
	temp->next=q->next;
	temp->previous=q;
	q->next->previous=temp;
	q->next=temp;
	a++;
}
 void delBeg()
{
	node *q;
	if (start==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if (start->previous==NULL && start->next==NULL)
	{
		start=NULL;
		a--;
	}
	else
	{
		q=start;
		start=q->next;
		q->next->previous=NULL;
		a--;
	}
}

void delEnd()
{
	node *q;
	if (start==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if (start->previous==NULL && start->next==NULL)
	{
		start=NULL;
		a--;
	}
	else
	{
		q=start;
		while(q->next->next!=NULL)
		{
			q=q->next;
		}
		q->next=NULL;
		current=q;
		a--;
	}
}

void delPos()
{
	node *q,*temp,*s;
	if (start==NULL)
	{
		printf("Nothing to delete\n");
	}
	else if (start->previous==NULL && start->next==NULL)
	{
		start=NULL;
		a--;
	}
	else
	{
		q=start;
		int position,i;
		printf("Which position do you want to delete the nodes betwee 1 and %d",a);
		scanf("%d",&position);
		for (i=2;i<position;i++)
		{
			q=q->next;
		}
		temp=q;
		q->next->next->previous=temp;
		q->next=temp->next->next;
		a--;
	}	
}
