/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * first = NULL, *second = NULL;

    void solve(TreeNode * root, TreeNode * &prev)
    {
        if(root == NULL) return;

        solve(root->left, prev);

        if(prev != NULL && root->val < prev->val)
        {
            if(first == NULL) first = prev;
            second = root;
        }
        prev = root;
        solve(root->right, prev);
    } 
    void recoverTree(TreeNode* root) {
        TreeNode * prev = NULL;
        solve(root, prev);

        if(first != NULL && second != NULL) swap(first->val, second->val);
    }
};
