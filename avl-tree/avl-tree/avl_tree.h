#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct Node 
{
	int data, height;
	struct Node* left, *right;
}Node;

struct Node* new_node(int data);

Node* insert_node(Node* node, int data);

Node* delete_tree(Node* node); //delets all tree

Node* delete_node(Node* node, int data); //deletes node by given data

#endif
