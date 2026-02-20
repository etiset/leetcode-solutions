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
    bool isSameTree(TreeNode* a, TreeNode* b){
        if(a == nullptr || b == nullptr){
            return (a == b);
        }

        if(a -> val != b -> val){
            return false;
        }

        if(!isSameTree(a -> left, b -> left)){
            return false;
        }

        if(!isSameTree(a -> right, b -> right)){
            return false;
        }

        return true;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }

        if(isSameTree(root, subRoot)){
            return true;
        }
        
        if(isSubtree(root -> left, subRoot)){
            return true;
        }

        if(isSubtree(root -> right, subRoot)){
            return true;
        }

        return false;
    }
};