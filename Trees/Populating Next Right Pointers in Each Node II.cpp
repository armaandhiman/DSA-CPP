/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
       Node * dumm = new Node(-1);
       Node * curr = root;
       while(curr)
       {
        Node * temp = dumm;
        while(curr)
        {
           if(curr->left)
           {
            temp->next = curr->left;
            temp = temp->next;
           } 
           if(curr->right)
           {
            temp->next = curr->right;
            temp = temp->next;
           }
           curr = curr->next;
        }
        curr = dumm->next;
        dumm->next = nullptr;
       }

       return root;
    }
};
