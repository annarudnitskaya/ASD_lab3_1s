#include "tree_iterator.h"

base_iterator::base_iterator(node* _head)
{
	//current_it = head;

}

base_iterator::base_iterator(base_iterator&& _other)
{
	clear();

	head = _other.head;
	tail = _other.tail;
	current_it = _other.current_it;
	first = _other.first;
	last = _other.last;

	_other.head = nullptr;
	_other.tail = nullptr;
	_other.current_it = nullptr;
}

void base_iterator::operator=(base_iterator&& _other)
{
	clear();

	head = _other.head;
	tail = _other.tail;
	current_it = _other.current_it;
	first = _other.first;
	last = _other.last;

	_other.head = nullptr;
	_other.tail = nullptr;
	_other.current_it = nullptr;
}

void base_iterator::add(node* _data)
{
	if (head == nullptr)
	{
		head = new list_node;
		head->data = _data;
		tail = head;
	}
	else
	{
		tail->next = new list_node;
		tail->next->prev = tail;
		tail = tail->next;
		tail->data = _data;
	}
}

base_iterator::~base_iterator()
{
	while (head != nullptr)
	{
		list_node* ptr = head->next;
		delete head;
		head = ptr;
	}
}

int base_iterator::operator*()
{
	if (current_it != nullptr) return current_it->data->data;
	else return 0;
}

void base_iterator::operator++()
{
	if (current_it == nullptr) return;
	first = false;
	if (current_it->next == nullptr)
		last = true;
	else
		current_it = current_it->next;
}

void base_iterator::operator--()
{
	if (current_it == nullptr) return;
	last = false;
	if (current_it->prev == nullptr)
		first = true;
	else
		current_it = current_it->prev;
}

void base_iterator::clear()
{
	while (head != nullptr)
	{
		list_node* ptr = head->next;
		delete head;
		head = ptr;
	}
	tail = nullptr;
	current_it = nullptr;
}

bool base_iterator::is_first()
{
	return first;
}

bool base_iterator::is_last()
{
	return last;
}



dft_iterator::dft_iterator(node* _head) : base_iterator(_head)
{
	build_order(_head);
	current_it = head;
	if (current_it == nullptr) last = true;
}

void dft_iterator::build_order(node* _data)
{
	if (_data == nullptr) return;
	add(_data);
	build_order(_data->left);
	build_order(_data->right);
}



bft_iterator::bft_iterator(node* _head) : base_iterator(_head)
{
	build_order(_head);
	current_it = head;
	if (current_it == nullptr) last = true;
}

unsigned int bft_iterator::get_depth(node* _nptr) const
{
	if (_nptr == nullptr) return 0;

	unsigned int hl = get_depth(_nptr->left) + 1;
	unsigned int hr = get_depth(_nptr->right) + 1;

	return (hl > hr ? hl : hr);
}

void bft_iterator::add_level_to_order(node* _parent, unsigned int _level)
{
	if (_parent == nullptr) return;
	if (_level == 1) add(_parent);
	else if (_level > 1)
	{
		add_level_to_order(_parent->left, _level - 1);
		add_level_to_order(_parent->right, _level - 1);
	}
}

void bft_iterator::build_order(node* _head)
{
	if (_head == nullptr) return;
	unsigned int depth = get_depth(_head);
	for (unsigned int i = 1; i <= depth; ++i)
		add_level_to_order(_head, i);
}