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
    int candidate = INT_MIN;

    int sum(TreeNode * root)
    {
        if(root == NULL) return 0;

        int left = sum(root->left);
        int right = sum(root->right);

        left = max(0, left);
        right = max(0, right);

        candidate = max(candidate, (left + root->val + right));

        return (root->val + max(left, right)); 
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return candidate;
    }
};
