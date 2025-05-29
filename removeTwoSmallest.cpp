#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    object.removeTwo();



    object.display();	//displays again after!
   
    return 0;
}


void bst::removeTwo() {
    cout << "Root: " << root->data << endl;
    if (!root) { //no root = no tree
        cout << "No tree to delete from." << endl;
        return;
    }
    if (root->left == nullptr) { //no leftchild, nothing smaller to delete
        cout << "Nothing smaller to delete." << endl;
        return;
    }
    root = removeHelper(root); //ensures root reflects the changes that can occur
    root = removeHelper(root);

}

node* bst::removeHelper(node* current) {
    if (current->left == nullptr) { //this is the smallest node
        node* temp = current->right; //if there is a rightchild of this node, it will become the parent
        delete current;
        return temp;
    }
    current->left = removeHelper(current->left); //setting currents leftpointer to point at the node we return ensures if we delete the leftchild the connection is restored, no matter if its the right child or nullptr
    return current;
}