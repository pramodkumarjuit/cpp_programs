/*
 * Given the root of a binary tree. Check whether it is a Binary Search Tree or not.
 * A Binary Search Tree (BST) has the following properties:
 *    - All left nodes value in the left subtree are smaller than the root and
 *      all keys in the right subtree are greater.
 *    - Both the left and right subtrees must also be binary search trees.
 *    - Each key must be distinct.
 * */

// The solution uses in-order traversal. The in-order traversal of BST
// visits nodes in sorted order:
//       left subtree -> current node -> right subtree. 

#include <iostream>
#include <stack>
#include <climits>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if a binary tree is a BST using iterative in-order traversal
bool isBST(TreeNode* root) {
    if (root == nullptr) return true;

    stack<TreeNode*> s;
    TreeNode* current = root;
    int preVal = INT_MIN;
    bool isFirstNode = true;

    while (!s.empty() || current != nullptr) {
        // push all left subtree to a stack
        while(current != nullptr) {
            s.push(current);
            current = current->left;
        } // s=[5,3,2(top)]

        // now pop from stack and process each node
        current = s.top();
        s.pop();

        if(!isFirstNode && current->val <= preVal) return false;

        isFirstNode = false;
        preVal = current->val;
        current = current->right; // s=[5,3]; current=4 ==> in 2 iter: s=[5,3,4]
    }

    return true;
}

// Helper function to create a binary tree
TreeNode* createTree() {
    // Example tree:
    //       5
    //      / \
    //     3   7
    //    / \   \
    //   2   4   8
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    return root;
}

int main() {
    TreeNode* root = createTree();

    if (isBST(root)) {
        cout << "The binary tree is a BST." << endl;
    } else {
        cout << "The binary tree is NOT a BST." << endl;
    }

    return 0;
}

