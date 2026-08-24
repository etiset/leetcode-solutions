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
    bool isSameTree(TreeNode* u, TreeNode* v){
        if(u == nullptr || v == nullptr){
            return (u == v);
        }

        if(u -> val != v -> val){
            return false;
        }

        if(!isSameTree(u -> left, v -> left)){
            return false;
        }

        if(!isSameTree(u -> right, v -> right)){
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