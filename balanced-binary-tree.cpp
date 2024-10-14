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
    pair<bool, int> checkBalancedAndHeight(TreeNode* root){
        if(root == NULL){
            return make_pair(true, 0);
        }

        auto left_info = checkBalancedAndHeight(root -> left);
        auto right_info = checkBalancedAndHeight(root -> right);

        bool is_balanced = left_info.first && right_info.first;

        if(abs(left_info.second - right_info.second) > 1){
            is_balanced = false;
        }

        int ht = max(left_info.second, right_info.second);

        return make_pair(is_balanced, ht + 1);
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkBalancedAndHeight(root).first;
    }
};