class Solution {
public:

       TreeNode * A = nullptr;
       TreeNode * B = nullptr;
       TreeNode * prev = nullptr;

       void inorder(TreeNode * root)
       {
        if(root == nullptr)
        return ;

        inorder(root->left);
        if(prev && prev->val > root->val)
        {
            if(!A)
            A = prev;
            B = root;
        }
        prev = root;
        inorder(root->right);
       }
    
    void recoverTree(TreeNode* root) {
       inorder(root);
       swap(A->val , B->val);
    }
};
