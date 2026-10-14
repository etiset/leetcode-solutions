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
    int traverseTree(TreeNode* root, int maxValue){
        if(root == nullptr){
            return 0;
        }

        int res = (root -> val >= maxValue);

        maxValue = max(maxValue, root -> val);
        res += traverseTree(root -> left, maxValue);
        res += traverseTree(root -> right, maxValue);

        return res;
    }

public:
    int goodNodes(TreeNode* root) {
        return traverseTree(root, INT_MIN);
    }
};