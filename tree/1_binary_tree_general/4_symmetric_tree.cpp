/*
 * Given the root of a binary tree, check whether it is a mirror of itself (symmetric around its center).
 *  Input: root = [1,2,2,3,4,4,3]
 *  Output: true
*/


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

bool isTreeSymmetric(TreeNode *root)
{
    if (!root) return true; // empty tree is symmetric
    std::queue<std::pair<TreeNode*, TreeNode*>> q;
    q.push({root->left, root->right});
    TreeNode *node1=nullptr, *node2=nullptr;

    while(!q.empty()) {
        node1 = q.front().first;
        node2 = q.front().second;
        q.pop();

        if (node1 == nullptr && node2 == nullptr) continue;
        if (node1 == nullptr || node2 == nullptr) return false;
        if (node1->val != node2->val) return false;

        q.push({node1->left, node2->right});
        q.push({node1->right, node2->left});
    }

    return true;
}

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right= new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Input: root = [1,2,2,3,4,4,3]
    // Output: true
    std::cout << "Input Tree (expected: [1,2,2,3,4,4,3])" << std::endl;
    printBinaryTree(root);

    bool res =  isTreeSymmetric(root);
    if (res) {
        std::cout << "Tree is symmetric" << std::endl;
    } else {
        std::cout << "Tree is NOT symmetric" << std::endl;
    }

    return 0;
}
