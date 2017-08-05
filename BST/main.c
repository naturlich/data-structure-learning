#include <stdio.h>
#include <stdlib.h>

struct node_t;

typedef struct node_t {
	struct node_t *left;
	struct node_t *right;
	int val;
} node_t;

node_t *insert(node_t *node, int val)
{
	node_t *new_node = NULL;

	if (!node) {
		new_node = malloc(sizeof(node_t));
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->val = val;
		return new_node;
	}

	if (val < node->val) {
		node->left = insert(node->left, val);
	} else if (val > node->val) {
		node->right = insert(node->right, val);
	}

	return node;
}

void preorder_visit(node_t *node)
{
	if (!node)
		return;

	printf("val = %d\n", node->val);
	preorder_visit(node->left);
	preorder_visit(node->right);
}
	
void inorder_visit(node_t *node)
{
	if (!node)
		return;

	inorder_visit(node->left);
	printf("val = %d\n", node->val);
	inorder_visit(node->right);
}

void postorder_visit(node_t *node)
{
	if (!node)
		return;

	printf("val = %d\n", node->val);
	postorder_visit(node->left);
	postorder_visit(node->right);
}

node_t *find_max(node_t *node)
{
	if (!node->right)
		return node;

	return find_max(node->right);
} 

node_t *find_min(node_t *node)
{
	if (!node->left)
		return node;

	return find_min(node->left);
}

node_t *find(node_t *node, int val)
{
	if (!node)
		return NULL;

	if (val < node->val)
		return find(node->left, val);
	else if (val > node->val)
		return find(node->right, val);

	return node;
}

node_t *delete(node_t *node, int val)
{
	if (!node)
		return NULL;

	if (val < node->val)
		delete(node->left, val);
	else if (val > node->val)
		delete(node->right, val);

	if (val == node->val) {
		if (!node->left && !node->right) {
			free(node);
			return NULL;
		} else if (node->left && !node->right) {
			node_t *temp = node;

			node = node->left;
			free(temp);
			temp = NULL;
		} else if (!node->left && node->right) {
			node_t *temp = node;

			node = node->right;
			free(temp);
			temp = NULL;
		} else {
			node_t *temp = find_min(node->right);

			node->val = temp->val;

			node->right = delete(node->right, node->val);

		}
	}

	return node;
}

int main()
{
	node_t *root = NULL;
	node_t *node = NULL;

	root = insert(root, 5);
	root = insert(root, 10);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 1);
	root = insert(root, 11);

	printf("Inorder\n");
	inorder_visit(root);

	node = find_max(root);
	printf("max node: %d\n", node->val);

	node = find_min(root);
	printf("min node: %d\n", node->val);

	root = delete(root, 5);

	printf("Inorder\n");
	inorder_visit(root);

	return 0;
}
