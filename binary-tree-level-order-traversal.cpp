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
        vector<vector<int>> res;

        if(root == NULL){
            return res;
        }

        queue<pair<TreeNode*, int>> qu;
        qu.push(make_pair(root, 0));

        while(!qu.empty()){
            auto [curr, lev] = qu.front();
            qu.pop();

            if(res.size() == lev){
                res.push_back(vector<int>());
            }

            res[lev].push_back(curr -> val);

            if(curr -> left != NULL){
                qu.push(make_pair(curr -> left, lev + 1));
            }

            if(curr -> right != NULL){
                qu.push(make_pair(curr -> right, lev + 1));
            }
        }

        return res;
    }
};