/*
 * =====================================================================================
 *
 *       Filename:  Calc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2017 07:21:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Usman (), uthmanhere@gmail.com
 *   Organization:  SEECS, NUST
 *
 * =====================================================================================
 */


#include "Calc.h"
#include <stdio.h>
#define MAX 30

class_stack set_expr_stack(char * expr)
{	
	class_stack inv_expr_stack = get_stack();
	for (unsigned int counter = 0; counter < MAX; ++counter)
		push(&inv_expr_stack, expr[counter]);
	class_stack expr_stack = get_stack();
	while (!is_empty(&inv_expr_stack))
	{
		push(&expr_stack, pop(&inv_expr_stack));
	}
	return expr_stack;
}

int evaluate_expr(class_stack expr_stack)
{
	class_stack num_stack = get_stack();
	class_stack op_stack = get_stack();

	char character = '\0';


	class_stack tmpOp_stack = get_stack();
	char test = '\0';
	
	int num1 = -1;
	int num2 = -2;

	char op = '\0';
	
	while (!is_empty(&expr_stack))
	{
		character = pop(&expr_stack);
		if (character >= '0' && character <= '9')
			push(&num_stack, character);
		else if (character == '+' || character == '-')
		{
			if (is_empty(&op_stack))
				push(&op_stack, character);
			else
			{
				test = pop(&op_stack);
				if (test == '*' || test == '/')
				{	
					while (test != '*' || test != '/')
					{
						push(&tmpOp_stack, test);
						if (is_empty(&op_stack))
							break;
						test = pop(&op_stack);
					}
					push(&op_stack, character);
					while (!is_empty(&tmpOp_stack))
					{
						push(&op_stack, pop(&tmpOp_stack));
					}
				}
				else
				{
					push(&op_stack, test);
					push(&op_stack, character);
				}
			}
		}
		else if (character == '*' || character == '/')
		{
			push(&op_stack, character);
		}
		else if (character == ')')
			push(&op_stack, character);
		else if (character == '(')
		{


			op = pop(&op_stack);
			while (op != ')')
			{

				num2 = pop(&num_stack);
				num1 = pop(&num_stack);
			
				push(&expr_stack, arithematic(num1, num2, op));
				
				op = pop(&op_stack);

			}
		}
	}

	while (!is_empty(&op_stack))
	{
		num2 = pop(&num_stack);
		num1 = pop(&num_stack);

		op = pop(&op_stack);

		push(&num_stack, arithematic(num1, num2, op));
	}


	return pop(&num_stack);
}

char arithematic(char num1, char num2, char op)
{
	int num_1 = num1 - '0';
	int num_2 = num2 - '0';
	int out = 0;
	switch (op)
	{
		case '+' :
			out = num_1 + num_2;
			break;
		case '-' :
			out = num_1 - num_2;
			break;
		case '*' :
			out = num_1 * num_2;
			break;
		case '/' :
			out = num_1 / num_2;
			break;
	}
	return out + '0';
}
