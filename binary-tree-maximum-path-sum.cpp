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
private:
    int dfs(TreeNode* root, int& res){
        if(root == nullptr){
            return 0;
        }

        int o1 = max(0, dfs(root -> left, res));
        int o2 = max(0, dfs(root -> right, res));

        res = max(res, (root -> val) + o1 + o2);

        return (root -> val) + max(o1, o2);
    }

public:
    int maxPathSum(TreeNode* root) {
        int res = root -> val;

        dfs(root, res);

        return res;
    }
};