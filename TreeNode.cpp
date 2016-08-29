//
// Created by Freddie on 8/29/2016.
//

#include <iostream>

using namespace std;

struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char elem){
        value = elem;
        left = nullptr;
        right  = nullptr;
    }

};


void treeInsert(TreeNode *&root, char newItem) {
    // Add the item to the binary sort tree to which the parameter
    // "root" refers.  Note that root is passed by reference since
    // its value can change in the case where the tree is empty.
    if ( root == nullptr ) {
        // The tree is empty.  Set root to point to a new node containing
        // the new item.  This becomes the only node in the tree.
        root = new TreeNode( newItem );
        // NOTE:  The left and right subtrees of root
        // are automatically set to NULL by the constructor.
        // This is important!
        return;
    }
    else if ( newItem < root->value ) {
        treeInsert( root->left, newItem );
    }
    else {
        treeInsert( root->right, newItem );
    }
}
// end treeInsert()

void postorderPrint( TreeNode *root ) {
    // Print all the items in the tree to which root points.
    // The items in the left subtree are printed first, followed
    // by the items in the right subtree and then the item in the
    // root node.
    if ( root != nullptr ) {  // (Otherwise, there's nothing to print.)
        postorderPrint( root->left );    // Print items in left subtree.
        postorderPrint( root->right );   // Print items in right subtree.
        cout << root->value << " ";       // Print the root item.
    }
} // end postorderPrint()