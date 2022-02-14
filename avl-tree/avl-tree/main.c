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
	print(node);
	printf("I have printed all list\n");
	node = delete_tree(node);
	print(node);
	printf("I have printed all list\n");
	for (int i = 0; i < 10; i++) {
		node = insert_node(node, i * 10);
	}
	node = delete_node(node, 10);
	print(node);
	printf("I have printed all list\n");
	node = delete_node(node, -12012);
	print(node);
	printf("I have printed all list\n");
	return 0;
}

void print(Node* node) {
	if (node != NULL) {
		printf("height:%d element:%d \n", node->height, node->data);
		print(node->left);
		print(node->right);
	}
}