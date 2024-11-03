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
        vector<int> res;

        if(root == NULL){
            return res;
        }
        
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()){
            res.push_back(qu.front() -> val);

            int upto = qu.size();

            for(int i = 0; i < upto; i++){
                TreeNode* it = qu.front();
                qu.pop();

                if(it -> right){
                    qu.push(it -> right);
                }

                if(it -> left){
                    qu.push(it -> left);
                }
            }
        }

        return res;
    }
};