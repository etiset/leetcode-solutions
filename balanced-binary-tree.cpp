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
    optional<int> checkHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        auto lh = checkHeight(root -> left);
        auto rh = checkHeight(root -> right);

        if(lh.has_value() && rh.has_value() && abs(*lh - *rh) <= 1){
            return 1 + max(*lh, *rh);
        }

        return nullopt;
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root).has_value();
    }
};