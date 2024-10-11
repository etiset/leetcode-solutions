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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        if(preorder.size() == 1){
            return root;
        }

        int pid = 1;
        int iid = 0;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            while(st.top() -> val != inorder[iid]){
                TreeNode* curr = new TreeNode(preorder[pid++]);

                st.top() -> left = curr;
                st.push(curr);
            }

            TreeNode* curr = NULL;

            while(!st.empty() && st.top() -> val == inorder[iid]){
                curr = st.top();
                st.pop();

                iid++;
            }

            if(pid < preorder.size()){
                TreeNode* r_node = new TreeNode(preorder[pid++]);

                curr -> right = r_node;
                st.push(r_node);
            }
        }

        return root;
    }
};