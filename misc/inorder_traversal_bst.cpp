/*
 * in-order and pre-order are both traversal strategies that belong to Depth-First Search (DFS)
 * In-order traversal is a depth-first traversal technique for binary trees.
 * The order of visiting nodes is:
 *     - Traverse the left subtree.
 *     - Visit the current node.
 *     - Traverse the right subtree.
 *
 * 
 *         1
 *        / \
 *       2   3
 *      / \ / \
 *     4  5 6  7
 *
 *  In-Order Traversal: 4 2 5 1 6 3 7
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform in-order traversal iteratively using STL
vector<int> inOrderTraversal(TreeNode* root) {
    vector<int> result;       // To store the result of traversal
    stack<TreeNode*> s;       // Stack to simulate recursion
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        // Traverse the left subtree
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Visit the current node
        current = s.top();
        s.pop();
        result.push_back(current->val);

        // Traverse the right subtree
        current = current->right;
    }

    return result;
}

// Helper function to test in-order traversal
int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform in-order traversal
    vector<int> traversal = inOrderTraversal(root);

    // Print the traversal result
    cout << "In-Order Traversal: ";
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
