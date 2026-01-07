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
    static const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProductAns = 0;

    
    long long totalSumDFS(TreeNode* root) {
        if (!root) return 0;
        return root->val + totalSumDFS(root->left) + totalSumDFS(root->right);
    }

   
    long long productDFS(TreeNode* root) {
        if (!root) return 0;

        long long left = productDFS(root->left);
        long long right = productDFS(root->right);

        long long subtreeSum = root->val + left + right;

        long long product = subtreeSum * (totalSum - subtreeSum);
        maxProductAns = max(maxProductAns, product);

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = totalSumDFS(root);   
        productDFS(root);               
        return maxProductAns % MOD;   
    }
};
