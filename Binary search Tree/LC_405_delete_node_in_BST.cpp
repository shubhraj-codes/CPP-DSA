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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        TreeNode * curr = root;
        TreeNode * par = NULL;
        while(curr != NULL && curr->val != key)
        { 
            par = curr;

            if(key < curr->val) curr = curr->left;
            else curr = curr->right;
        }
        if(curr == NULL) return root;

        if(curr->left != NULL && curr->right != NULL) 
        {
            TreeNode * sucPar = curr;
            TreeNode * suc = curr->right;

            while(suc->left != NULL)
            {   
                sucPar = suc;
                suc = suc->left;
            }

            curr->val = suc->val;
            curr = suc;
            par = sucPar;
        }

        TreeNode * child;

        if(curr->left != NULL) child = curr->left;
        else child = curr->right;

        if(par == NULL) root = child;

        else if(par->left == curr) par->left = child;

        else par->right = child;
        
        delete curr;
        return root;
    }
};
