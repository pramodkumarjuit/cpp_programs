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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) return nullptr;

    int postIndex = postorder.size() -1;
    int inIndex = inorder.size() - 1;

    stack<TreeNode*> st;
    TreeNode* root = new TreeNode(postorder[postIndex]);
    st.push(root);

    for (int i = postIndex-1; i >=0 ; i--) {
        TreeNode* node = new TreeNode(postorder[i]);
        TreeNode* parent = nullptr;

        while(!st.empty() && st.top()->val == inorder[inIndex]) {
            parent = st.top();
            st.pop();
            inIndex--;
        }

        if (parent) {
            parent->left = node;
        } else {
            st.top()->right = node;
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
    vector<int> inorder =  {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Inorder of built tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
