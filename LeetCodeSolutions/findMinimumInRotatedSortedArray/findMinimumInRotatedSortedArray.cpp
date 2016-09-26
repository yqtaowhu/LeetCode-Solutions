// Date   : 2016.09.26
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* Find the minimum element.
* 
* You may assume no duplicate exists in the array.
*               
**********************************************************************************/
//binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high) {
            int mid=(low+high)>>1;
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid;
        }
        return nums[low];
    }
};