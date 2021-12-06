#ifndef __TREE
#define __TREE

#include "node.h"
#include "tree_iterator.h"

//the tree itself
class tree
{
private:
	node* head = nullptr;	//pointer to the head (root) of the tree

private:
	void delete_all_nodes(node* _nptr);
	node* find_node(node* _prev, int _key);

public:
	~tree();	//destructor deletes all data from computer's memory. 
	//if any of iterators were created, their data will be corrupted and usage will cause crash

	void insert(int _key);		//add node to the tree. algorythm complexity - from O(log(n)) to O(n) depending on input order of keys.
	void remove(int _key);		//remove node from tree. algorythm complexity - from O(log(n)) to O(n) depending on the position of deleted element
	bool contains(int _key);	//check if _key is present in the tree. algorythm complexity - from O(log(n)) to O(n) depending on the position of _key

	//iterators for easy traversal through the tree. if the tree was modifyed in any way, you have to create new iterator. you can use the same object
	//example:
	//	tree t;
	//	t.insert(11);
	//	iterator it = t.create_dft_iterator();
	//	t.remove(11);
	//	it = t.create_dft_iterator();
	//you can use both methods to initialize iterator object

	base_iterator create_dft_iterator();	//creates iterator with depth-first traversal algorythm. 
	base_iterator create_bft_iterator();	//creates iterator with width-first traversal algorythm.
};
// class Iterator for bfs_iterator and dfs_iterator




#endif