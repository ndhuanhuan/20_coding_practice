class Solution {
	// Basic inorder traversal which counts alphabet
    void check(unordered_map<char, int> &umap, Node* root){
        
        if(root->val != '+'){
            umap[root->val]++;
            return;
        }
        
        check(umap, root->left);
        check(umap, root->right);
    }
public:
    bool checkEquivalence(Node* root1, Node* root2) {
        
        unordered_map<char, int> umap1, umap2;
        check(umap1, root1);
        check(umap2, root2);
        
		return umap1 == umap2;
    }
};
