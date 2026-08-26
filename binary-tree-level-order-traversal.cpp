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
            auto it = qu.front();
            qu.pop();

            if(it == nullptr){
                if(!qu.empty()){
                    res.push_back({});
                    qu.push(nullptr);
                }

                continue;
            }

            res.back().push_back(it -> val);

            if(it -> left != nullptr){
                qu.push(it -> left);
            }

            if(it -> right != nullptr){
                qu.push(it -> right);
            }
        }

        return res;
    }
};