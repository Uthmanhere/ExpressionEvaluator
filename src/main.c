		
/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2017 05:34:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "Stack.h"
#include "Calc.h"

int main()
{
	class_stack the_stack = get_stack();

	for (unsigned int counter = 1; counter <= 20; ++counter)
		push(&the_stack, counter);
	peek(&the_stack);


	char * expr;
	size_t size = 30;
	printf("String: ");
	//scanf("%s", expr);
	getline(&expr, &size, stdin);

	class_stack expr_stack = get_stack();

	for (unsigned int counter = 0; expr[counter] != 0; ++counter)
		push(&expr_stack, expr[counter]);

	peek(&expr_stack);
	evaluate_expr(expr_stack);
	
}
