#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root == NULL)
            return postorder;

        // st1 is for processing nodes
        // st2 is for storing them in reverse postorder (Root, Right, Left)
        stack<TreeNode *> st1, st2;
        st1.push(root);

        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);

            // Push left then right so that Right is on top of st1
            if (root->left != NULL)
            {
                st1.push(root->left);
            }
            if (root->right != NULL)
            {
                st1.push(root->right);
            }
        }
        // Pop everything from st2 to get final Postorder (Left, Right, Root)
        while (!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};

// Driver code to test
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
    vector<int> result = sol.postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    // Expected Output: 3 2 1

    return 0;
}
