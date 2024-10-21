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
    int findSolution(TreeNode* root, int& res){
        if(root == NULL){
            return 0;
        }

        int val = root -> val;
        int lres = findSolution(root -> left, res);
        int rres = findSolution(root -> right, res);

        int rooted_sol = val + max(0, lres) + max(0, rres);
        res = max(res, rooted_sol);

        int upstream_sol = val + max(0, max(lres, rres));

        return upstream_sol;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = root -> val;

        findSolution(root, res);

        return res;
    }
};