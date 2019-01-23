#include "Node.h"
#include "NodeInterface.h"

Node::Node(){
    rightChild = NULL;
    leftChild = NULL;
    data = 0;
}

Node::Node(int dat){
    data = dat;
    rightChild = NULL;
    leftChild = NULL;
}

Node::~Node(){
    //we don't need to do anything in our destructor
}

/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData() const{
    return data;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getLeftChild() const{
    return leftChild;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
NodeInterface * Node::getRightChild() const{
    return rightChild;
}