class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode * root = new TreeNode(preorder[0]);
        int i = 0;
        stack<TreeNode *> st;
        st.push(root);
        i++;
        while(i < preorder.size() && !st.empty())
        {
            TreeNode * newNode = new TreeNode(preorder[i]);
            if(preorder[i] < st.top()->val)
            {
                st.top()->left = newNode;
                st.push(newNode);
                i++;
            }
            else
            {   
                TreeNode * curr = nullptr;
                while(!st.empty() && st.top()->val < preorder[i])
                {
                    curr = st.top();
                    st.pop();
                }
             
                curr->right = newNode;
                st.push(newNode);
                i++;
            }
        }
        return root;
    }
};
