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
    int findSolution(TreeNode* root, int &res){
        if(root == nullptr){
            return 0;
        }

        int val = root -> val;
        int lval = findSolution(root -> left, res);
        int rval = findSolution(root -> right, res);
        res = max(res, val + lval + rval);

        int pval = val + max(0, max(lval, rval));
        res = max(res, pval);

        return pval;
    }

public:
    int maxPathSum(TreeNode* root) {
        int res = root -> val;
        findSolution(root, res);
        return res;
    }
};