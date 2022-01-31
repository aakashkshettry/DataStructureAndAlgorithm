#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define max 5
int top=-1;
int stack[max];
void traverse();
void push();
void pop();
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
	if (top==max-1)
	{
		printf("Sorry the STACK is full...More elements cannot be pushed\n");
	}
	else
	{
		int num;
		printf("Which number do you want to want to push into stack??\n");
		scanf("%d",&num);
		top++;
		stack[top]=num;
	}
	
}

void traverse()
{
	int i;
	if (top==-1)
	{
		printf("Sorry the STACK is empty and No elements to display\n");
	}
	else
	{
		for(i=0;i<=top;i++)
		{
			printf("%d>>",stack[i]);
		}
		printf("\n");	
	}
}

void pop()
{
	if (top==-1)
	{
		printf("Sorry the STACK is empty and  elements cannot be popped out of stack\n");
	}
	else
	{
		printf("The popped element is  %d\n",stack[top]);
		top--;
	}
	
}
