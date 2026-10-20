/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode * node = q.front();
            q.pop();

            if(node == nullptr) 
            {
                s += "N,";
                continue;
            }

            s += (to_string(node->val) + ',');

            q.push(node->left);
            q.push(node->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        vector<string> nodes;
        string temp;

        for(auto c : data)
        {
            if(c != ',')
            {
                temp += c;
            }
            else 
            {
                nodes.push_back(temp);
                temp = "";
            }
        }

        TreeNode * root = new TreeNode(stoi(nodes[0]));

        queue<TreeNode *> q;
        q.push(root);

        int i = 1;

        while(!q.empty() && i < nodes.size())
        {
            TreeNode * node = q.front();
            q.pop();

            if(nodes[i] != "N")
            {
                node->left = new TreeNode(stoi(nodes[i]));
                q.push(node->left);
            }
            i++;

            if(i < nodes.size() && nodes[i] != "N")
            {
                node->right = new TreeNode(stoi(nodes[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
