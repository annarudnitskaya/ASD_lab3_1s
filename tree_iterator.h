#ifndef __ORDER_LIST
#define __ORDER_LIST

#include "node.h"

//node for list inside the iterator class (order of iterations)
struct list_node
{
	list_node* prev = nullptr;
	list_node* next = nullptr;

	node* data = nullptr;
};



//iterator base class
class base_iterator
{
protected:
	list_node* head = nullptr;
	list_node* tail = nullptr;

	list_node* current_it = nullptr;

	bool first = true;
	bool last = false;

protected:
	void add(node* _data);	//this method creates instance in the integrated list
	void clear();	//clears orders' list. it's used in move constructor and operator

protected:
	virtual void build_order(node* _data) {  }	//this method should be overrided in every child class, otherwise you'll end up with invalid iterator

protected:
	base_iterator(node* _head);	//base constructor is essential to be inherrited by childs' constructors, but is hidden (protected) to prevent creation of base iterator object

public:
	base_iterator(base_iterator&& _other);		//move constructor, used to move data from just created objects of childs' classes
	void operator=(base_iterator&& _other);	//move operator provides ability to re-use old objects without need to create new ones
	~base_iterator();	//destructor clears iterations' order, but doesn't touch data inside

	
	bool is_first();	
	bool is_last();		//if iterator is invalid (aka contains no built iterations' order) both (last) and (first) flags are set to true

	//these operators provides ability to retrieve data (*) or iterate though the tree (--/++) just like stl data structures' iterators
	int operator*();	
	void operator++();
	void operator--();
};

//depth-first traversal
class dft_iterator : public base_iterator
{
private:
	void build_order(node* _data) override;

public:
	dft_iterator(node* _head);

};



//width-first traversal
class bft_iterator : public base_iterator
{
private:
	unsigned int get_depth(node* _nptr) const;
	void add_level_to_order(node* _parent, unsigned int _level);

private:
	void build_order(node* _data) override;

public:
	bft_iterator(node* _head);

};

#endif
