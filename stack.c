/*
数据结构 栈
*/
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	/* data */
	unsigned int size; //栈大小
	unsigned int top;  //栈顶下标
	int* stack;		   //数据
};

int put(struct Stack* stack, int value)
{
	if (stack->size < stack->top)  //top超出大小
	{
		return -1;
	}
	stack->stack[stack->top] = value;
	stack->top++;
	return 0;
}
int pop(struct Stack* stack)
{
	if (stack->top == 0)  //到达栈顶
	{
		return -1;
	}
	int data = stack->stack[stack->top-1]; //超出了的top减一回到原本的位置
	stack->top--;
	return data;
}

struct Stack* getStack(unsigned int length)
{
	static struct Stack* stack;
	stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->stack = (int*)malloc(sizeof(int) * (length + 1));
	stack->size = length;
	stack->top = 0;
	return stack;
}
int main()
{
	struct Stack* stack = getStack(3); 
	for (int i = 1; i < 4; i++) //输入1-4数字
	{
		put(stack, i);
	}
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", pop(stack));
	}
}