/* Given the root of a binary tree, invert the tree, and return its root. */
#include<iostream>
#include<queue>

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

void printBinaryTree(TreeNode *root)
{
    if(!root) return;
    std::queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if(node) {
            std::cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    std::cout << std::endl;
}

void invertTree(TreeNode *root)
{
    if (!root) return;
    std::queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        std::swap(node->left, node->right);
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right= new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // Input: root = [4,2,7,1,3,6,9]
    // Output: [4,7,2,9,6,3,1]
    std::cout << "Tree before invert(expected: [4,2,7,1,3,6,9])" << std::endl;
    printBinaryTree(root);

    invertTree(root);
    std::cout << "Tree after invert(expected: [4,7,2,9,6,3,1])" << std::endl;
    printBinaryTree(root);

    return 0;
}
