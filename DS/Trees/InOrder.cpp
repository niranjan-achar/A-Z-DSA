#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)    // Left -> Root -> Right
    {
        stack<TreeNode *> st;
        TreeNode *node = root;
        vector<int> inorder;

        while (true)
        {
            if (node != NULL)
            {
                // Keep going left and push nodes onto the stack
                st.push(node);
                node = node->left;
            }
            else
            {
                // If we reach a NULL, check if the stack is empty
                if (st.empty()) break;

                // Pop the last node, record its value, then go right
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};

// Simple driver code to test
int main()
{
    // Creating a sample tree: [1, 2, 3]
    //      1
    //     / \
    //    2   3
    //   / \  
    //  4  5
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    // Output: 4 2 5 1 3

    return 0;
}
