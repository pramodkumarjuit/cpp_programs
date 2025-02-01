/*
 * in-order and pre-order are both traversal strategies that belong to Depth-First Search (DFS).
 * Pre-order Traversal Order:
 *     - Visit the current node.
 *     - Traverse the left subtree.
 *     - Traverse the right subtree.
 * */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform pre-order traversal iteratively
vector<int> preOrderTraversal(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();

        // Process the current node
        result.push_back(current->val);

        // Push right child first so the left child is processed first
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }

    return result;
}

int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform pre-order traversal
    vector<int> traversal = preOrderTraversal(root);

    // Print the traversal result
    cout << "Pre-order Traversal: ";
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

