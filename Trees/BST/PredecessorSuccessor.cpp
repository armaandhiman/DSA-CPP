class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
       
       Node* succ = nullptr;
      Node * pre = nullptr;

      while(root)
        {
          if(root->data < key)
          {
            pre = root;
            root = root->right;
          }

          else if(root->data > key)
          {
            succ = root;
            root = root->left;
          }

          else 
          {
            if(root->right){
              Node* curr = root->right;
              while(curr->left)
                curr = curr->left;
              succ = curr;
             }
            if(root->left)
            {
              Node * curr = root->left;
              while(curr->right)
                curr = curr->right;
              pre = curr;
            }
            break;
          }
        }
      return {pre , succ};
    
    }
};
