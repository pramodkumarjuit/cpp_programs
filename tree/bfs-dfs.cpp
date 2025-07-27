#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the depth of a binary tree using BFS
int maxDepthBFS(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        depth++;

        // Process all nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return depth;
}

// Function to find the depth of a binary tree using DFS (iterative)
// *** Go deep down a branch before exploring siblings. ***
int maxDepthDFS(TreeNode* root) {
    if (!root) return 0;

    stack<pair<TreeNode*, int>> st; // Stack holds pairs of (node, current depth)
    st.push({root, 1});
    int maxDepth = 0;

    while (!st.empty()) {
        TreeNode* node = st.top().first;
        int depth = st.top().second;
        st.pop();

        if (node) {
            maxDepth = max(maxDepth, depth);
            st.push({node->right, depth + 1});
            st.push({node->left, depth + 1});
        }
    }

    return maxDepth;
}

int main() {
    // Example binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
//    root->left->right->left = new TreeNode(7);
  //  root->left->right->right = new TreeNode(8);

    cout << "Maximum Depth of Tree using BFS: " << maxDepthBFS(root) << endl; // Output: 3
    cout << "Maximum Depth of Tree using DFS: " << maxDepthDFS(root) << endl; // Output: 3

    return 0;
}

