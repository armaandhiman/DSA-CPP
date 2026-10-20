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

    void solve(TreeNode * root  , TreeNode * Root , string& ans){
        if(root == nullptr)
        return ;

        if(root != Root)
        ans.push_back('(');
        
        ans += to_string(root->val);

        if(!root->left && root->right)
        {
            ans.push_back('(');
            ans.push_back(')');
        }

        solve(root->left , Root , ans);
        solve(root->right , Root , ans);

        ans.push_back(')');

    }

    string tree2str(TreeNode* root) {
        
        TreeNode * Root = root;
        string ans = "";
        solve(root , Root , ans);
        ans.pop_back();
        return ans;
    }
};
