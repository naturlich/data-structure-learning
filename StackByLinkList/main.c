#include <stdlib.h>
#include <stdio.h>

struct node_t;

typedef struct node_t {
	struct node_t *next;
	int data;
} node_t;

node_t *stack_push(node_t *stack, int data)
{
	node_t *new_node = NULL;

	new_node = malloc(sizeof(node_t));
	if (!new_node)
		return NULL;

	new_node->data = data;

	if (!stack) {
		new_node->next = NULL;
		return new_node;
	}

	new_node->next = stack;

	return new_node;
}

node_t *stack_pop(node_t *stack)
{
	node_t *next = NULL;

	if (!stack)
		return NULL;

	printf("stack: %d\n", stack->data);

	next = stack->next;
	free(stack);

	return next;
}

int main()
{
	node_t *stack = NULL;

	stack = stack_push(stack, 1);
	stack = stack_push(stack, 3);
	stack = stack_push(stack, 2);

	stack = stack_pop(stack);
	stack = stack_pop(stack);
	stack = stack_pop(stack);

	return 0;
}
