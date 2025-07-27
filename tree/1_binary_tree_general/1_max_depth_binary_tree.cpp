#include<iostream>
#include<stack>
#include<queue>

/*
 * Notes:
 *  - Search Techniques: DFS & BFS
 *  - Traversal types: preorder, inorder, postorder. Only defined for DFS, not BFS.
 *  - DFS: uses stack / recursion
 *  - BFS: uses Queue
 *  ===============================================================================
 *  DFS : suitable/preferred for finding max depth a binary tree due to simple
 *        implementation and less memory usage O(h)stack(h), height of tree
 *  ===============================================================================
 *  BFS can also be used for finding max depth a binary tree but code is simple (needs loop)
 *  and memory usage O(w)queue(w)
 *  Rule of Thumb:
 *  - Choose BFS when the problem involves levels, shortest paths, or minimal steps.
 *  - Choose DFS when the problem requires exploring all paths, backtracking, or subtree-level operations.
 *
 *  Common BFS Use Cases:
 *      Minimum depth of binary tree
 *      Shortest path in unweighted graph
 *      Level-order traversal
 *      Word ladder, knight’s shortest path
 *
 * Common DFS Use Cases:
 *      Maximum depth of tree
 *      Binary tree traversals (pre/in/post)
 *      Subset/combinations/backtracking
 *      Topological sort
 *      Maze solving (all paths) 
 *
 * */

class TreeNode {
    public:
        int val;
        class TreeNode *left;
        class TreeNode *right;
        TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

/*
 * Not preferred way
 */
int maxDepthBFS(TreeNode* root)
{
    if (root == nullptr) return 0;

    std::queue<TreeNode *> q;
    q.push(root);
    int maxDepth = 0;

    while(!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            TreeNode *node = q.front(); 
            q.pop();
            if (node) {
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        maxDepth++; // completed one level
    }

    return maxDepth;
}

int maxDepthDFSRecusion(TreeNode *root) {

    if (root == nullptr) return 0;
    return 1 + std::max(maxDepthDFSRecusion(root->left), maxDepthDFSRecusion(root->right));
}

int maxDepthDSF(TreeNode *root)
{
    if (root == nullptr) return 0;

    std::stack<std::pair<TreeNode *, int>> st; // [ node, node_depth ]
    st.push({root, 1});
    int maxDepth = 0;

    // only works with gdb
    //    asm volatile ("hlt");
    //    asm volatile ("int $0x03");
    //     __builtin_trap(); 
    while (!st.empty()) {
        TreeNode *node = st.top().first;
        int curDepth = st.top().second;
        st.pop();

        if (node) {
            //std::cout << node->val << " ";
            maxDepth = std::max(maxDepth, curDepth);
            // root->left->right: Preorder
            if(node->right) st.push({node->right, curDepth+1});
            if(node->left) st.push({node->left, curDepth+1});
        }
    }

    //std::cout << std::endl;

    return maxDepth;
}
//        1
//      /  \
//     2    3
//          / \
//         4  5
int main(int argc, char *argv[])
{
#if 0
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
#else
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
#endif
    std::cout << "Depth using DFS(Pre-order:Root->left->Right): " << maxDepthDSF(root) << std::endl;
    std::cout << "Depth using DFS(recursion): " << maxDepthDFSRecusion(root) << std::endl;

    std::cout << "Depth using BFS: " << maxDepthBFS(root) << std::endl;

    return 0;
}
