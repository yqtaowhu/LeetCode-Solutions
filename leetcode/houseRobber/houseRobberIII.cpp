// Date   : 2016.09.24
// Author : yqtao
// https://github.com/yqtaowhu


/*************************************************************************************** 
 *
 * The thief has found himself a new place for his thievery again. There is only one
 * entrance to this area, called the "root." Besides the root, each house has one and
 * only one parent house. After a tour, the smart thief realized that "all houses in
 * this place forms a binary tree". It will automatically contact the police if two 
 * directly-linked houses were broken into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight without alerting the
 * police.
 * 
 * Example 1:
 *     3
 *    / \
 *   2   3
 *    \   \ 
 *     3   1
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * Example 2:
 *     3
 *    / \
 *   4   5
 *  / \   \ 
 * 1   3   1
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 * Credits:
 * Special thanks to @dietpepsi for adding this problem and creating all test cases.
 * 
 ***************************************************************************************/
class Solution {
public:
    int rob(TreeNode* root) {
    vector<int> res = robSub(root);
    return max(res[0], res[1]);
}
  
vector<int> robSub(TreeNode* root) {
    if (root == NULL) {
        return vector<int>(2,0);
    }

    vector<int> left = robSub(root->left);
    vector<int> right = robSub(root->right);

    vector<int> res(2,0);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = root->val + left[0] + right[0];

    return res;
}
};
