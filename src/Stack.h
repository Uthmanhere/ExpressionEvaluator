#ifndef __STACK_H
#define __STACK_H

#include <stdbool.h>
#include <stdlib.h>

#define MAX 30 

typedef struct stack
{
	int base[MAX];
	int top;
} class_stack;

class_stack get_stack();

//insert and extract
void push(class_stack *, int);
int pop(class_stack *);

//checks
bool is_empty(class_stack *);
bool is_full(class_stack *);

//clearance and peeking
void clear(class_stack *);
void peek(class_stack *);


#endif
