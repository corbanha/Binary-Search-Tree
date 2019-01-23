#include "BST.h"
#include "NodeInterface.h"
#include "Node.h"

BST::BST(){
    root = NULL;
}

BST::~BST(){
    clear();
}

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
* Returns the root node for this tree
*
* @return the root node for this tree.
*/
NodeInterface * BST::getRootNode() const{
    return root;
}

/*
* Attempts to add the given int to the BST tree
*
* @return true if added
* @return false if unsuccessful (i.e. the int is already in tree)
*/
bool BST::add(int data){
    return add(root, data);
}


/*
An add helper funcion
*/
bool BST::add(Node*& localRoot, int data){
    if(localRoot == NULL){
        //this is where we want to add our item
        localRoot = new Node(data); //this will work and update this node's parent because we have &
        return true;
    }
    
    if(localRoot->data == data){
        //the item is already in here
        return false;
    }else if(data < localRoot->data){
        return add(localRoot->leftChild, data);
    }else{
        return add(localRoot->rightChild, data);
    }
}


/*
* Attempts to remove the given int from the BST tree
*
* @return true if successfully removed
* @return false if remove is unsuccessful(i.e. the int is not in the tree)
*/
bool BST::remove(int data){
    return remove(root, data);
}

/*
Remove helper function
*/
bool BST::remove(Node*& localRoot, int data){
    if(localRoot == NULL){
        //the item is not in the tree, can't remove it
        return false;
    }
    
    if(localRoot->data == data){
        //found the item! remove it
        
        //TODO cases for if the item has 0, 1, or 2 children
        
        if(localRoot->leftChild == NULL && localRoot->rightChild == NULL){
            //this is a leaf node and we don't have to do anything else!
            delete localRoot;
            localRoot = NULL;
        }else if(localRoot->leftChild != NULL && localRoot->rightChild != NULL){
            //this node has two children, more work!
            
            //we need to find the largest value in it's left subtree
          
            Node* tempToDelete = localRoot;
            localRoot = largest(localRoot->leftChild);
            localRoot->rightChild = tempToDelete->rightChild;
            localRoot->leftChild = tempToDelete->leftChild;
            delete tempToDelete;
            tempToDelete = NULL;
            
        }else if(localRoot->leftChild != NULL){
            //the node has a left child
            Node* tempToDelete = localRoot;
            localRoot = localRoot->leftChild;
            delete tempToDelete;
            tempToDelete = NULL;
        }else{
            //the node has a right child
            Node* tempToDelete = localRoot;
            localRoot = localRoot->rightChild;
            delete tempToDelete;
            tempToDelete = NULL;
        }
        
        return true;
    }else if(data < localRoot->data){
        return remove(localRoot->leftChild, data);
    }else{
        return remove(localRoot->rightChild, data);
    }
}

/*
Helper function for remove, will find the largest value in the given subtree
*/
Node* BST::largest(Node*& localRoot){
    if(localRoot == NULL){
        return NULL;
    }else if(localRoot->rightChild == NULL){
        Node* copyOfPtr = localRoot;
        localRoot = copyOfPtr->leftChild;
        return copyOfPtr;
    }else{
        return largest(localRoot->rightChild);
    }
}

/*
* Removes all nodes from the tree, resulting in an empty tree.
*/
void BST::clear(){
    while(root != NULL){
        remove(root, root->getData());
    }
}


void BST::printNodes(){
    printNodes(root);
}

/*
This function is for testing, it will print all of the nodes in the tree
*/
void BST::printNodes(Node* localRoot){
    if(localRoot == NULL){
        return;
    }
    
    cout << "Node: " << localRoot->data;
    
    if(localRoot->leftChild == NULL){
        cout << " left: NULL";
    }else{
        cout << " left: " << localRoot->leftChild->data;
    }
    
    if(localRoot->rightChild == NULL){
        cout << " right: NULL";
    }else{
        cout << " right: " << localRoot->rightChild->data;
    }
    
    cout << endl;
    
    printNodes(localRoot->leftChild);
    printNodes(localRoot->rightChild);
}