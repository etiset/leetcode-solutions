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
            auto fr = qu.front();
            qu.pop();

            if(fr == nullptr){
                if(!qu.empty()){
                    res.push_back({});
                    qu.push(nullptr);
                }

                continue;
            }

            res.back().push_back(fr -> val);

            if(fr -> left != nullptr){
                qu.push(fr -> left);
            }

            if(fr -> right != nullptr){
                qu.push(fr -> right);
            }
        }

        return res;
    }
};