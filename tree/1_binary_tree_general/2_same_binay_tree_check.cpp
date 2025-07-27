#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>

class TreeNode {
    public:
    int val;
    class TreeNode *left;
    class TreeNode *right;

    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}

};

bool isSameTreeRecursion(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if(p->val != q->val) return false;

    return isSameTreeRecursion(p->left, q->left) && isSameTreeRecursion(p->right, q->right);
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;

    std::queue<TreeNode *> q1, q2;
    q1.push(p);
    q2.push(q);

    while(!q1.empty() && !q2.empty()) {
        TreeNode *node1 = q1.front();
        TreeNode *node2 = q2.front();
        q1.pop();
        q2.pop();


        if (node1->val != node2->val) return false;

        // return true: if any one of the nodes are nullptr
        // Cases needs further processing:
        //  - if both are nullptr -> tree has reached edges or both the nodes are nullptr (empty tree)
        //  - if both are Not nullptr -> needs further check
        if((node1 == nullptr) ^ (node2 == nullptr)) return false;

        if(node1->left != nullptr && node2->left != nullptr) {
            q1.push(node1->left);
            q2.push(node2->left);

        }

        if (node1->right != nullptr && node2->right != nullptr) {
            q1.push(node1->right);
            q2.push(node2->right);
        }
    }

    return true;

}

int main(int argc, char *argv[])
{
    // Tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Tree 2
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(4);

    if (isSameTreeRecursion(root1, root2)) {
        std::cout << "Both trees are identical" << std::endl;
    } else {
        std::cout << "Trees are NOT identical" << std::endl;
    }

    if (isSameTree(root1, root2)) {
        std::cout << "[Iterative] Both trees are identical" << std::endl;
    } else {
        std::cout << "[Iterative] Trees are NOT identical" << std::endl;
    }
    return 0;
}
