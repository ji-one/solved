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

/**
 * A valid BST is defined as follows:
 *  The left subtree of a node contains only nodes with keys less than the node's key.
 *  The right subtree of a node contains only nodes with keys greater than the node's key.
 *  Both the left and right subtrees must also be binary search trees.
*/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, false, false, 0, 0);
    }
    
    bool isValidBST(TreeNode* node, bool lowerBoundExist, bool upperBoundExist, int lowerBound, int upperBound){
        if(node == NULL)
            return true;
        
        if(lowerBoundExist && node->val <= lowerBound)
            return false;
        
        if(upperBoundExist && node->val >= upperBound)
            return false;
        
        return isValidBST(node->left, lowerBoundExist, true, lowerBound, node->val) && 
            isValidBST(node->right, true, upperBoundExist, node->val, upperBound);
    }
};