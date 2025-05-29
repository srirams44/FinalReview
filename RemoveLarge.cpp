#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    object.removeLarge();




    object.display();	//displays again after!
   
    return 0;
}


void bst::removeLarge() {
    cout << "Root: " << root->data << endl;
    if (!root) {
        cout << "Nothing to delete." << endl;
        return;
    }
    if (root->right == nullptr) { //if root has no right branch, there is nothing larger then root to delete
        cout << "Nothing larger then root to delete." << endl;
        return;
    }
    root = removeHelper(root);
    removeLarge();
}

node* bst::removeHelper(node* current) {
    if (current->right == nullptr) { //if there is no right child of current, this is the largest possible node
        node* leftChild = current->left;
        delete current;
        return leftChild;
    }
    //if current has more right children, keep going down the tree
    current->right = removeHelper(current->right);
    return current;
}