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
    bool traverseTree(TreeNode* root, optional<int>& curr_min){
        if(root == nullptr){
            return true;
        }

        if(root -> left != nullptr && !traverseTree(root -> left, curr_min)){
            return false;
        }

        if(curr_min.has_value() && root -> val <= curr_min.value()){
            return false;
        }

        curr_min = root -> val;

        if(root -> right != nullptr && !traverseTree(root -> right, curr_min)){
            return false;
        }

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        optional<int> curr_min;

        return traverseTree(root, curr_min);
    }
};