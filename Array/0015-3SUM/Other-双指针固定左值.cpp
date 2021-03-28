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
sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if( i==0 || (i > 0 & nums[i] != nums[i-1]) ){
                int low = i+1; int high = nums.size()-1;
                int sum = - nums[i];
                if (sum < 0) break;
                while(low < high){
                    if( (nums[low]+nums[high]) == sum){
                        res.push_back(vector<int>({nums[i], nums[low], nums[high]}));
                        while( low < high && nums[low] == nums[low+1] ) low++;
                        while( low < high && nums[high] == nums[high-1] ) high--;
                        low++; high--;                        
                    }else if(nums[low]+nums[high] < sum) low++;
                    else high--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

//我的思路，复杂度为 O(n^2*logn)，先排序，选取一个数作为中间的数开始遍历数组，
//对于每一个选取的中间数，从两边使用双指针来寻找符合题意的数，并且需要维护一个集合set
//这个集合的复杂度为longn

//第二次思考：不需要特别维护一个set，中间值，左右指针遇到相同的直接跳过即可，
//除去000的情况。

//固定中间值的方法不如固定最左值，例如[1,1,-2]就会WA

//第三次思考，举例子没举完全，固定中间值的方法弱于固定左值的方法，固定左值时
//左值增加保证搜索空间不重叠，进行跳过前，已经搜索过更大的右边区域，跳过的是其的子集，不会出问题
//中值增加也能保证搜索空间不重叠，但进行掉过时，左右区域搜索空间此消彼长，容易出现问题




