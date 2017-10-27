#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX 30

//declaring the variables
//int base[MAX] = { 0 };	//the array
//int top = -1;			//top ptr
class_stack get_stack()
{
	class_stack new_stack;
	for (unsigned int counter = 0; counter < MAX; ++counter)
		new_stack.base[counter] = 0;
	new_stack.top = -1;
	return new_stack;
}

void push(class_stack * stack_this, int info)
{
	if (stack_this->top < MAX)		//limit check
	{
		++stack_this->top;			//new term
		stack_this->base[stack_this->top] = info;
	}
}

int pop(class_stack * stack_this)
{
	int popped = stack_this->base[stack_this->top];
	stack_this->base[stack_this->top] = 0;	//clearing
	--stack_this->top;			//one less a term
	return popped;
}

bool is_empty(class_stack * stack_this)
{
	if (stack_this->top == -1)
		return true;
	else
		return false;
}

bool is_full(class_stack * stack_this)
{
	if (stack_this->top = MAX - 1)
		return true;
	else
		return false;
}

void clear(class_stack * stack_this)
{
	//top to bottom clearance
	for (; stack_this->top >= 0; --stack_this->top)
		stack_this->base[stack_this->top] = 0;	
}

void peek(class_stack * stack_this)
{
	//top to bottom peeking...
	for (int counter = stack_this->top; counter >= 0; --counter)
		printf(" %c", stack_this->base[counter]);
	printf("\n");
}
