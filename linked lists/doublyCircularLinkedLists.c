#include<stdio.h>
#include<stdlib.h>
int a=0;
void addEnd();
void addBeg();
void addPos();
void display();
void displayPos();
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
		printf("Choose[7] to display from beginning\n"); 
		printf("Choose[8] to display from end\n");
		printf("Choose[9] to display from specific position\n");
		printf("Choose[10] to exit\n");
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
					display();
					break;	
				}
			case 8:
				{
					displayfromEnd();
					break;
				}
				case 9:
					{
						displayPos();
						break;
					}
			case 10:
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
	node*temp,*q;
	temp=(node*)malloc(sizeof(node*));
	printf("Enter the node to be inserted\n ");
	scanf("%d",&num);
	temp->data=num;
	if (start==NULL)
	{
		start=temp;
		current=temp;
		temp->previous=NULL;
		temp->next=start;
		a++;
	}
	else
	{
		q=start;
		temp->next=start;
		while(q->next!=start)
		{
			q=q->next;
		}
		q->next=temp;
		temp->previous=q;
		a++;
		current=temp;
	}
}

void display()
{
	if (start==NULL)
	{
		printf("No elements to display\n");
	}
	else{
		node *q,*temp;
		q=start;
		while(q->next!=start)
		{
			printf("%d>>",q->data);
			q=q->next;
		}
		printf("%d>>",q->data);
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
		printf("\n");
	}
}

void displayPos()
{
	node *n,*q;
	int a,i;
	printf("From which position do you want to travese?\n");
	scanf("%d",&a);
	q=start;
	for (i=1;i<a;i++)
	{
		q=q->next;
	}
	n=q;
	while(q->next!=n)
	{
		printf("%d>>",q->data);
		q=q->next;	
	}
	printf("%d>>",q->data);
	
}


void addBeg()
{
	int num;
	node *temp,*q,*r;
	temp=(node*)malloc(sizeof(node*));
	printf("Enter the node to be inserted\n ");
	scanf("%d",&num);
	temp->data=num;
	if (start==NULL)
	{
		start=temp;
		q=temp;
		q->previous=NULL;
		q->next=start;
		current=temp;
		a++;	
	}	
	else
	{
		q=start;
		temp->next=q;
		temp->previous=NULL;
		q->previous=temp;
		start=temp;
		r=q;
		while(r->next!=q)
		{
			r=r->next;
		}
		r->next=start;
		a++;
	}
}


void addPos()
{
	int num,position,i;
	node *temp,*q,*r,*f;
	
	printf("Which position do you want to insert data between 1 and %d?\n",a);
	scanf("%d",&position);
	if (position>=2 && position<a)
	{
	temp=(node*)malloc(sizeof(node*));
	printf("Enter the node to be inserted\n ");
	scanf("%d",&num);
	temp->data=num;
	q=start;
		for (i=2;i<position;i++)
		{
			q=q->next;
		}
		f=q->next;   //nodes to be deleted
		temp->next=q->next;
		temp->previous=q;
		q->next->previous=temp;
		q->next=temp;
		a++;
	}
	else
	{
		printf("invalid choice\n");
	}
}


void delBeg()
{
	node *q,*f;
	q=start;
	if (start==NULL)
	{
		printf("no elements to delete \n");
	}
	else if (q->previous==NULL && q->next==start)
	{
		f=q;
		start=NULL;
		free(f);
		a--;
	}
	else
	{
		f=start;
		q=start;
		q->next->previous=NULL;
		start=f->next;
		q=start;
		while(q->next!=f)
		{
			q=q->next;
		}
		q->next=start;
		free(f);
		a--;
	}
}


void delEnd()
{
	node *q,*f;
	q=start;
	if (start==NULL)
	{
		printf("no elements to delete \n");
	}
	else if (q->previous==NULL && q->next==start)
	{
		f=q;
		start=NULL;
		free(f);
		a--;
	}
	else
	{
		while(q->next->next!=start)
		{
			q=q->next;
		}	
		f=q->next;
		q->next=start;
		free(f);
		a--;
	}	
}

void delPos()
{
	int position,i;
	node *f,*q,*r;
	q=start;
	r=start;
	printf("In which position do you want to delete the node between 1 to %d\n",a);
	scanf("%d",&position);
	if (position>=2 && position<a)
	{
		for (i=2;i<position;i++)
		{
			q=q->next;
		}
		for (i=1;i<=position;i++)
		{
			r=r->next;
		}
		q->next=r;
		r->previous=q;
		a--;
	}
	
	else
	{
		printf("invalid choice\n");
	}
	
		
}















