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
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL){
            return make_pair(0, 0);
        }

        auto lres = dfs(root -> left);
        auto rres = dfs(root -> right);

        int cand_diam = lres.second + rres.second;

        int diam = max(cand_diam, max(lres.first, rres.first));
        int height = 1 + max(lres.second, rres.second);

        return make_pair(diam, height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).first;
    }
};