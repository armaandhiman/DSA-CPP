class BSTIterator {
public:

    TreeNode * curr = nullptr;
    BSTIterator(TreeNode* root) {
        
        curr = root;
    }
    
    int next() {
        
        while(curr)
        {
            if(!curr->left)
            {
                int ans = curr->val ;
                curr = curr->right;
                return ans;
            }

            else 
            {
                TreeNode * prev = curr->left;
                while(prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if(prev->right == nullptr)
                {
                prev->right = curr;
                curr= curr->left;
                }
                else
                {
                     int ans = curr->val;
                     prev->right = nullptr;
                    curr = curr->right;
                     return ans ;

                }
            }
        }
          return -1;
    }
    
    bool hasNext() {
        
    if(curr)
    return true;
    else
    return false;
    }
};
