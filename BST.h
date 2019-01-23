#ifndef BST_H
#define BST_H


#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface {
public:
    BST();
	virtual ~BST();

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual NodeInterface * getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	virtual bool add(int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	virtual bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear();   
	
	Node* root;
	
	virtual void printNodes();
private:
    bool add(Node*& localRoot, int data);
    
    bool remove(Node*& localRoot, int data);
    
    Node* largest(Node*& localRoot);
    
    void clear(Node*& localRoot);
    
    void printNodes(Node* localRoot);
};


#endif