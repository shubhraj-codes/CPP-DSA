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
    TreeNode * build(vector<int> &preorder, int &i, int lower, int upper)
    {
        if(i == preorder.size()) return NULL;

        int x = preorder[i];

        if(x < lower || x > upper) return NULL;

        TreeNode * root = new TreeNode(x);
        i++;

        root->left = build(preorder, i, lower, x);
        root->right = build(preorder, i, x, upper);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        
        return build(preorder, i, INT_MIN, INT_MAX);
    }
};
