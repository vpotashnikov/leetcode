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
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> rt;
        rt.push(root);
        int ans = 0;
        while (rt.size()) {
            root = rt.front(); rt.pop();
            if (low <= root->val && root->val <= high) ans += root->val;
            if (root->left != NULL) rt.push(root->left);
            if (root->right != NULL) rt.push(root->right);
        }
        return ans;
    }
};
