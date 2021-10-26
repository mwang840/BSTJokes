/*
 * bstNode.cpp
 *
 *  Created on: Oct 21, 2021
 *      Author: kabut
 */

#include "bstNode.hpp"
#include <iostream>
using namespace std;
//Default constructor
bstNode::bstNode() {
	left = NULL;
	right = NULL;
	parent = NULL;
	person = NULL;
	height = 0;

}

//Constructor which takes in the names
bstNode::bstNode(string firstName, string lastName, int number, string joke){
	 person = new Student(firstName, lastName, number, joke);
	 left = NULL;
	 right = NULL;
	 parent = NULL;
	 height = 1;
}

//Prints out the nodes in the binary tree(some empty, some full)
void bstNode::printNode(){
	cout<<person<<endl;
}

//Delete the student object
bstNode::~bstNode() {
	delete person;
}

