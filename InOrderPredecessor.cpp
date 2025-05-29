#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    object.findInOrder();



    object.display();	//displays again after!
   
    return 0;
}

void bst::findInOrder() {
    if (!root) { //if no root, no tree
        cout << "No tree to do operation on." << endl;
        return;
    }
    if (root->left == nullptr) { //if theres no left child, no inorder predecessor
        cout << "Can't do operation." << endl;
        return;
    }
    node* inOrderP = findHelper(root->left);
    cout << "Root: " << root->data << endl;
    cout << "In-Order Predecessor: " << inOrderP->data << endl;
}

node* bst::findHelper(node* current) {
    if (current->right == nullptr) { //if there is no more right to go, return the current node, thats the in order predecessor
        return current;
    }
    //else, keep going down the right subtree
    return findHelper(current->right);
}

