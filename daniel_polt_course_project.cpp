/*
 Solution to course project
 Solution written by Daniel Polt.
*/
//This program tests binary search trees, which are designed to be nonlinar linked structures with several member functions.

#include <iostream>
#include <fstream>
#include "bst.h"

using namespace std;


int main()
{

	bst<int> b;
	

	b.insert(50);
	b.insert(30);
	b.insert(70);
	b.insert(20);
	b.insert(40);
	b.insert(60);
	b.insert(80);
	b.inorder(cout);
	b.preorder(cout);
	b.postorder(cout);
	cout << b.getMaximum() << endl;
	cout << b.getMinimum() << endl;
	cout << b.getPredecessor(70) << endl;
	cout << b.getPredecessor(7) << endl;
	cout << b.getSuccessor(50) << endl;
	cout << b.getSuccessor(3) << endl;
	cout << b.getPredecessor(80) << endl;
	cout << endl << endl;

	bst<int> b1(b);
	b1.insert(56);
	b1.remove(50);
	b1.inorder(cout);
	b1.preorder(cout);
	b1.postorder(cout);
	cout << endl << endl;

	bst<int> b2;
	b2 = b;
	b2.insert(51);
	b2.remove(50);
	
	b2.inorder(cout);
	b2.preorder(cout);
	b2.postorder(cout);
	cout << endl << endl;

	bst<int> b3;
	b3.insert(12);
	b3.insert(13);

	bst<int> b4(b2);
	b4.inorder(cout);


	bst<double> b5;
	b5.insert(3.5);
	b5.insert(4.8);
	b5.postorder(cout);
	cout << b5.getMaximum() << endl;
	bst<double> b6;
	b6.~bst();

	cout << "Run Done";
	return 0;
}
