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
    bool checkTree(TreeNode* root, optional<int>& minn){
        if(root == NULL){
            return true;
        }

        if(!checkTree(root -> left, minn)){
            return false;
        }

        if(minn.has_value() && *minn >= root -> val){
            return false;
        }

        minn = root -> val;

        if(!checkTree(root -> right, minn)){
            return false;
        }

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        optional<int> minn;

        return checkTree(root, minn);
    }
};