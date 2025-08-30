/*
 * INPUT:
 *      7
 *      / \
 *     3   15
 *        /  \
 *       9    20
 *
 *  Expected Output:
 *     If we repeatedly call next(), we should get all values in sorted order (in-order traversal):
 *     3 → 7 → 9 → 15 → 20
 */

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}

};

class BSTIterator {
    public:
        stack<TreeNode *> st;

    void pushLeft(TreeNode *node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    int next() {
        TreeNode *node = st.top();
        st.pop();
        int val = node->val;
        if (node->right) {
            pushLeft(node->right);
        }

        return val;
    }

    bool hasNext()
    {
        return !st.empty();
    }

};

int main(int argc, char *argv[])
{

    // Example BST:
    //       7
    //      / \
    //     3   15
    //         / \
    //        9  20
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator it(root);
    cout << endl;
    while (it.hasNext()) {
        cout << it.next() << " ";  // 3 7 9 15 20
    }

    cout << endl;
    return 0;
}
