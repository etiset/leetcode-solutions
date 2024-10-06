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
    bool treesMatch(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL){
            return true;
        }

        if(a == NULL && b != NULL){
            return false;
        }

        if(b == NULL && a != NULL){
            return false;
        }

        if(a -> val != b -> val){
            return false;
        }

        bool left_matches = treesMatch(a -> left, b -> left);
        bool right_matches = treesMatch(a -> right, b -> right);
        bool tree_matches = left_matches && right_matches;

        return left_matches && right_matches;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool res = treesMatch(root, subRoot);

        if(root -> left != NULL){
            res = res || isSubtree(root -> left, subRoot);
        }

        if(root -> right != NULL){
            res = res || isSubtree(root -> right, subRoot);
        }

        return res;
    }
};