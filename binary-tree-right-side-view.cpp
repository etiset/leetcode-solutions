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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<int> res = {};

        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            int rem = qu.size();
            int to_add = qu.front() -> val;

            while(rem--){
                auto it = qu.front();
                qu.pop();

                to_add = it -> val;

                if(it -> left){
                    qu.push(it -> left);
                }
                
                if(it -> right){
                    qu.push(it -> right);
                }
            }

            res.push_back(to_add);
        }

        return res;
    }
};