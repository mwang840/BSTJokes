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
	bstNode *temp = root;
	if(root == NULL){
		root = new bstNode(f, l, n, j);
		return true;
	}
	else{
		while(temp->person->last != l){
			 if(temp->person->last > l){
				if(temp->left == NULL){
					temp->left = new bstNode(f, l, n, j);
					temp->left->parent = temp;
					setHeight(temp);
					return true;
					}
				else{
					temp = temp->left;
				}
			}
			else if(temp->person->last < l){
				 if(temp->right == NULL){
					 temp->right = new bstNode(f,l,n,j);
					 temp->right->parent = temp;
					 setHeight(temp);
					 return true;
				 }
				 else{
					 temp = temp->right;
				 }
			 }
			else{
				break;
			}
		}
	}
	return false;
}

//Find the node which has the first and last name is in the tree. It will return the node of the matching first and last name otherwise, return null.
bstNode *bst::find(string l, string n){
	bstNode *temp = root;
	if(root == NULL){
		return NULL;
	}
	else{
		while(temp != NULL && temp->person->last != l){
			if(temp->person->last > l){
				if(temp->person->last == l && temp->person->first == n){
					return temp;
				}
				else{
					temp = temp->left;
				}
			}
			else{
				if(temp->person->last == l && temp->person->first == n){
					return temp;
				}
				else{
					temp = temp->right;
				}
			}
		}
		if(temp->person->last == l){
			temp->printNode();
			return temp;
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
		//Prints out the information of the student node
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
	//Prints out the information of the student node
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

void bst::printTreePost(bstNode *n){//Recursive version which prints out the nodes from the bottom
	cout<<"Testing printTreePost";
	if(n == NULL){
		return;
	}
	//Start from the left child of root until the left==NULL
	printTreePost(n->left);
	//Start from the right child of root until the right==NULL
	printTreePost(n->right);
	//Prints out the information of the student node
	n->printNode();
}

//finds the minimum value of the node
bstNode *bst::minValNode(bstNode *n){
	bstNode *temp = n;
	while(temp && temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

//Removes the node off the tree, if the root is NULL, NULL will be returned.
bstNode *bst::remove(string l, string f){
	bstNode *temp = new bstNode();
	bool flag = true;
	if(root == NULL){
		temp = NULL;
	}
	else if(root->person->last > l){
		root->left = remove(l,f);
		setHeight(temp);
	}
	else if(root->person->last < l){
		root->right = remove(l,f);
		setHeight(temp);
	}
	else if(root->person->last == l){
		if(root->person->first == f){
			temp = root;
		}
		//Case one: node has no children

			removeNoKids(temp);
		//Case two: node has one child
			removeOneKid(temp, flag);
		//Case three: node has two children
			temp = minValNode(root->right);
			root->right = remove(root->right->person->last, root->right->person->first);
	}
	return temp;
}

//Removes the node that only has no children. Return the node which is being removed if the root is NULL, NULL will be returned.
 bstNode *bst::removeNoKids(bstNode *tmp){
	 bstNode *temp = tmp;
	 //Base case here
	 if(tmp == NULL){
		 temp = NULL;
	 }
	 if(tmp->left == NULL && tmp->right == NULL){
		 temp = NULL;
	 }
	 else if(tmp->left == NULL){
		 temp = root ->right;
		 delete tmp;
	 }
	 else if(root->right == NULL){
		 temp = root->left;
		 delete tmp;
	 }
	 //Calls set height after deletion
	 setHeight(temp);
	 root->right = removeNoKids(root->right);
	 return temp;
 }

//Removes the node that only has one child. Return the node which is being removed if the root is NULL, NULL will be returned.
bstNode *bst::removeOneKid(bstNode *tmp, bool leftFlag){
	bstNode  *temp = tmp;
	//Base case here
	if(tmp == NULL){
		return tmp;
	}
	if(tmp->left == NULL){
		temp = tmp;
		leftFlag = false;
		delete tmp;
	}
	else if(tmp->right == NULL){
		temp = tmp;
		leftFlag = true;
		delete tmp;
	}
	tmp->right = removeOneKid(tmp->right, leftFlag);
	return temp;
}

//Sets the height of the nodes in the tree. This one is a hard one since it has to account for the cases recursively.
void bst::setHeight(bstNode *n){
	int height = 0;
	//Base case
	if(n->parent == NULL){
		height+=1;
	}
	else if(n->left == NULL and n->right == NULL){
		height = 1;
		setHeight(n->parent);
	}
	else{
		height+=1;
		setHeight(n->parent);
	}
}


