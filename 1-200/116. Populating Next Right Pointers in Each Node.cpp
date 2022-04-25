class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        
        Node* leftMost = root;
        
        while(leftMost->left != nullptr) {
            
            Node* head = leftMost;
            
            while(head != nullptr) {
                head->left->next = head->right;
                if(head->next) {
                    head->right->next = head->next->left;
                }
                
                head = head->next;
            }
            
            leftMost = leftMost->left;
        }
        
        
        
    
        
        return root;
    }
};
