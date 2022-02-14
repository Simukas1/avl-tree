#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

struct Node* new_node(int data) {
	struct Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		exit(-1);
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}

int return_height(Node* node) {
	if (node == NULL) {
		return 0;
	}
	return node->height;
}

int get_tree_balance(Node* node) {
	if (node == NULL) {
		return 0;
	}
	return return_height(node->left) - return_height(node->right);
}

Node* rotate_right(Node* b) {
	Node* a = b->left;
	Node* T2 = a->right;
	a->right = b;
	b->left = T2;
	b->height = max(return_height(b->left), return_height(b->right)) + 1;
	a->height = max(return_height(a->left), return_height(a->right)) + 1;
	return a;
}

Node* rotate_left(Node* a) {
	Node* b = a->right;
	Node* T2 = b->left;
	b->left = a;
	a->right = T2;
	a->height = max(return_height(a->left), return_height(a->right)) + 1;
	b->height = max(return_height(b->left), return_height(b->right)) + 1;
	return b;
}

Node* insert_node(Node* node, int data) {
	if (node == NULL) {
		return (new_node(data));
	}

	if (data < node->data) {
		node->left = insert_node(node->left, data);
	}
	else if (data > node->data) {
		node->right = insert_node(node->right, data);
	}
	else {
		return node;
	}

	node->height = max(return_height(node->left), return_height(node->right)) + 1;

	int balance = get_tree_balance(node);

	if (balance > 1 && data < node->left->data) {
		return rotate_right(node);
	}
	if (balance<-1 && data>node->right->data) {
		return rotate_left(node);
	}
	if (balance > 1 && data > node->left->data) {
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	if (balance < -1 && data < node->right->data) {
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

Node* min_value_node(Node* node) {
	Node* curr = node;
	while (curr->left != NULL) {
		curr = curr->left;
	}
	return curr;
}

Node* delete_node(Node* node, int data) {
	if (node == NULL) {
		return node;
	}
	if (data < node->data) {
		node->left = delete_node(node->left, data);
	}
	else if (data > node->data) {
		node->right = delete_node(node->right, data);
	}
	else {
		if (node->left == NULL || node->right==NULL) {
			Node* temp = node->left ? node->left : node->right;
			if (temp == NULL) {
				temp = node;
				node = NULL;
			}
			else {
				*node = *temp;
			}
			free(temp);
		}
		else {
			Node* temp = min_value_node(node->right);
			node->data = temp->data;
			node->right = delete_node(node->right, temp->data);
		}
	}
	if (node == NULL) {
		return node;
	}
	node->height = max(return_height(node->left), return_height(node->right)) + 1;
	int balance = get_tree_balance(node);
	if (balance > 1 && get_tree_balance(node->left) >= 0) {
		return rotate_right(node);
	}
	if (balance > 1 && get_tree_balance(node->left) < 0) {
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	if (balance < -1 && get_tree_balance(node->right) <= 0) {
		return rotate_left(node);
	}
	if (balance < -1 && get_tree_balance(node->right)>0) {
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

Node* delete_tree(Node* node) {
	if (node->right == NULL && node->left == NULL) {
		free(node);
		return node;
	}
	if (node->right != NULL) {
		delete_tree(node->right);
	}
	if (node->left != NULL) {
		delete_tree(node->left);
	}
	free(node);
}