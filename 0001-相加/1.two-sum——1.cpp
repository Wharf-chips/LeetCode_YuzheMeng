/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
using namespace std;
#include<vector>
#include <algorithm>

struct P{
    int t1;
    int index;
};

bool compare(P &t1, P &t2){
    return t1.t1 < t2.t1;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2,1);
        P *p = new P[nums.size()];

        for(int i=0;i<nums.size();i++){
            p[i].t1 = nums[i];
            p[i].index = i;
        }

        sort(p, p+nums.size(), compare);

        int index1=0,index2=nums.size()-1;

        for(int i=0; i<nums.size(); i++){
            if(p[index1].t1+p[index2].t1 > target) index2--;
            else if(p[index1].t1+p[index2].t1 < target) index1++;
            else break;
        }

        result[0]=p[index1].index;
        result[1]=p[index2].index;

        return result;
    }
};
// @lc code=end

//解法思路:先排序数组，再利用双指针一个头一个尾寻找目标值。重点在于
//排序的时候要记录原位置，因此重新创建了一个结构体，这里可能有更好的方法
//时间效率上超越了97.55%的程序，时间复杂度为nlogn+n,主要取决于排序算法

