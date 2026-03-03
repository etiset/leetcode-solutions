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
    bool validateTree(TreeNode* root, optional<int>& minn){
        if(root == nullptr){
            return true;
        }

        if(!validateTree(root -> left, minn)){
            return false;
        }

        if(minn.has_value() && *minn >= root -> val){
            return false;
        }
        
        minn = root -> val;

        return validateTree(root -> right, minn);
    }

public:
    bool isValidBST(TreeNode* root) {
        optional<int> minn;

        return validateTree(root, minn);
    }
};