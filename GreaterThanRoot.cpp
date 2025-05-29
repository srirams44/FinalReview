#include "bst.h"

int main()
{
    bst object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    object.count();


    object.display();	//displays again after!
   
    return 0;
}

void bst::count() { //this function will count how many nodes are greater then the root (eg how many nodes to the right of the root there are
    cout << "Root: " << root->data << endl;
    if (!root) {
        cout << "No tree." << endl;
        return;
    }
    if (root->right == nullptr) { //if root has no right children, there is nothing greater than root
        cout << "No nodes bigger than root." << endl;
        return;
    }

    int sum = countHelper(root->right); //passing in the right child so i can explore all paths stemming from the right child
    cout << "There are " << sum << " nodes greater than the root in this tree." << endl;

}

int bst::countHelper(node* current) {
    if (!current) { //if there are no more nodes in  this path, exit
        return 0;
    }
    //if there are more nodes, go down the left
    return 1 + countHelper(current->right) + countHelper(current->left);
}




