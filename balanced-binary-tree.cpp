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
    optional<int> getHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        auto lh = getHeight(root -> left);
        auto rh = getHeight(root -> right);

        if(!lh.has_value() || !rh.has_value()){
            return nullopt;
        }

        if(abs(*lh - *rh) > 1){
            return nullopt;
        }

        return 1 + max(*lh, *rh);
    }

public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root).has_value();
    }
};