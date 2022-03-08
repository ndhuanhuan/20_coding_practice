// https://leetcode.com/problems/create-binary-tree-from-descriptions/discuss/1823606/C%2B%2B-Hash-Map-O(N)-Time
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& A) {
        unordered_map<TreeNode*, TreeNode*> parentMap; // map from child node pointer to parent node pointer
        unordered_map<int, TreeNode*> m; // map from node value to node pointer
        for (auto &v : A) {
            int p = v[0], c = v[1], isLeft = v[2];
            auto parent = m.count(p) ? m[p] : (m[p] = new TreeNode(p));
            auto child = m.count(c) ? m[c] : (m[c] = new TreeNode(c));
            if (isLeft) parent->left = child;
            else parent->right = child;
            parentMap[child] = parent;
        }
        auto root = m.begin()->second; // Pick a random node pointer and keep traversing up until the node doesn't have any parents
        while (parentMap.count(root)) root = parentMap[root];
        return root;
    }
};
