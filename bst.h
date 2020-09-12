#ifndef POLT_BST_H
#define POLT_BST_H

#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class bst
{
private:
	struct Node
	{
		T value;
		Node* Left;
		Node* Right;
	};
	Node* root;
	void inorderHelper(ostream&, Node*) const;
	void preorderHelper(ostream&, Node*) const;
	void postorderHelper(ostream&, Node*) const;
	void getMinimumHelper(Node*, Node*&) const; //can it be const?
	void getMaximumHelper(Node*, Node*&) const; //can it be const?
public:
	// Constructor#
	bst() { root = nullptr; }
	//Copy Constructor
	bst(const bst& tocopy)
	{
		root = nullptr;
		copyBinarySearchTree(tocopy.root, root);
	}
	//Assignment operator
	/*
	operator=
	precondition: two bst objects, one of which fully defined and on the right side of the '=' operator, exist
	postcondition: bst object to the left of the '=' operator becomes a copy of the bst object on the right
	*/
	void operator = (const bst& tocopy)
	{
		root = nullptr;
		copyBinarySearchTree(tocopy.root, root);
	}
	// Destructor
	~bst();
	// operations#
	void insert(const T&);
	void inorder(ostream&);
	void preorder(ostream&);
	void postorder(ostream&);
	bool search(const T&) const;
	bool remove(const T&);
	void deleteBinarySearchTree(Node*&);
	void copyBinarySearchTree(Node*, Node*&);
	T getMinimum() const;
	T getMaximum() const;
	T getSuccessor(const T&) const;
	T getPredecessor(const T&) const;
};

/*
inorderHelper
precondition: bst object, bst Node pointer (n), and an ostream reference exist
postcondition: uses the inorderHelper for the node to the left of the one pointed to by n if it exists, displays value of current node, and uses the inorderHelper for the node to the right of the one pointed to by n if it exists
*/
template <typename T>
void bst<T>::inorderHelper(ostream& os, Node* n) const
{
	if (n->Left)
	{
		this->inorderHelper(os, n->Left);
	}
	os << n->value << " ";
	if (n->Right)
	{
		this->inorderHelper(os, n->Right);
	}
}

/*
preorderHelper
precondition: bst object, bst Node pointer (n), and an ostream reference exist
postcondition: displays value of current node, uses the preorderHelper for the node to the left of the one pointed to by n if it exists, and uses the preorderHelper for the node to the right of the one pointed to by n if it exists
*/
template <typename T>
void bst<T>::preorderHelper(ostream& os, Node* n) const
{
	os << n->value << " ";
	if (n->Left)
	{
		this->preorderHelper(os, n->Left);
	}
	if (n->Right)
	{
		this->preorderHelper(os, n->Right);
	}
}

/*
postorderHelper
precondition: bst object, bst Node pointer (n), and an ostream reference exist
postcondition: uses the preorderHelper for the node to the left of the one pointed to by n if it exists, uses the preorderHelper for the node to the right of the one pointed to by n if it exists, and displays value of current node
*/
template <typename T>
void bst<T>::postorderHelper(ostream& os, Node* n) const
{
	if (n->Left)
	{
		this->postorderHelper(os, n->Left);
	}
	if (n->Right)
	{
		this->postorderHelper(os, n->Right);
	}
	os << n->value << " ";
}

/*
getMinimumHelper
precondition: bst object, bst Node pointer (sub), and bst Node pointer reference (min) exist
postcondition: calls the getMinimumHelper again with the node to the left of sub if it exists, or sets min to sub otherwise
*/
template <typename T>
void bst<T>::getMinimumHelper(Node* sub, Node*& min) const
{
	if (sub->Left)
		this->getMinimumHelper(sub->Left, min);
	else
		min = sub;
}

/*
getMaximumHelper
precondition: bst object, bst Node pointer (sub), and bst Node pointer reference (min) exist
postcondition: calls the getMaximumHelper again with the node to the right of sub if it exists, or sets min to sub otherwise
*/
template <typename T>
void bst<T>::getMaximumHelper(Node* sub, Node*& min) const
{
	if (sub->Right)
		this->getMaximumHelper(sub->Right, min);
	else
		min = sub;
}


/*
~bst
precondition: bst object exists
postcondition: deletes the root pointer if it is a nullpointer, or runs deleteBinarySearchTree for the entire tree (starting at the root) otherwise
*/
template <typename T>
bst<T>::~bst()
{
	if (!root)
	{
		delete root;
	}
	else
	{
		deleteBinarySearchTree(root);
	}
}


/*
insert
precondition: bst object and a constant T reference exist
postcondition: adds a node with a T value to the bst object
*/
template <typename T>
void bst<T>::insert(const T& value_par)
{
	Node* previousnode, *nodeptr, * new_node;
	new_node = new Node;
	new_node->value = value_par;
	new_node->Left = nullptr;
	new_node->Right = nullptr;
	if (!root)
		root = new_node;
	else
	{
		previousnode = nullptr;
		nodeptr = root;
		bool last_left = true;
		while (nodeptr)
		{
			if (value_par > nodeptr->value)
			{
				previousnode = nodeptr;
				nodeptr = nodeptr->Right;
				last_left = false;
			}
			else if (value_par < nodeptr->value)
			{
				previousnode = nodeptr;
				nodeptr = nodeptr->Left;
				last_left = true;
			}
		}
		if (last_left)
		{
			previousnode->Left = new_node;
		}
		else
			previousnode->Right = new_node;
	}
}

/*
inorder
precondition: bst object and an ostream reference exist
postcondition: displays the values of the bst object with inorder traveral, using the inorderHelper function to assist it
*/
template <typename T>
void bst<T>::inorder(ostream& os)
{
	if (root) {
		this->inorderHelper(os, root);
		cout << endl;
	}
}

/*
preorder
precondition: bst object and an ostream reference exist
postcondition: displays the values of the bst object with preorder traveral, using the preorderHelper function to assist it
*/
template <typename T>
void bst<T>::preorder(ostream& os)
{
	if (root) {
		this->preorderHelper(os, root);
		cout << endl;
	}
}

/*
postorder
precondition: bst object and an ostream reference exist
postcondition: displays the values of the bst object with postorder traveral, using the postorderHelper function to assist it
*/
template <typename T>
void bst<T>::postorder(ostream& os)
{
	if (root) {
		this->postorderHelper(os, root);
		cout << endl;
	}
}

/*
search
precondition: bst object and a constant T reference exist
postcondition: returns true if a node with the T value exists within the bst object, returns false otherwise
*/
template <typename T>
bool bst<T>::search(const T& value_par) const
{
	Node* previousnode, * nodeptr;
	previousnode = nullptr;
	nodeptr = root;
	while (nodeptr)
	{
		if (value_par == nodeptr->value)
			return true;
		else if (value_par > nodeptr->value)
		{
			previousnode = nodeptr;
			nodeptr = nodeptr->Right;
		}
		else if (value_par < nodeptr->value)
		{
			previousnode = nodeptr;
			nodeptr = nodeptr->Left;
		}
	}
	return false;
}

/*
remove
precondition: bst object and a constant T reference exist
postcondition: returns true and removes a node with the T value (following the rules for deletion defined in the instructions) if it exists within the bst object, returns false otherwise
*/
template <typename T>
bool bst<T>::remove(const T& value_par)
{
	Node* previousnode, * nodeptr;
	previousnode = nullptr;
	nodeptr = root;
	bool last_left = true;
	while (nodeptr)
	{
		if (value_par == nodeptr->value)
		{
			if (!previousnode && !nodeptr->Left && !nodeptr->Right)
			{
				delete nodeptr;
			}
			else if (!nodeptr->Left && !nodeptr->Right)
			{
				if (last_left)
					previousnode->Left = nullptr;
				else
					previousnode->Right = nullptr;
				delete nodeptr;
			}
			else if (!nodeptr->Left || !nodeptr->Right)
			{
				if (last_left)
				{
					if (nodeptr->Left)
						previousnode->Left = nodeptr->Left;
					else
						previousnode->Left = nodeptr->Right;
				}
				else
				{
					if (nodeptr->Left)
						previousnode->Right = nodeptr->Left;
					else
						previousnode->Right = nodeptr->Right;
				}
				delete nodeptr;
			}
			else
			{
				T temp = getSuccessor(value_par);
				remove(temp);
				nodeptr->value = temp;
			}
			return true;
		}
		else if (value_par > nodeptr->value)
		{
			previousnode = nodeptr;
			nodeptr = nodeptr->Right;
			last_left = false;
		}
		else if (value_par < nodeptr->value)
		{
			previousnode = nodeptr;
			nodeptr = nodeptr->Left;
			last_left = true;
		}
	}
	return false;
}

/*
deleteBinarySearchTree
precondition: bst object, bst Node pointer reference exists
postcondition: runs the deleteBinarySearchTree for any existant nodes to the left and right of the current node and then removes the current node with the remove function
*/
template <typename T>
void bst<T>::deleteBinarySearchTree(Node*& subTreeRoot)
{

	if (subTreeRoot->Left)
		this->deleteBinarySearchTree(subTreeRoot->Left);
	if (subTreeRoot->Right)
		this->deleteBinarySearchTree(subTreeRoot->Right);
	remove(subTreeRoot->value);

}

/*
copyBinarySearchTree
precondition: bst object, bst Node original and bst Node pointer reference copy exists
postcondition: copies of the original node and its descandant (child, grandchild, etc.) nodes are put into the copy node pointer and its descendants
*/
template <typename T>
void bst<T>::copyBinarySearchTree(Node* original, Node*& copy)
{
	Node *new_node;
	new_node = new Node;
	new_node->value = original->value;
	new_node->Left = nullptr;
	new_node->Right = nullptr;
	if (original->Left)
	{
		Node* new_node_2;
		new_node_2 = new Node;
		new_node_2->value = original->value;
		new_node_2->Left = nullptr;
		new_node_2->Right = nullptr;
		Node*& n_l = new_node_2;
		copyBinarySearchTree(original->Left, n_l);
		new_node->Left = n_l;
	}
	if (original->Right)
	{
		Node* new_node_3;
		new_node_3 = new Node;
		new_node_3->value = original->value;
		new_node_3->Left = nullptr;
		new_node_3->Right = nullptr;
		Node*& n_r = new_node_3;
		copyBinarySearchTree(original->Right, n_r);
		new_node->Right = n_r;
	}
	copy = new_node;
}

/*
getMinimum
precondition: bst object exists
postcondition: returns the minimum T value contained in the bst object's nodes
*/
template <typename T>
T bst<T>::getMinimum() const
{
	Node* ptr;
	ptr = new Node;
	Node*& min = ptr;
	this->getMinimumHelper(root, min);
	return ptr->value;
}

/*
getMaximum
precondition: bst object exists
postcondition: returns the maximum T value contained in the bst object's nodes
*/
template <typename T>
T bst<T>::getMaximum() const
{
	Node* ptr;
	ptr = new Node;
	Node*& max = ptr;
	this->getMaximumHelper(root, max);
	return ptr->value;
}

/*
getSuccessor
precondition: bst object and a constant T reference exists
postcondition: returns the  T value contained in the successor of the node with the inputted T value. Returns null if there is not a successor.
*/
template <typename T>
T bst<T>::getSuccessor(const T& value_par) const
{
	if (!this->search(value_par))
		return NULL;
	Node* nodeptr;
	nodeptr = root;
	while (nodeptr)
	{
		if (value_par == nodeptr->value)
			break;
		else if (value_par > nodeptr->value)
		{
			nodeptr = nodeptr->Right;
		}
		else if (value_par < nodeptr->value)
		{
			nodeptr = nodeptr->Left;
		}
	}
	if (!nodeptr->Right)
	{
		return NULL;
	}
	else
	{
		nodeptr = nodeptr->Right;
		while (nodeptr->Left)
		{
			nodeptr = nodeptr->Left;
		}
	}
	return nodeptr->value;
}

/*
getPredecessor
precondition: bst object and a constant T reference exists
postcondition: returns the  T value contained in the predecessor of the node with the inputted T value. Returns null if there is not a predecessor.
*/
template <typename T>
T bst<T>::getPredecessor(const T& value_par) const
{
	if (!this->search(value_par))
		return NULL;
	Node* previousnode, * nodeptr, * NewNode;
	previousnode = nullptr;
	nodeptr = root;
	if (value_par == root->value)
		return NULL;
	while (nodeptr)
	{
		if (value_par == nodeptr->value)
			break;
		else if (value_par > nodeptr->value)
		{
			previousnode = nodeptr;
			nodeptr = nodeptr->Right;
		}
		else if (value_par < nodeptr->value)
		{
			previousnode = nodeptr;
			nodeptr = nodeptr->Left;
		}
	}
	return previousnode->value;
}


#endif //POLT_BST_H