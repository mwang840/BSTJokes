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

//Inserts a node in the bst if the root is not null. Otherwise, compare the nodes data and check. Returns the status of inserting. Recursion is a big player in this function.
bool bst::insert(string f, string l, int n, string j){
	bstNode *temp = new bstNode();
	if(root == NULL){
		temp = new bstNode(f, l, n, j);

	}
	else{
		if(temp->person->last < l){
			if(temp->left == NULL){
				temp->left = new bstNode(f, l,n,j);
				temp->parent = temp;
				return true;
			}
			else{
				insert(f,l,n,j);
			}
		}
		else if(temp->person->last > l){
			if(temp->right == NULL){
				temp->right = new bstNode(f, l, n, j);
				temp->parent = temp;
				return true;
			}
			else{
				insert(f, l, n, j);
			}
		}
		else{
			return false;
		}
	}
}

//Find the node which has the first and last name is in the tree. It will return the node of the matching first and last name otherwise, return null.
bstNode bst::*find(string l, string n){
	bstNode *temp = new bstNode();
	if(root == NULL){
		return NULL;
	}
	else{
		if(temp->person->last == l){
			if(temp->person->first == l){
				return temp;
			}
			else{
				find(l, n);
			}
		}
		else{
			if(temp->person->last < l){
				temp = temp->left;
				find(l, n);
			}
			if(temp->person->last > l){
				temp = temp->right;
				find(l,n);
			}
		}
		else{
			return NULL;
		}

	}

}

void bst::clearTree(bstNode *tmp) { //Recursive call in which the nodes are deleted from the tree
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

void bst::printTreeIO(bstNode *n){ //Recursive version which prints out the nodes in order starting from the node input
	if(n == NULL){
		return;
	}
		//Start from the left child of root until the left==NULL
		printTreeIO(n->left);
		//Prints out the information of the node
		n->printNode();
		//Start from the right child of root until the right==NULL
		printTreeIO(n->right);

}

void bst::printTreePre() { //Prints out the tree in preorder calls recursive function if root != NULL
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void bst::printTreePre(bstNode *n){//Recursive version which prints out the nodes in order starting from the node input(root) and going down by node class order
	if(n == NULL){
		return;
	}
	n->printNode();
	//Start from the left child of root until the left==NULL
	printTreePre(n->left);
	//Start from the right child of root until the right==NULL
	printTreePre(n->right);
}

void bst::printTreePost() {//Recursive version which prints out the nodes in order starting from the child nodes
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}
