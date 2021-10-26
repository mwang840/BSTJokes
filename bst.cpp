/*
 * bst.cpp
 *
 *  Created on: Oct 23, 2021
 *      Author: kabut
 */

#include "bst.hpp"
#include "bstNode.hpp"
#include <iostream>
using namespace std;

bst::bst() { // empty constructor
	root = NULL;
}

bst::bst(string f, string l, int n, string j) { // constructor that forms the root
	root = new bstNode( f,l, n, j);
}
void bst::clearTree() { //clears out an old tree
//This calls the recursive clearTree with the root node
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

//Inserts a node in the bst if the root is not null. Otherwise, compare the nodes data and check. Returns the status of inserting.
bool bst::insert(string f, string l, int n, string j){
	bool inserted;
	if(root == NULL){
		root = new bstNode(f, l, n, j);
		
	}
	return inserted;
}

void bst::clearTree(bstNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}
void bst::printTreeIO() { // Just the start – you must write the recursive version
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}

void bst::printTreeIO(bstNode *n){ //Recursive version
	
}


void clearTree(bstNode *tmp){ // Recursive version which clears the node off the tree

}

void bst::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}


void bst::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}
