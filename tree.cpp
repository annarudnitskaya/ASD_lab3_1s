#include "tree.h"

void tree::delete_all_nodes(node* _nptr)
{
	if (_nptr == nullptr) return;
	delete_all_nodes(_nptr->left);
	delete_all_nodes(_nptr->right);
	delete _nptr;
}

node* tree::find_node(node* _prev, int _key)
{
	if (_prev == nullptr) return nullptr;
	if (_prev->data == _key) return _prev;
	if (_key > _prev->data) return find_node(_prev->right, _key);
	else return find_node(_prev->left, _key);
}

tree::~tree()
{
	delete_all_nodes(head);
}

bool tree::contains(int _key)
{
	if (find_node(head, _key) != nullptr) return true;
	else return false;
}

void tree::insert(int _key)
{
	if (head == nullptr)	//if tree is empty, create new node in the head
	{
		head = new node;
		head->data = _key;
	}
	else					//otherwise find empty acceptable place and insert node there
	{
		node* ptr = head;
		while ((ptr->data < _key ? ptr->right : ptr->left) != nullptr)
			ptr = (ptr->data < _key ? ptr->right : ptr->left);

		if (ptr->data < _key)
		{
			ptr->right = new node;
			ptr->right->data = _key;
			ptr->right->parent = ptr;
		}
		else
		{
			ptr->left = new node;
			ptr->left->data = _key;
			ptr->left->parent = ptr;
		}
	}
}

void tree::remove(int _key)
{
	if (head == nullptr) return;
	if (head->data == _key)
	{
		node* rptr = head->right;
		node* lptr = head->left;
		delete head;

		if (lptr == nullptr && rptr == nullptr) head = nullptr;
		else if (rptr == nullptr) head = lptr;
		else if (lptr == nullptr) head = rptr;
		else
		{
			head = rptr;

			node* ptr = head;
			while (ptr->left != nullptr)
				ptr = ptr->left;
			ptr->left = lptr;
			lptr->parent = ptr;
		}

		if(head != nullptr)
			head->parent = nullptr;
		return;
	}

	node* ptr = find_node(head, _key);	//find node to delete
	if (ptr == nullptr) return; //do nothing if cant find

	node* pptr = ptr->parent;  //some more temp pointers for readability
	node* rptr = ptr->right;
	node* lptr = ptr->left;

	bool left = pptr->left == ptr;

	delete ptr;

	if (rptr == nullptr && lptr == nullptr)	//if deleted node didnt have childs, set it's parent's child to nullptr
	{
		if (left)
			pptr->left = nullptr;
		else
			pptr->right = nullptr;
	}
	else if (rptr != nullptr)				//if deleted node had some childs, put them in it's place
	{
		if (left)
			pptr->left = rptr;
		else
			pptr->right = rptr;

		rptr->parent = pptr;

		if (lptr != nullptr)
		{
			ptr = rptr;
			while (ptr->left != nullptr)
				ptr = ptr->left;
			ptr->left = lptr;
			lptr->parent = ptr;
		}
	}
	else
	{
		if (left)
			pptr->left = lptr;
		else
			pptr->right = lptr;
		lptr->parent = pptr;
	}
}

base_iterator tree::create_dft_iterator()
{
	return dft_iterator(head);
}

base_iterator tree::create_bft_iterator()
{
	return bft_iterator(head);
}