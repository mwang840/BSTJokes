/*
 * bstNode.hpp
 *
 *  Created on: Oct 21, 2021
 *      Author: kabut
 */

#ifndef BSTNODE_HPP_
#define BSTNODE_HPP_
#include "Student.hpp"

class bstNode {
friend class TreeInterface;
public:
	bstNode();
	bstNode(string firstName, string lastName, int number, string joke);
	bstNode *left;
	bstNode *right;
	bstNode *parent;
	int height;
	Student *person;
	void printNode();
	virtual ~bstNode();
};

#endif /* BSTNODE_HPP_ */
