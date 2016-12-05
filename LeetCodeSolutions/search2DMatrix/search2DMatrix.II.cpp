// Source : https://leetcode.com/problems/search-a-2d-matrix-ii/
// Author : Hao Chen
// Date   : 2015-08-15

/********************************************************************************** 
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. This 
 * matrix has the following properties:
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   4,  7, 11, 15],
 *   [2,   5,  8, 12, 19],
 *   [3,   6,  9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * 
 * Given target = 5, return true.
 * Given target = 20, return false.
 *               
 *               
 * 
 *               
 **********************************************************************************/

// 139 ms
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
	    if (row == 0 || col == 0) return false;
	    int i = 0, j = col - 1;
	    while (i < row&&j >= 0) {
		    if (target > matrix[i][j]) i++;
		    else if (target < matrix[i][j]) j--;
		    else return true;
	    }
	    return false;
    }
};