// Date   : 2016.07.23
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
* such that adding up all the values along the path equals the given sum.
* 
* For example:
* Given the below binary tree and sum = 22,
* 
*               5
*              / \
*             4   8
*            /   / \
*           11  13  4
*          /  \      \
*         7    2      1
* 
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*               
**********************************************************************************/

#include <time.h>

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //迭代
class Solution {
public:
     bool hasPathSum(TreeNode *root, int sum) {
        if (root==NULL) return false;
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0){
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left==NULL && node->right==NULL){
                if (node->val == sum){
                    return true;
                }
            }
            if (node->left){
                node->left->val += node->val;
                v.push_back(node->left);
            }
            if (node->right){
                node->right->val += node->val;
                v.push_back(node->right);
            }
        }
        return false;
        
    }
};
//递归
bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }