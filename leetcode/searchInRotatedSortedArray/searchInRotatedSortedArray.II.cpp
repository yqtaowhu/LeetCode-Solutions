// Date   : 2016.09.16
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
* 
* Would this affect the run-time complexity? How and why?
* 
* Write a function to determine if a given target is in the array.
*               
**********************************************************************************/
//reference:https://discuss.leetcode.com/topic/16660/my-8ms-c-solution-o-logn-on-average-o-n-worst-case
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right =  nums.size()-1, mid;
        while(left<=right) {
            mid = (left + right) >> 1;
            if(nums[mid] == target) return true;
            // the only difference from the first one, trickly case, just updat left and right
            if( (nums[left] == nums[mid]) && (nums[right] == nums[mid]) ) {++left; --right;}
            else if(nums[left] <= nums[mid]) {
                if( (nums[left]<=target) && (nums[mid] > target) ) right = mid-1;
                else left = mid + 1; 
            }
            else {
                if((nums[mid] < target) &&  (nums[right] >= target) ) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};
