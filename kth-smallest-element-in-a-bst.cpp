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
    optional<int> traverseTree(TreeNode* root, int& rem){
        if(root -> left != nullptr){
            auto lres = traverseTree(root -> left, rem);

            if(lres.has_value()){
                return lres;
            }
        }

        rem--;

        if(rem == 0){
            return root -> val;
        }

        if(root -> right != nullptr){
            auto rres = traverseTree(root -> right, rem);

            if(rres.has_value()){
                return rres;
            }
        }

        return nullopt;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        return *traverseTree(root, k);
    }
};