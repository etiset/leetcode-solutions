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
    int getHeight(TreeNode* root, bool& res){
        if(root == nullptr || !res){
            return 0;
        }

        int lh = getHeight(root -> left, res);
        int rh = getHeight(root -> right, res);

        if(abs(lh - rh) > 1){
            res = false;
        }

        return 1 + max(lh, rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool res = true;

        getHeight(root, res);

        return res;
    }
};