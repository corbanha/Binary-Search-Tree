#ifndef NODE_H
#define NODE_H

#include "NodeInterface.h"

class Node : public NodeInterface {
public:
    Node();
    Node(int dat);
	virtual ~Node();

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	virtual int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	virtual NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	virtual NodeInterface * getRightChild() const;
	
	int data;
    Node* rightChild;
    Node* leftChild;
    
    friend class BST;
};


#endif