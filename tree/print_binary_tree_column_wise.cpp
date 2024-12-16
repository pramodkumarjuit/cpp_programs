/*
 * Problem Statement: print a binary tree column-wisae
 *
 *       1
 *      / \
 *     2   3
 *    / \ / \
 *   4  5 6  7
 *
 * Output: 4 2 1 5 6 3 7
 *
 *
 * Approach:
 *     1. Nodes are grouped into columns based on their horizontal distance from the root.
 *     2. Horizontal Distance (HD):
 *        - Root node is at HD = 0.
 *        - Moving left decreases HD by 1.
 *        - Moving right increases HD by 1.
 *     3. Perform a level-order traversal (using a queue) to visit nodes.
 *     4. Maintain a map:
 *         - Keys represent the HD.
 *         - Values are lists of nodes's value corresponding to that HD.
 *     5. At the end, traverse the map to print nodes column-wise.
 * */


#include<iostream>
#include<unordered_map>
#include<queue>    
#include<vector>    
#include<map>    

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void printColumnWise(TreeNode* root)
{
    // Note: The std::map ensures keys (horizontal distances) are stored in
    //       sorted order, which guarantees the correct column-wise traversal.
    //{HD->{val1, val2...} }
    map<int, vector<int>> map;

    // {TreeNode*, HD} 
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        TreeNode* node = front.first;
        int horizontal_dist = front.second;

        // add HD and node's value
        map[horizontal_dist].push_back(node->val);

        if (node->left) {
            q.push({node->left, horizontal_dist - 1});
        }

        if (node->right) {
            q.push({node->right, horizontal_dist + 1});
        }
    } // while

    for (auto &col: map) {
        for (auto &val: col.second) {
            cout << val << " ";
        }
    }
    cout << endl;
}

int main()
{
    // construct a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    printColumnWise(root);

    return 0;
}
