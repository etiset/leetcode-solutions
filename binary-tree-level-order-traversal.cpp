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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> res = {{}};
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(nullptr);

        while(!qu.empty()){
            TreeNode* fr = qu.front();
            qu.pop();

            if(fr){
                res.back().push_back(fr -> val);

                if(fr -> left){
                    qu.push(fr -> left);
                }

                if(fr -> right){
                    qu.push(fr -> right);
                }
            }

            else{
                if(!qu.empty()){
                    qu.push(nullptr);
                    res.push_back({});
                }
            }
        }

        return res;
    }
};