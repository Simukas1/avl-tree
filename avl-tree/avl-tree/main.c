#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

void print(Node* node);

int main()
{
	Node* node = new_node(5);
	for (int i = 0; i < 10; i++) {
		node = insert_node(node, i*10);
	}
	node = insert_node(node, 15);
	node = insert_node(node, 25);
	node = insert_node(node, 120);
	node = insert_node(node, -10);
	node = insert_node(node, 6);
	print(node);
	return 0;
}

void print(Node* node) {
	if (node != NULL) {
		printf("height:%d element:%d ", node->height, node->data);
		print(node->left);
		print(node->right);
	}
}