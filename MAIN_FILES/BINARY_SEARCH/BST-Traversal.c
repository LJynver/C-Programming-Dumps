#include <stdio.h>
#include <stdlib.h>

struct TreeNode { //assume this is the definition of a node in a tree
    int val;
    struct TreeNode *left, *right;
};


int main () {

    return 0;
}

int rangeSumBST(struct TreeNode* root, int low, int high){
    // Preorder approach
    int sum = 0;
    if (root != NULL) {
        sum = (root->val >= low && root->val <= high) ? sum + root->val : 0;
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
    }
    return sum;
}

/* PRE-ORDER APPROACH  

1. The root node is visited
2. Do any operation with the value
3. Proceed to the left child
    3a. If left child has a child as well, repeat process 1-3 until it is a leaf
    3b. If left child is empty, it will basically return 0 and proceeds to the right child and repeat 1-3
    3c. If right child is empty, it returns 0
4. Proceed then to the right child
    4a. If right child has a left child, repeat the process 1-3 until it is a leaf
    4b. If left child is empty, it will return 0 and proceeds to the right child
    4c. If right child is empty, it will return nothing and goes back to the root

*/

int rangeSumBST(struct TreeNode* root, int low, int high){
    // Inorder approach
    int sum = 0;
    if (root != NULL) {
        sum = rangeSumBST(root->left, low, high);
        sum = (root->val >= low && root->val <= high) ? sum + root->val : 0;
        sum += rangeSumBST(root->right, low, high);
    }
    return sum;
}