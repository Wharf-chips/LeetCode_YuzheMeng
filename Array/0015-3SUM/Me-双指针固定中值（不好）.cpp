/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
using namespace std;
#include <vector>
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        int mid = 0;
        int left = 0;
        int right = nums.size() - 1;

        for(;mid<nums.size();mid++,left = 0,right = nums.size() - 1){//错误点1，没有重新初始化
            if(mid+1<nums.size()&&nums[mid]==nums[mid+1]&&mid!=1){
                if(mid+2<nums.size()&&nums[mid]==0&&nums[mid+1]==0&&nums[mid+2]==0){
                    vector<int> temp = {0,0,0};
                    result.push_back(temp);
                    continue;
                }
                continue;
            }

            while(left<mid&&right>mid){
                if(left-1>0&&nums[left]==nums[left-1]){
                    left++;
                    continue;
                }
                else if(right+1<nums.size()&&nums[right]==nums[right+1]){
                    right--;
                    continue;
                }
                if(nums[left]+nums[right]==-(nums[mid])){
                    vector<int> temp = {nums[left],nums[mid],nums[right]};
                    result.push_back(temp);
                    left++;
                }
                else if(nums[left]+nums[right]>-(nums[mid])){
                    right--;
                }
                else{
                    left++;
                }
            }

        }

        return result;
    }
};
// @lc code=end

//我的思路，复杂度为 O(n^2*logn)，先排序，选取一个数作为中间的数开始遍历数组，
//对于每一个选取的中间数，从两边使用双指针来寻找符合题意的数，并且需要维护一个集合set
//这个集合的复杂度为longn

//第二次思考：不需要特别维护一个set，中间值，左右指针遇到相同的直接跳过即可，
//除去000的情况。

//固定中间值的方法不如固定最左值，例如[1,1,-2]就会WA




