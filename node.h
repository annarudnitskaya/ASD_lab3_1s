#ifndef __NODE
#define __NODE

//this is node struct for the tree
struct node
{
	node* parent = nullptr;

	node* left = nullptr;
	node* right = nullptr;

	int data;
};

#endif