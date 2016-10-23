#include <stdlib.h>

truct stack
{
	int elem_num;
	Node p_top;
	Node p_position;
	Node p_bottom;
}STACK, *P_STACK;
 
typedef P_STACK Stack;
 
Stack stack_create()
{
	Stack stack = (Stack)malloc(sizeof(STACK));

	stack->elem_num = 0;
	stack->p_top = stack->p_position = stack->p_bottom = NULL;
	
	return stack;
}

Node stack_push_node(Stack stack, Node node)
{
	
}
