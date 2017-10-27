#ifndef __CALC_H
#define __CALC_H

#include "Stack.h"

class_stack set_expr_stack(char *);

int evaluate_expr(class_stack);
char arithematic(char, char, char);

#endif
