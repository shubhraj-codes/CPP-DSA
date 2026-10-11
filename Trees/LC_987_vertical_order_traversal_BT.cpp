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
    vector<tuple<int, int, int>> nodes;

    void dfs(TreeNode * root, int r, int c)
    {
        if(!root) return;

        nodes.push_back({c, r, root->val});

        dfs(root->left, r + 1, c - 1);
        dfs(root->right, r + 1, c + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        int prevCol = INT_MIN;

        for(auto [col, row, val] : nodes)
        {
            if(col != prevCol)
            {
                ans.push_back({});
                prevCol = col;
            } 

            ans.back().push_back(val);
        }

        return ans;
    }
};
