
#include <iostream>
#include "../tree_project/tree.h"

using namespace std; 

int main()
{
	tree t;
	t.insert(8);
	t.insert(3);
	t.insert(1);
	t.insert(6);
	t.insert(4);
	t.insert(7);
	t.insert(10);
	t.insert(14);
	t.insert(13);


	cout << "Node with key " << 7 << (t.contains(7) ? " present" : "does not present") << " in the tree:\n \n";

	cout << "Depth-first traversal output:\n";
	base_iterator it = t.create_dft_iterator();
	while (it.is_last() == false)
	{
		cout <<* it << ' ';
		++it;
	}
	cout << '\n';

	cout << "Width-first traversal output:\n";
	it = t.create_bft_iterator();
	while (it.is_last() == false)
	{
		cout <<* it << ' ';
		++it;
	}
	cout << '\n';

	return 0;
}
