#include<stdio.h>
#include<stdlib.h>
int a=0;
void addEnd();
void addBeg();
void addPos();
void display();
void displayPos();
void delBeg();
void delEnd();
void delPos();

typedef struct Node
{
	int data;
	struct Node *next;
}node;
node *start=NULL,*end=NULL,*q,*temp,*r;  //global variables
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
		printf("Choose[8] to display from specific position\n");
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
					display();
					break;	
				}
				case 8:
					{
						displayPos();
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
	temp=(node*)malloc(sizeof(node*));
	end=temp;	
	printf("Enter node");
	scanf("%d",&num);
	temp->data=num;	
	if (start==NULL)
	{
		start=temp;
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
		a++;
	}
}

void display()
{
	if (start==NULL)
	{
		printf("Nothing to display\n");
	}
	else{
	q=start;
	while(q->next!=start)
	{
		printf("%d>>",q->data);
		q=q->next;
	}
	printf("%d",q->data);
	printf("\n");
}
}

void displayPos()
{
	node *n;
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
	temp=(node*)malloc(sizeof(node*));
	end=temp;	
	printf("Enter node");
	scanf("%d",&num);
	temp->data=num;	
	if (start==NULL)
	{
		start=temp;
		temp->next=start;
		a++;
	}
	else
	{
		end=start;
		q=start;
		temp->next=start;
		start=temp;	
		while(q->next!=end)
		{
		q=q->next;	
		}
		q->next=start;
		a++;
	}			

}

void addPos(int p)
{
	int position;
	printf("Which position do you want to add the node?? between 1 and %d\n",a-1);
	scanf("%d",&position);
	int i,num;
	while(p>=2&&p<=a-1)
	{
	q=start;
	temp=(node*)malloc(sizeof(node*));
	printf("Add the node:\n");
	scanf("%d",&num);
	temp->data=num;
	for(i=2;i<p;i++)
	{
		q=q->next;	
	}	
	temp->next=q->next;
	q->next=temp;
	}
	a++;
}

void delBeg()
{
	node *s;
	if (start==NULL)
	{
		printf("No elements to delete\n");
	}
	else if (start->next==start)
	{
		start=NULL;
		a--;
	}
	else
	{
		q=start;
		s=start;
		start=q->next;
		while(q->next!=s)
		{
			q=q->next;
		}
		q->next=start;
		a--;
	}
}

void delEnd()
{
	if (start==NULL)
	{
		printf("No elements to delete\nw");
	}
	else if (start->next==start)
	{
		start=NULL;
		a--;
	}
	else
	{
		q=start;
		while(q->next->next!=start)
		{
			q=q->next;
		}
		q->next=start;
		a--;
	}
}

void delPos()
{
	if (start==NULL)
	{
		printf("No elements to delete\nw");
	}
	else if (start->next==start)
	{
		start=NULL;
		a--;
	}
	else
	{
	int pos,i;
	printf("position do you want to delete the object between 1 and %d ",a);
	scanf("%d",&pos);
	q=start;
	for (i=2;i<pos;i++)
	{
		q=q->next;		
	}	
	q->next=q->next->next;
	a--;
}
}






