#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            // Number of nodes at the current level
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // Add left and right children to the queue for the NEXT level
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);

                level.push_back(node->val);
            }
            // Add the completed level to our final result
            ans.push_back(level);
        }
        return ans;
    }
};

// Driver code to test
int main()
{
    /* Creating tree:
            3
           / \
          9  20
             / \
            15  7
    */
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "BFS (Level Order) Traversal:" << endl;
    for (const auto &level : result)
    {
        cout << "[ ";
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
    /* Expected Output:
       [ 3 ]
       [ 9 20 ]
       [ 15 7 ]
    */

    return 0;
}
