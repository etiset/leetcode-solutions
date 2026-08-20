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
    int dfs(TreeNode* root, int curr_max){
        if(root == NULL){
            return 0;
        }

        int res = 0;

        if(root -> val >= curr_max){
            res++;
            curr_max = root -> val;
        }

        res += dfs(root -> left, curr_max) + dfs(root -> right, curr_max);

        return res;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};