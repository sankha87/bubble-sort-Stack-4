#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(int);
int pop();
void display();
void bubbleSort();
void main()
{
	int choice, num;
	while (1)
	{
		printf("\nEnter your choice \n");
		printf("1. Push \n");
		printf("2. Pop \n");
		printf("3. Display \n");
		printf("4. Bubble Sort \n");
		printf("5. Exit \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter a number to be inserted : ");
			scanf("%d", &num);
			push(num);
			break;
		case 2:
			num = pop();
			break;
		case 3:
			display();
			break;
		case 4:
			bubbleSort();
			break;
		case 5:
			exit(1);
		default:
			printf("\nInvalid choice");
		}
	}
}
void push(int element)
{
	if (top == MAX - 1)
	{
		printf("Stack Overflow \n");
		return;
	}
	top = top + 1;
	stack[top] = element;
}
int pop()
{
	int element;
	if (top == -1)
	{
		printf("Stack is empty \n");
		return -1;
	}
	element = stack[top];
	top = top - 1;
	printf("%d has been deleted \n", element);
	return element;
}
void display()
{
	if (top == -1)
	{
		printf("Stack is empty \n");
		return;
	}
	printf("\n\n");
	for (int i = top; i >= 0; i--)
		printf("%d\n", stack[i]);
}

void bubbleSort()
{
	int n = top + 1;

	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;

		for (int j = 0; j < n - i - 1; j++)
		{
			if (stack[j] > stack[j + 1])
			{
				int temp = stack[j];
				stack[j] = stack[j + 1];
				stack[j + 1] = temp;

				flag = 1;			// if swapping happens update flag to 1
			}
		}
		// if value of flag is zero after all the iterations of inner loop then break out
		if (flag == 0)
		{
			break;
		}
	}
}
