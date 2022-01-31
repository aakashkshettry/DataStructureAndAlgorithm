#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct node *next;
}node;
node *start=NULL;
node *q,*temp;

int main()
{
	temp=(node*)malloc(sizeof(node*));
	printf("%d",temp);
	start=temp;
	printf("%d",start);
	return 0;
}






/*if (N%2!=0)
        {
            System.out.println("Weird");
        }
        if (N%2==0&&N>=2&&N<=5)
        {
            System.out.println("Not Weird");
        }
        if (N%2!=0&&N>=6&&N<=20)
        {
             System.out.println("Weird");
        }
        if (N%2==0&&N>20)
        {
            System.out.println("Not Weird");
        }

/*

