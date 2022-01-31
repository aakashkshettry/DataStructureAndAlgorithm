#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void traverse();
void push();
void pop();

typedef struct Stack
{
	int data;
	struct Stack *next;
}stack;
stack *top=NULL,*q,*temp,*r;

int main()
{
	
	char choice;
	while(1)
	{
		int option;
		printf("Choose[1] to push into the stack\n");
		printf("Choose[2] to pop out of stack\n");
		printf("Choose[3] to traverse the stack\n");
		printf("Choose[4] to exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				{
					push();
					break;
				}
			case 2:
				{
					pop();
					break;
				}
			case 3:
				{
					traverse();
					break;	
				}
			case 4:
				{
					exit(0);
				}
			default:
				{
					printf("Invalid input");
					break;
				}
			}
			printf("\n");
		}
}

void push()
{
	int num;
	temp=(stack*)malloc(sizeof(stack*));
	if (temp==NULL)
	{
		printf("Stack full\n");
	}	
	else
	{
		printf("Enter node");
		scanf("%d",&num);					
		temp->data=num;	
		if (top==NULL)
		{
			top=temp;
			temp->next=NULL;
		}			
		else
		{
			r=top;
			while(r->next!=NULL)
			{
				r=r->next;
			}
			r->next=temp;
			temp->next=NULL;
	}
	}
	
}

void pop()
{
	stack *ptr;
	ptr=top;
	if (top==NULL)
	{
		printf("Cannot be deleted");
	}
	else if (ptr->next==NULL)
	{
		free(ptr->next);
		top=NULL;
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


void traverse()
{
	if (top==NULL)
	{
		printf("No elements to display\n");
	}
	else{
	q=top;
	while(q!=NULL)
	{
		printf("%d>>",q->data);
		q=q->next;
	}
	printf("\n");
		}
}

