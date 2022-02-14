#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct Node 
{
	int data, height;
	struct Node* left, *right;
}Node;

struct Node* new_node(int data);

int return_height(Node* node);

int get_tree_balance(Node* node);

Node* rotate_right(Node* b); //this function will make tree from 1) to 2)

Node* rotate_left(Node* a);  //this function will make tree from 2) to 1)

Node* insert_node(Node* node, int data);

Node* delete_tree(Node* node);

Node* delete_node(Node* node, int data);

Node* min_value_node(Node* node);


#endif

/*
*	1)			a
*			   / \
*			  b	  T3
*			 / \ 
*			T1  T2
* 
* 
*	2)			b
*			   / \
*			  T1  a
*				 / \
*				T2  T3
*
*/