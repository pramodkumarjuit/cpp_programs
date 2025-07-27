#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val): val(val), left(nullptr), right(nullptr) {}

};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return nullptr;

    // Preorder: root, left, right
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> st;
    st.push(root);
    int inIndex = 0; // to track inorder

    // For each element in preorder (after the root):
    //  - If the value on top of the stack is not equal to inorder[inIndex],
    //    the current node is the left child.
    //  - Otherwise, pop from the stack if the values match. 
    //    The current node becomes the right child of the last popped node.
    for (int i = 1; i < preorder.size(); ++i) {
        TreeNode* node = new TreeNode(preorder[i]);
        TreeNode* parent = nullptr;

        // Find parent node for right child by comparing with inorder
        while (!st.empty() && st.top()->val == inorder[inIndex]) {
            parent = st.top();
            st.pop();
            ++inIndex;
        }

        if (parent) {
            parent->right = node;
        } else {
            st.top()->left = node;
        }

        st.push(node);
    }

    return root;
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder =  {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder of built tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
