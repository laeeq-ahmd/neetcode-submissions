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
    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> &mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inord = mp[root->val];
        int leftNums = inord-inStart;
        root->left = buildTree(preorder, preStart+1, preStart+leftNums, inorder, inStart, inord-1, mp);
        root->right = buildTree(preorder, preStart+leftNums+1,preEnd , inorder, inord+1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        int n = preorder.size();
        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return buildTree(preorder, 0, n-1, inorder, 0, n-1, mp); 
    }
};
