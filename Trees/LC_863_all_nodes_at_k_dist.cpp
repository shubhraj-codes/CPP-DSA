/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode *, TreeNode *> parent;

    void markParent(TreeNode * root, TreeNode *par)
    {
        if(root == NULL) return;

        parent[root] = par;

        markParent(root->left, root); 
        markParent(root->right, root); 
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParent(root, NULL);

        queue<TreeNode *> q;
        q.push(target);

        unordered_set<TreeNode *> visited;
        visited.insert(target);

        int dis = 0;

        while(!q.empty())
        {
            if(dis == k) break;

            int n = q.size();

            for(int i = 0; i < n; i++)
            {
                TreeNode * node = q.front();
                q.pop();

                if(node->left && !visited.count(node->left)) 
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && !visited.count(node->right)) 
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }

                TreeNode * par = parent[node];

                if(par && !visited.count(par))
                {
                    q.push(par);
                    visited.insert(par);
                }
            }

            dis++;
        }

        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
